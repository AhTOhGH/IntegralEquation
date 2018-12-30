#include <QtWidgets/QMainWindow>
#include "ui_IntegralEquation.h"
#include "kellog.h"
#include <QChart>
#include "qchartview.h"
#include <QLineSeries>
#include <QSplineSeries>

class IntegralEquation : public QMainWindow
{
	Q_OBJECT

public:
	IntegralEquation(QWidget *parent = Q_NULLPTR);

public slots:
	void calc();
	void reverce();
	void update(double);
	void update(int);

private:
	void drawGraphikZkr(QVector<double> vZkr, double dDeltaX);
	void drawGraphikZ2(QVector<QVector<double>> vZ2, double dDeltaX);

private:
	Ui::IntegralEquationClass ui;
	CKellog *m_pIntegral;
	QtCharts::QChart *m_pZkrChart;
	QtCharts::QChart *m_pZ2Chart;
};
