#include "kellog.h"

CKellog::CKellog(int nA_, int nB_, int nKolRazbieniy_, int nKolIterac_, double dTochnost_, EVariantCore var_)
{
	m_nA = nA_;
	m_nB = nB_;
	m_nKolRazbieniy = nKolRazbieniy_;
	m_nKolIterac = nKolIterac_;
	m_dTochnost = dTochnost_;
	m_dDeltaX = (m_nB - m_nA) / ((double)m_nKolRazbieniy);
	m_dLambda = 0;
	m_variantCore = var_;
}

CKellog::~CKellog()
{
}

double CKellog::Calculation()
{
	mY.clear();
	vNormi.clear();
	vMu.clear();
	mZ.clear();

	//	Заполним первую строчку матрицы Y единицами.
	mY.push_back(QVector<double>());
	for (size_t i = 0; i < m_nKolRazbieniy; i++)
	{
		mY[0].push_back(1);
	}

	//	Заполним остальные строки матрицы Y.
	for (size_t i = 1; i < m_nKolIterac; i++)
	{
		mY.push_back(QVector<double>());
		for (size_t j = 0; j < m_nKolRazbieniy; j++)
		{
			mY[i].push_back(calcmYij(j, mY[i - 1]));//посчитать 
		}
	}

	//	Для каждой строчки посчитать норму.
	vNormi.push_back(1);
	for (size_t i = 1; i < mY.size(); i++)
	{
		vNormi.push_back(norma(mY[i]));//расчёт норм для каждой строчки кроме первой
	}

	//	Посчитаем все мю.
	for (size_t i = 1; i < vNormi.size(); i++)
	{
		vMu.push_back(vNormi[i - 1] / vNormi[i]);
	}

	//	Найдём нужное мю.
	double dMu;
	for (size_t i = 1; i < vMu.size(); i++)
	{
		if (abs(vMu[i] - vMu[i - 1]) < m_dTochnost)
		{
			dMu = vMu[i];
		}
	}

	// Посчитаем матрицу Z
	for (size_t i = 0; i < mY.size(); i++)
	{
		mZ.push_back(QVector<double>());
		for (size_t j = 0; j < mY[0].size(); j++)
		{
			mZ[i].push_back(mY[i][j] / vNormi[i]);
		}
	}
	vZ1.clear();
	vZ2.clear();
	//	Найдём z с волной
	for (size_t i = 3; i < mZ.size(); i += 2)
	{
		double dMaxRazn = 0;
		for (size_t j = 0; j < mZ[0].size(); j++)
		{
			dMaxRazn = std::max(abs(mZ[i][j] - mZ[i - 2][j]), dMaxRazn);
		}
		if (dMaxRazn < m_dTochnost)
		{
			vZ1 = mZ[i];
			break;
		}
	}

	//	Найдём z с двумя волнами
	for (size_t i = 2; i < mZ.size(); i += 2)
	{
		double dMaxRazn = 0;
		for (size_t j = 0; j < mZ[0].size(); j++)
		{
			dMaxRazn = std::max(abs(mZ[i][j] - mZ[i - 2][j]), dMaxRazn);
		}
		if (dMaxRazn < m_dTochnost)
		{
			vZ2 = mZ[i];
			break;
		}
	}

	//	Найдём разность z с волной и z с двумя волнами
	double dRaznost = 0;
	for (size_t i = 0; i < vZ1.size(); i++)
	{
		dRaznost = std::max(vZ1[i] - vZ2[i], dRaznost);
	}

	m_vZkr.clear();
	if (dRaznost < m_dTochnost)
	{
		m_vZkr = vZ1;
		m_dLambda = dMu;
	}
	else
	{
		m_dLambda = -dMu;
		for (size_t i = 0; i < vZ2.size(); i++)
		{
			m_vZkr.push_back(vZ2[i] - vZ1[i]);
		}
	}

	return m_dLambda;
}

double CKellog::calcmYij(int dColumn, QVector<double> vY)
{
	double dSumm = 0;
	for (size_t i = 0; i < vY.size(); i++)
	{
		dSumm += core(dColumn, i)*vY[i];
	}
	return dSumm * m_dDeltaX;
}

double CKellog::core(int k, int i)
{
	switch (m_variantCore)
	{
	case EVariantCore::eAnton:
		if (!m_dLambda)
			return sqrt(pow(k*m_dDeltaX, 2) + pow(i*m_dDeltaX, 2));
		else
			return sqrt(pow(k*m_dDeltaX, 2) + pow(i*m_dDeltaX, 2)) - (m_vZkr[k] * m_vZkr[i]) / m_dLambda;
		break;
	case EVariantCore::eAlena:
		if (!m_dLambda)
			return log(1+(k*m_dDeltaX)*(i*m_dDeltaX));
		else
			return log(1 + (k*m_dDeltaX)*(i*m_dDeltaX)) - (m_vZkr[k] * m_vZkr[i]) / m_dLambda;
		break;
	default:
		break;
	}
	return 0;	
}

double CKellog::norma(QVector<double> vY)
{
	double dSumm = 0;
	for (size_t i = 0; i < vY.size(); i++)
	{
		dSumm += vY[i] * vY[i];
	}
	return sqrt(dSumm*m_dDeltaX);
}

