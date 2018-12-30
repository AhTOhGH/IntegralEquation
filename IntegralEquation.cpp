#include "IntegralEquation.h"

using namespace QtCharts;

IntegralEquation::IntegralEquation(QWidget *parent)
	: QMainWindow(parent),
	m_pIntegral(nullptr)
{
	ui.setupUi(this);
	m_pZkrChart = new QChart;
	m_pZkrChart->setTitle("Решение");
	m_pZkrChart->legend()->hide();
	m_pZ2Chart = new QChart;
	m_pZ2Chart->setTitle("Чётные строки приближений");
	m_pZ2Chart->legend()->hide();
	ui.grafikWidgetZ2->setRubberBand(QChartView::RectangleRubberBand);
	ui.grafikWidgetZkr->setRubberBand(QChartView::RectangleRubberBand);

	connect(ui.dsbTochnost, SIGNAL(valueChanged(double)), this, SLOT(update(double)));
	connect(ui.sbA, SIGNAL(valueChanged(int)), this, SLOT(update(int)));
	connect(ui.sbB, SIGNAL(valueChanged(int)), this, SLOT(update(int)));
	connect(ui.sbKolIterac, SIGNAL(valueChanged(int)), this, SLOT(update(int)));
	connect(ui.sbKolRazbieniy, SIGNAL(valueChanged(int)), this, SLOT(update(int)));
	connect(ui.cbCore, SIGNAL(currentIndexChanged(int)), this, SLOT(update(int)));

	calc();
}

void IntegralEquation::calc()
{
	if (m_pIntegral == nullptr)
	{
		int nA = ui.sbA->value();
		int nB = ui.sbB->value();
		int nKolRazbieniy = ui.sbKolRazbieniy->value();
		int nKolIterac = ui.sbKolIterac->value();
		double dTochnost = ui.dsbTochnost->value();
		EVariantCore var = ui.cbCore->currentText() == "sqrt(x^2+t^2)" ? EVariantCore::eAnton : EVariantCore::eAlena;
		m_pIntegral = new CKellog(nA, nB, nKolRazbieniy, nKolIterac, dTochnost, var);
	}

	double dLambda = m_pIntegral->Calculation();
	QVector<double> vMu = m_pIntegral->GetvMu();
	QVector<QVector<double>> mZ = m_pIntegral->GetmZ();
	QVector<double> vZkr = m_pIntegral->GetvZkr();
	double dDeltaX = m_pIntegral->GetDeltaX();

	ui.lblSobstvennoeChislo->setText("Собственное число №1 = " + QString::number(dLambda, 'g', 10));

	ui.twMu1->setRowCount(1);
	ui.twMu1->setColumnCount(vMu.size());
	QStringList lblMu;
	lblMu << "μ1";
	ui.twMu1->setVerticalHeaderLabels(lblMu);
	QTableWidgetItem *pItem = nullptr;
	for (size_t i = 0; i < vMu.size(); i++)
	{
		pItem = new QTableWidgetItem(QString::number(vMu[i], 'g', 10));
		ui.twMu1->setItem(0, i, pItem);
	}

	drawGraphikZkr(vZkr, dDeltaX);
	drawGraphikZ2(mZ, dDeltaX);

	dLambda = m_pIntegral->Calculation();
	vMu = m_pIntegral->GetvMu();
	mZ = m_pIntegral->GetmZ();
	vZkr = m_pIntegral->GetvZkr();
	dDeltaX = m_pIntegral->GetDeltaX();

	ui.lblSobstvennoeChislo_2->setText("Собственное число №2 = " + QString::number(dLambda, 'g', 10));

	ui.twMu2->setRowCount(1);
	ui.twMu2->setColumnCount(vMu.size());
	lblMu.clear();
	lblMu << "μ2";
	ui.twMu2->setVerticalHeaderLabels(lblMu);
	for (size_t i = 0; i < vMu.size(); i++)
	{
		pItem = new QTableWidgetItem(QString::number(vMu[i], 'g', 10));
		ui.twMu2->setItem(0, i, pItem);
	}

	drawGraphikZkr(vZkr, dDeltaX);
	drawGraphikZ2(mZ, dDeltaX);
}

void IntegralEquation::reverce()
{
	delete(m_pIntegral);
	m_pIntegral = nullptr;
	m_pZkrChart->removeAllSeries();
	m_pZ2Chart->removeAllSeries();
}

void IntegralEquation::update(int)
{
	reverce();
	calc();
}

void IntegralEquation::update(double)
{
	reverce();
	calc();
}

void IntegralEquation::drawGraphikZkr(QVector<double> vZkr, double dDeltaX)
{
	static int nNumber = 1;
	QSplineSeries *series = new QSplineSeries;

	for (size_t i = 0; i < vZkr.size(); i++)
	{
		series->append(i*dDeltaX, vZkr[i]);
	}

	series->setName("Z с крышкой" + QString::number(nNumber));
	m_pZkrChart->addSeries(series);
	nNumber++;

	m_pZkrChart->createDefaultAxes();
	m_pZkrChart->setAcceptHoverEvents(true);
	QChart::AnimationOptions options(QChart::AllAnimations);
	m_pZkrChart->setAnimationOptions(options);
	ui.grafikWidgetZkr->setChart(m_pZkrChart);
}

void IntegralEquation::drawGraphikZ2(QVector<QVector<double>> mZ, double dDeltaX)
{
	static int nNumber = 1;

	for (size_t i = 0; i < mZ.size(); i ++/*= 2)*/)
	{
		QSplineSeries *series = new QSplineSeries;
		for (size_t j = 0; j < mZ[0].size(); j++)
		{
			series->append(j*dDeltaX, mZ[i][j]);
		}
		series->setColor(QColor(nNumber % 2 == 0 ? "red" : "blue"));
		m_pZ2Chart->addSeries(series);
	}

	nNumber++;

	m_pZ2Chart->createDefaultAxes();
	m_pZ2Chart->setAcceptHoverEvents(true);
	QChart::AnimationOptions options(QChart::AllAnimations);
	m_pZ2Chart->setAnimationOptions(options);
	ui.grafikWidgetZ2->setChart(m_pZ2Chart);
}
