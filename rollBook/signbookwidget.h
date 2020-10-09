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
namespace Ui {
class signBookWidget;
}

class signBookWidget : public QWidget
{
    Q_OBJECT

public:
    explicit signBookWidget(QWidget *parent = nullptr);
    ~signBookWidget();

signals:
    void signedSignal();

private slots:
    void on_scrollArea_destroyed();

    void on_textBrowser_destroyed();

    void rebackButtonClicked();
    void showButtonClicked();
    void saveButtonClick();

private:
    Ui::signBookWidget *ui;

    void sendsigned();

    void paintEvent(QPaintEvent *);

    QLabel *signnameDisplayLabel;

    QPushButton *rebackButton;
    QPushButton *saveButton;
    QPushButton *showButton;

    QGridLayout *signLayout;

    QStringList strListImport;

    //控制窗口移动
    bool movewidget;
    QPoint m_startPoint;
    QPoint m_windowPoint;



};

#endif // SIGNBOOKWIDGET_H
