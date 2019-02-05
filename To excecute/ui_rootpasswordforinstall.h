/********************************************************************************
** Form generated from reading UI file 'rootpasswordforinstall.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ROOTPASSWORDFORINSTALL_H
#define UI_ROOTPASSWORDFORINSTALL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListWidget>

QT_BEGIN_NAMESPACE

class Ui_rootPasswordForInstall
{
public:
    QListWidget *listWidget;

    void setupUi(QDialog *rootPasswordForInstall)
    {
        if (rootPasswordForInstall->objectName().isEmpty())
            rootPasswordForInstall->setObjectName(QStringLiteral("rootPasswordForInstall"));
        rootPasswordForInstall->resize(400, 300);
        listWidget = new QListWidget(rootPasswordForInstall);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(0, 30, 401, 251));

        retranslateUi(rootPasswordForInstall);

        QMetaObject::connectSlotsByName(rootPasswordForInstall);
    } // setupUi

    void retranslateUi(QDialog *rootPasswordForInstall)
    {
        rootPasswordForInstall->setWindowTitle(QApplication::translate("rootPasswordForInstall", "Dialog", nullptr));

        const bool __sortingEnabled = listWidget->isSortingEnabled();
        listWidget->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = listWidget->item(0);
        ___qlistwidgetitem->setText(QApplication::translate("rootPasswordForInstall", "New Item", nullptr));
        QListWidgetItem *___qlistwidgetitem1 = listWidget->item(1);
        ___qlistwidgetitem1->setText(QApplication::translate("rootPasswordForInstall", "c", nullptr));
        QListWidgetItem *___qlistwidgetitem2 = listWidget->item(2);
        ___qlistwidgetitem2->setText(QApplication::translate("rootPasswordForInstall", "New Item", nullptr));
        listWidget->setSortingEnabled(__sortingEnabled);

    } // retranslateUi

};

namespace Ui {
    class rootPasswordForInstall: public Ui_rootPasswordForInstall {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ROOTPASSWORDFORINSTALL_H
