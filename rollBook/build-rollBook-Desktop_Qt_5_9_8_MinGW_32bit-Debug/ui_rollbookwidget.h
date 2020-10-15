/********************************************************************************
** Form generated from reading UI file 'rollbookwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ROLLBOOKWIDGET_H
#define UI_ROLLBOOKWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_rollBookWidget
{
public:

    void setupUi(QWidget *rollBookWidget)
    {
        if (rollBookWidget->objectName().isEmpty())
            rollBookWidget->setObjectName(QStringLiteral("rollBookWidget"));
        rollBookWidget->resize(400, 300);

        retranslateUi(rollBookWidget);

        QMetaObject::connectSlotsByName(rollBookWidget);
    } // setupUi

    void retranslateUi(QWidget *rollBookWidget)
    {
        rollBookWidget->setWindowTitle(QApplication::translate("rollBookWidget", "rollBookWidget", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class rollBookWidget: public Ui_rollBookWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ROLLBOOKWIDGET_H
