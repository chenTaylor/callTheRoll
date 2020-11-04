#ifndef SIGNBOOKWIDGET_H
#define SIGNBOOKWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include <QLabel>
#include <QTimer>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>
#include <QDebug>
#include <QTime>
#include <QObject>
#include <QFont>
#include <QFontDatabase>
#include <QMutex>
#include <QApplication>
#include <QPainter>
#include <QPaintEvent>
#include <QTextCodec>
#include <QScrollArea>
#include <QTextEdit>
#include <QTextBrowser>
#include <QObject>
namespace Ui {
class signBookWidget;
}

class signBookWidget : public QWidget
{
    Q_OBJECT

public:
    explicit signBookWidget(QWidget *parent = nullptr);
    ~signBookWidget();

    void paintEvent(QPaintEvent *);

signals:
    void signedSignal();

private slots:
    void on_scrollArea_destroyed();

    void on_textBrowser_destroyed();

    void rebackButtonClicked();
    void showButtonClicked();
    void saveButtonClicked();
    //void saveAbsentButtonClicked();

private:
    Ui::signBookWidget *ui;

    void sendsigned();

    QLabel *signnameDisplayLabel;

    QPushButton *rebackButton;
    QPushButton *saveButton;
    QPushButton *showButton;
    //QPushButton *saveAbsentButton;

    QGridLayout *signLayout;

    QStringList strListImport;

    //控制窗口移动
    bool movewidget;
    QPoint m_startPoint;
    QPoint m_windowPoint;

protected:
    //控制窗口移动
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void enterEvent(QEvent *);
    void leaveEvent(QEvent *);


};

#endif // SIGNBOOKWIDGET_H
