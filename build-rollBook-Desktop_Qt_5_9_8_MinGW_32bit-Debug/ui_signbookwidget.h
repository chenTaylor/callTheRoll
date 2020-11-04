/********************************************************************************
** Form generated from reading UI file 'signbookwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGNBOOKWIDGET_H
#define UI_SIGNBOOKWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_signBookWidget
{
public:
    QTextBrowser *textBrowser;
    QTextEdit *textEdit;

    void setupUi(QWidget *signBookWidget)
    {
        if (signBookWidget->objectName().isEmpty())
            signBookWidget->setObjectName(QStringLiteral("signBookWidget"));
        signBookWidget->resize(700, 160);
        textBrowser = new QTextBrowser(signBookWidget);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(10, 10, 461, 141));
        textEdit = new QTextEdit(signBookWidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(20, 20, 441, 121));

        retranslateUi(signBookWidget);

        QMetaObject::connectSlotsByName(signBookWidget);
    } // setupUi

    void retranslateUi(QWidget *signBookWidget)
    {
        signBookWidget->setWindowTitle(QApplication::translate("signBookWidget", "Form", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class signBookWidget: public Ui_signBookWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGNBOOKWIDGET_H
