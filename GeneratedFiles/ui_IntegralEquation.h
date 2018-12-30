/********************************************************************************
** Form generated from reading UI file 'IntegralEquation.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INTEGRALEQUATION_H
#define UI_INTEGRALEQUATION_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qchartview.h"

QT_BEGIN_NAMESPACE

class Ui_IntegralEquationClass
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_6;
    QSplitter *splitter;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_4;
    QtCharts::QChartView *grafikWidgetZkr;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_5;
    QtCharts::QChartView *grafikWidgetZ2;
    QHBoxLayout *horizontalLayout_2;
    QTableWidget *twMu1;
    QTableWidget *twMu2;
    QDockWidget *dockWidget;
    QWidget *dockWidgetContents;
    QVBoxLayout *verticalLayout_3;
    QComboBox *cbCore;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QVBoxLayout *verticalLayout;
    QSpinBox *sbA;
    QSpinBox *sbB;
    QSpinBox *sbKolRazbieniy;
    QSpinBox *sbKolIterac;
    QDoubleSpinBox *dsbTochnost;
    QLabel *lblSobstvennoeChislo;
    QLabel *lblSobstvennoeChislo_2;
    QSpacerItem *verticalSpacer;

    void setupUi(QMainWindow *IntegralEquationClass)
    {
        if (IntegralEquationClass->objectName().isEmpty())
            IntegralEquationClass->setObjectName(QStringLiteral("IntegralEquationClass"));
        IntegralEquationClass->resize(855, 460);
        QIcon icon;
        icon.addFile(QStringLiteral(":/IntegralEquation/Resources/integral-mathematical-sign.png"), QSize(), QIcon::Normal, QIcon::Off);
        IntegralEquationClass->setWindowIcon(icon);
        centralWidget = new QWidget(IntegralEquationClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout_6 = new QVBoxLayout(centralWidget);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        splitter = new QSplitter(centralWidget);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        layoutWidget = new QWidget(splitter);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        verticalLayout_4 = new QVBoxLayout(layoutWidget);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        grafikWidgetZkr = new QtCharts::QChartView(layoutWidget);
        grafikWidgetZkr->setObjectName(QStringLiteral("grafikWidgetZkr"));

        verticalLayout_4->addWidget(grafikWidgetZkr);

        splitter->addWidget(layoutWidget);
        layoutWidget1 = new QWidget(splitter);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        verticalLayout_5 = new QVBoxLayout(layoutWidget1);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        grafikWidgetZ2 = new QtCharts::QChartView(layoutWidget1);
        grafikWidgetZ2->setObjectName(QStringLiteral("grafikWidgetZ2"));

        verticalLayout_5->addWidget(grafikWidgetZ2);

        splitter->addWidget(layoutWidget1);

        verticalLayout_6->addWidget(splitter);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        twMu1 = new QTableWidget(centralWidget);
        twMu1->setObjectName(QStringLiteral("twMu1"));
        twMu1->setMaximumSize(QSize(16777215, 71));
        twMu1->verticalHeader()->setStretchLastSection(true);

        horizontalLayout_2->addWidget(twMu1);

        twMu2 = new QTableWidget(centralWidget);
        twMu2->setObjectName(QStringLiteral("twMu2"));
        twMu2->setMaximumSize(QSize(16777215, 71));
        twMu2->verticalHeader()->setStretchLastSection(true);

        horizontalLayout_2->addWidget(twMu2);


        verticalLayout_6->addLayout(horizontalLayout_2);

        IntegralEquationClass->setCentralWidget(centralWidget);
        dockWidget = new QDockWidget(IntegralEquationClass);
        dockWidget->setObjectName(QStringLiteral("dockWidget"));
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QStringLiteral("dockWidgetContents"));
        verticalLayout_3 = new QVBoxLayout(dockWidgetContents);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        cbCore = new QComboBox(dockWidgetContents);
        cbCore->addItem(QString());
        cbCore->addItem(QString());
        cbCore->setObjectName(QStringLiteral("cbCore"));

        verticalLayout_3->addWidget(cbCore);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label = new QLabel(dockWidgetContents);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout_2->addWidget(label);

        label_2 = new QLabel(dockWidgetContents);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout_2->addWidget(label_2);

        label_3 = new QLabel(dockWidgetContents);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout_2->addWidget(label_3);

        label_4 = new QLabel(dockWidgetContents);
        label_4->setObjectName(QStringLiteral("label_4"));

        verticalLayout_2->addWidget(label_4);

        label_5 = new QLabel(dockWidgetContents);
        label_5->setObjectName(QStringLiteral("label_5"));

        verticalLayout_2->addWidget(label_5);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        sbA = new QSpinBox(dockWidgetContents);
        sbA->setObjectName(QStringLiteral("sbA"));

        verticalLayout->addWidget(sbA);

        sbB = new QSpinBox(dockWidgetContents);
        sbB->setObjectName(QStringLiteral("sbB"));
        sbB->setValue(1);

        verticalLayout->addWidget(sbB);

        sbKolRazbieniy = new QSpinBox(dockWidgetContents);
        sbKolRazbieniy->setObjectName(QStringLiteral("sbKolRazbieniy"));
        sbKolRazbieniy->setMaximum(1000);
        sbKolRazbieniy->setValue(100);

        verticalLayout->addWidget(sbKolRazbieniy);

        sbKolIterac = new QSpinBox(dockWidgetContents);
        sbKolIterac->setObjectName(QStringLiteral("sbKolIterac"));
        sbKolIterac->setValue(11);

        verticalLayout->addWidget(sbKolIterac);

        dsbTochnost = new QDoubleSpinBox(dockWidgetContents);
        dsbTochnost->setObjectName(QStringLiteral("dsbTochnost"));
        dsbTochnost->setDecimals(6);
        dsbTochnost->setValue(0.0001);

        verticalLayout->addWidget(dsbTochnost);


        horizontalLayout->addLayout(verticalLayout);


        verticalLayout_3->addLayout(horizontalLayout);

        lblSobstvennoeChislo = new QLabel(dockWidgetContents);
        lblSobstvennoeChislo->setObjectName(QStringLiteral("lblSobstvennoeChislo"));
        lblSobstvennoeChislo->setMaximumSize(QSize(16777215, 13));
        lblSobstvennoeChislo->setStyleSheet(QStringLiteral("color: rgb(0, 0, 255);"));

        verticalLayout_3->addWidget(lblSobstvennoeChislo);

        lblSobstvennoeChislo_2 = new QLabel(dockWidgetContents);
        lblSobstvennoeChislo_2->setObjectName(QStringLiteral("lblSobstvennoeChislo_2"));
        lblSobstvennoeChislo_2->setMaximumSize(QSize(16777215, 13));
        lblSobstvennoeChislo_2->setStyleSheet(QStringLiteral("color: rgb(23, 156, 8);"));

        verticalLayout_3->addWidget(lblSobstvennoeChislo_2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);

        dockWidget->setWidget(dockWidgetContents);
        IntegralEquationClass->addDockWidget(static_cast<Qt::DockWidgetArea>(1), dockWidget);

        retranslateUi(IntegralEquationClass);

        QMetaObject::connectSlotsByName(IntegralEquationClass);
    } // setupUi

    void retranslateUi(QMainWindow *IntegralEquationClass)
    {
        IntegralEquationClass->setWindowTitle(QApplication::translate("IntegralEquationClass", "\320\222\321\213\321\207\320\270\321\201\320\273\320\265\320\275\320\270\320\265 \320\270\320\275\321\202\320\265\320\263\321\200\320\260\320\273\320\260 \320\274\320\265\321\202\320\276\320\264\320\276\320\274 \320\232\320\265\320\273\320\273\320\276\320\263\320\260", nullptr));
        dockWidget->setWindowTitle(QApplication::translate("IntegralEquationClass", "\320\224\320\260\320\275\320\275\321\213\320\265", nullptr));
        cbCore->setItemText(0, QApplication::translate("IntegralEquationClass", "sqrt(x^2+t^2)", nullptr));
        cbCore->setItemText(1, QApplication::translate("IntegralEquationClass", "ln(1+xt)", nullptr));

        label->setText(QApplication::translate("IntegralEquationClass", "a", nullptr));
        label_2->setText(QApplication::translate("IntegralEquationClass", "b", nullptr));
        label_3->setText(QApplication::translate("IntegralEquationClass", "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276 \321\200\320\260\320\267\320\261\320\270\320\265\320\275\320\270\320\271", nullptr));
        label_4->setText(QApplication::translate("IntegralEquationClass", "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276 \320\270\321\202\320\265\321\200\320\260\321\206\320\270\320\271", nullptr));
        label_5->setText(QApplication::translate("IntegralEquationClass", "\320\242\320\276\321\207\320\275\320\276\321\201\321\202\321\214", nullptr));
        lblSobstvennoeChislo->setText(QApplication::translate("IntegralEquationClass", "TextLabel", nullptr));
        lblSobstvennoeChislo_2->setText(QApplication::translate("IntegralEquationClass", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class IntegralEquationClass: public Ui_IntegralEquationClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INTEGRALEQUATION_H
