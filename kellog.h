#include <QVector>

//	Ядра
enum class EVariantCore
{
	eAnton,	//	Ядро Антона.
	eAlena	//	Ядро Алёны.
};

//	Класс вычисления интеграла методом Келлога.
class CKellog
{
public:
	CKellog(int nA_, int nB_, int nKolRazbieniy_, int nKolIterac_, double dTochnost_, EVariantCore var_);
	~CKellog();

	//	Функция расчёта. Возвращает собственное число.
	double Calculation();

	QVector<double> GetvMu() { return vMu; }
	QVector<double> GetvNormi() { return vNormi; }
	QVector<QVector<double>> GetmY() { return mY; }
	QVector<QVector<double>> GetmZ() { return mZ; }
	QVector<double> GetvZkr() { return m_vZkr; }
	double GetDeltaX() { return m_dDeltaX; }
	QVector<double> GetvZ2() { return vZ2; }

private:
	double calcmYij(int dColumn, QVector<double> vY);
	double core(int k, int i);
	double norma(QVector<double> vY);

private:
	EVariantCore m_variantCore;
	int m_nA;
	int m_nB;
	int m_nKolRazbieniy;
	int m_nKolIterac;
	double m_dTochnost;
	double m_dDeltaX;
	double m_dLambda;
	QVector<double> m_vZkr;

	QVector<double> vZ1;
	QVector<double> vZ2;
	QVector<double> vMu;
	QVector<double> vNormi;
	QVector<QVector<double>> mY;
	QVector<QVector<double>> mZ;
};
