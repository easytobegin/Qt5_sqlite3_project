/********************************************************************************
** Form generated from reading UI file 'management.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MANAGEMENT_H
#define UI_MANAGEMENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QTableWidget *tableWidget;
    QGroupBox *filterquerygroupBox;
    QComboBox *columncomboBox;
    QLabel *orderlabel;
    QLabel *label;
    QLineEdit *pricelineEdit;
    QRadioButton *increaseradioButton;
    QComboBox *andorcomboBox;
    QComboBox *columncomboBox2;
    QLabel *biglabel;
    QLabel *littlelabel;
    QRadioButton *descendradioButton;
    QLineEdit *biglineEdit;
    QPushButton *querypushButton;
    QLineEdit *textlineEdit;
    QGroupBox *operategroupBox;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *deletepushButton;
    QPushButton *addpushButton;
    QLineEdit *littlelineEdit;
    QSplitter *splitter;
    QGroupBox *tablegroupBox;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_2;
    QRadioButton *storageradioButton;
    QRadioButton *importRecordradioButton;
    QRadioButton *exportRecordradioButton;
    QPushButton *refreshStorageButton;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_4;
    QWidget *layoutWidget3;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *closepushButton;
    QPushButton *modifypushButton;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QStringLiteral("Form"));
        Form->resize(861, 533);
        Form->setStyleSheet(QStringLiteral("background-image: url(:/image/259453-14061G2132487.jpg);"));
        tableWidget = new QTableWidget(Form);
        if (tableWidget->columnCount() < 4)
            tableWidget->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(450, 20, 401, 271));
        filterquerygroupBox = new QGroupBox(Form);
        filterquerygroupBox->setObjectName(QStringLiteral("filterquerygroupBox"));
        filterquerygroupBox->setGeometry(QRect(90, 10, 241, 291));
        columncomboBox = new QComboBox(filterquerygroupBox);
        columncomboBox->setObjectName(QStringLiteral("columncomboBox"));
        columncomboBox->setGeometry(QRect(26, 20, 101, 25));
        orderlabel = new QLabel(filterquerygroupBox);
        orderlabel->setObjectName(QStringLiteral("orderlabel"));
        orderlabel->setGeometry(QRect(26, 150, 91, 21));
        label = new QLabel(filterquerygroupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(6, 50, 16, 16));
        pricelineEdit = new QLineEdit(filterquerygroupBox);
        pricelineEdit->setObjectName(QStringLiteral("pricelineEdit"));
        pricelineEdit->setGeometry(QRect(54, 120, 71, 21));
        increaseradioButton = new QRadioButton(filterquerygroupBox);
        increaseradioButton->setObjectName(QStringLiteral("increaseradioButton"));
        increaseradioButton->setEnabled(true);
        increaseradioButton->setGeometry(QRect(26, 207, 92, 23));
        andorcomboBox = new QComboBox(filterquerygroupBox);
        andorcomboBox->setObjectName(QStringLiteral("andorcomboBox"));
        andorcomboBox->setGeometry(QRect(26, 80, 101, 25));
        columncomboBox2 = new QComboBox(filterquerygroupBox);
        columncomboBox2->setObjectName(QStringLiteral("columncomboBox2"));
        columncomboBox2->setGeometry(QRect(26, 170, 101, 25));
        biglabel = new QLabel(filterquerygroupBox);
        biglabel->setObjectName(QStringLiteral("biglabel"));
        biglabel->setGeometry(QRect(129, 122, 16, 16));
        littlelabel = new QLabel(filterquerygroupBox);
        littlelabel->setObjectName(QStringLiteral("littlelabel"));
        littlelabel->setGeometry(QRect(20, 120, 16, 16));
        descendradioButton = new QRadioButton(filterquerygroupBox);
        descendradioButton->setObjectName(QStringLiteral("descendradioButton"));
        descendradioButton->setGeometry(QRect(26, 230, 92, 23));
        biglineEdit = new QLineEdit(filterquerygroupBox);
        biglineEdit->setObjectName(QStringLiteral("biglineEdit"));
        biglineEdit->setGeometry(QRect(140, 120, 61, 21));
        querypushButton = new QPushButton(filterquerygroupBox);
        querypushButton->setObjectName(QStringLiteral("querypushButton"));
        querypushButton->setGeometry(QRect(20, 260, 75, 27));
        textlineEdit = new QLineEdit(filterquerygroupBox);
        textlineEdit->setObjectName(QStringLiteral("textlineEdit"));
        textlineEdit->setGeometry(QRect(26, 50, 101, 23));
        operategroupBox = new QGroupBox(Form);
        operategroupBox->setObjectName(QStringLiteral("operategroupBox"));
        operategroupBox->setGeometry(QRect(560, 340, 202, 66));
        layoutWidget = new QWidget(operategroupBox);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(17, 25, 178, 32));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        deletepushButton = new QPushButton(layoutWidget);
        deletepushButton->setObjectName(QStringLiteral("deletepushButton"));

        horizontalLayout->addWidget(deletepushButton);

        addpushButton = new QPushButton(layoutWidget);
        addpushButton->setObjectName(QStringLiteral("addpushButton"));

        horizontalLayout->addWidget(addpushButton);

        littlelineEdit = new QLineEdit(Form);
        littlelineEdit->setObjectName(QStringLiteral("littlelineEdit"));
        littlelineEdit->setGeometry(QRect(30, 130, 61, 21));
        splitter = new QSplitter(Form);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setGeometry(QRect(30, 310, 521, 161));
        splitter->setOrientation(Qt::Horizontal);
        tablegroupBox = new QGroupBox(splitter);
        tablegroupBox->setObjectName(QStringLiteral("tablegroupBox"));
        layoutWidget1 = new QWidget(tablegroupBox);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 17, 254, 27));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        storageradioButton = new QRadioButton(layoutWidget1);
        storageradioButton->setObjectName(QStringLiteral("storageradioButton"));

        horizontalLayout_2->addWidget(storageradioButton);

        importRecordradioButton = new QRadioButton(layoutWidget1);
        importRecordradioButton->setObjectName(QStringLiteral("importRecordradioButton"));

        horizontalLayout_2->addWidget(importRecordradioButton);

        exportRecordradioButton = new QRadioButton(layoutWidget1);
        exportRecordradioButton->setObjectName(QStringLiteral("exportRecordradioButton"));

        horizontalLayout_2->addWidget(exportRecordradioButton);

        splitter->addWidget(tablegroupBox);
        refreshStorageButton = new QPushButton(splitter);
        refreshStorageButton->setObjectName(QStringLiteral("refreshStorageButton"));
        splitter->addWidget(refreshStorageButton);
        layoutWidget2 = new QWidget(Form);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(0, 0, 2, 2));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        layoutWidget3 = new QWidget(Form);
        layoutWidget3->setObjectName(QStringLiteral("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(580, 410, 178, 32));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget3);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        closepushButton = new QPushButton(layoutWidget3);
        closepushButton->setObjectName(QStringLiteral("closepushButton"));

        horizontalLayout_3->addWidget(closepushButton);

        modifypushButton = new QPushButton(layoutWidget3);
        modifypushButton->setObjectName(QStringLiteral("modifypushButton"));

        horizontalLayout_3->addWidget(modifypushButton);

        layoutWidget->raise();
        tableWidget->raise();
        filterquerygroupBox->raise();
        operategroupBox->raise();
        littlelineEdit->raise();
        splitter->raise();
        layoutWidget->raise();
        QWidget::setTabOrder(refreshStorageButton, tableWidget);

        retranslateUi(Form);
        QObject::connect(closepushButton, SIGNAL(clicked()), Form, SLOT(close()));

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QApplication::translate("Form", "Database Management System", 0));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("Form", "\345\255\246\345\217\267", 0));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("Form", "\345\247\223\345\220\215", 0));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("Form", "\347\217\255\347\272\247", 0));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("Form", "\345\200\237\351\230\205\345\206\214\346\225\260", 0));
        filterquerygroupBox->setTitle(QApplication::translate("Form", "\350\277\207\346\273\244\346\237\245\350\257\242:\343\200\200", 0));
        columncomboBox->clear();
        columncomboBox->insertItems(0, QStringList()
         << QApplication::translate("Form", "\345\255\246\345\217\267", 0)
         << QApplication::translate("Form", "\345\247\223\345\220\215", 0)
         << QApplication::translate("Form", "\347\217\255\347\272\247", 0)
        );
        orderlabel->setText(QApplication::translate("Form", "\346\240\271\346\215\256()\346\216\222\345\272\217:", 0));
        label->setText(QApplication::translate("Form", "=", 0));
        pricelineEdit->setText(QApplication::translate("Form", "\345\200\237\351\230\205\345\206\214\346\225\260", 0));
        increaseradioButton->setText(QApplication::translate("Form", "\345\215\207\345\272\217", 0));
        andorcomboBox->clear();
        andorcomboBox->insertItems(0, QStringList()
         << QApplication::translate("Form", "&&", 0)
         << QApplication::translate("Form", "||", 0)
        );
        columncomboBox2->clear();
        columncomboBox2->insertItems(0, QStringList()
         << QApplication::translate("Form", "\345\255\246\345\217\267", 0)
         << QApplication::translate("Form", "\345\247\223\345\220\215", 0)
         << QApplication::translate("Form", "\347\217\255\347\272\247", 0)
         << QApplication::translate("Form", "\345\200\237\351\230\205\345\206\214\346\225\260", 0)
        );
        biglabel->setText(QApplication::translate("Form", "<", 0));
        littlelabel->setText(QApplication::translate("Form", "<", 0));
        descendradioButton->setText(QApplication::translate("Form", "\351\231\215\345\272\217", 0));
        querypushButton->setText(QApplication::translate("Form", "\346\237\245\350\257\242", 0));
        operategroupBox->setTitle(QApplication::translate("Form", "\346\223\215\344\275\234:", 0));
        deletepushButton->setText(QApplication::translate("Form", "\345\210\240\351\231\244", 0));
        addpushButton->setText(QApplication::translate("Form", "\346\267\273\345\212\240", 0));
        tablegroupBox->setTitle(QApplication::translate("Form", "\350\241\250:", 0));
        storageradioButton->setText(QApplication::translate("Form", "\344\273\223\345\272\223", 0));
        importRecordradioButton->setText(QApplication::translate("Form", "\345\257\274\345\205\245\346\225\260\346\215\256", 0));
        exportRecordradioButton->setText(QApplication::translate("Form", "\345\257\274\345\207\272\346\225\260\346\215\256", 0));
        refreshStorageButton->setText(QApplication::translate("Form", "\345\210\267\346\226\260\344\273\223\345\272\223", 0));
        closepushButton->setText(QApplication::translate("Form", "\345\205\263\351\227\255", 0));
        modifypushButton->setText(QApplication::translate("Form", "\344\277\256\346\224\271", 0));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MANAGEMENT_H
