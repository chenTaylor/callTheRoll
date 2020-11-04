#ifndef ROLLBOOKWIDGET_H
#define ROLLBOOKWIDGET_H

#include "signbookwidget.h"
#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include <QTimer>
#include <QFileDialog>
#include <QTextStream>
#include <QDataStream>
#include <QFile>
#include <QMessageBox>
#include <QDebug>
#include <QTime>
#include <QObject>
#include <QFont>
#include <QFontDatabase>
#include <QMutex>
#include <QLabel>
#include <QApplication>
#include <QPainter>
#include <QPaintEvent>
#include <QString>

namespace Ui {
class rollBookWidget;
}

class rollBookWidget : public QWidget
{
    Q_OBJECT

public:
    explicit rollBookWidget(QWidget *parent = nullptr);
    ~rollBookWidget();

private:
    Ui::rollBookWidget *ui;

    void importData();

    //子窗口
    void signS();
    void dealsign();

    void paintEvent(QPaintEvent *);

    QLabel *nameDisplayLabel;

    QPushButton *beginButton;   //开始/暂停按钮
    QPushButton *inputButton;   //导入按钮
    QPushButton *quitButton;    //退出按钮
    QPushButton *miniButton;    //最小化按钮
    QPushButton *markButton;    //标记按钮
    QPushButton *signedButton;    //转到标记名单按钮

    signBookWidget w;

    //控制输出和布局
    QGridLayout *mainLayout;
    QTimer *switchTime;
    QStringList strListImport;

    int count=0;
    bool switchButtonFlg = false;
    int test = 0;
    int a=0;

    //控制窗口移动
    bool movewidget;
    QPoint m_startPoint;
    QPoint m_windowPoint;

private slots:
    void inputButtonClicked();
    void beginButtonClicked();
    void markButtonClicked();
    void signedButtonClicked();
    void quitButtonClicked();

    void switchTimeOut();

protected:
    //控制窗口移动
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void enterEvent(QEvent *);
    void leaveEvent(QEvent *);

};

#endif // ROLLBOOKWIDGET_H
