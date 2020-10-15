#include "signbookwidget.h"
#include "ui_signbookwidget.h"

signBookWidget::signBookWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::signBookWidget)
{
    this->setFixedSize(700,140);

    rebackButton = new QPushButton(tr("返回"));
    showButton = new QPushButton(tr("显示"));
    saveButton=new QPushButton(tr("保存"));
    //创建格子布局
    signLayout = new QGridLayout(this);

    signnameDisplayLabel = new QLabel(); //新建QLabel
    signnameDisplayLabel->setFont(QFont("隶书", 20));

    connect(rebackButton,&QPushButton::clicked,this,&signBookWidget::sendsigned);
    connect(showButton,&QPushButton::clicked,this,&signBookWidget::showButtonClicked);
    connect(rebackButton,&QPushButton::clicked,this,&signBookWidget::rebackButtonClicked);
    connect(saveButton,&QPushButton::clicked,this,&signBookWidget::saveButtonClick);


    signLayout->addWidget(rebackButton, 0,7);
    signLayout->addWidget(showButton,1,7);
    signLayout->addWidget(saveButton, 2,7);
    signLayout->addWidget(signnameDisplayLabel, 0,0,3,4);

    rebackButton->setStyleSheet(
                       //正常状态样式
                       "QPushButton"
                       "{"
                       "background-color:rgb(217,218,218);"    //背景色（也可以设置图片）
                       "border-width:10px;"                    //边框宽度像素
                       "border-color:rgb(126,192,238);"        //边框颜色

                       "font:bold 13px;"                       //字体，字体大小
                       "color:rgb(0,0,0);"                     //字体颜色
                       "padding:1px;"                          //填衬
                       "}"

                       //鼠标按下样式
                       "QPushButton:pressed"
                       "{"
                       "background-color:rgb(175,193,209);"
                       "border-color:rgba(135,206,255,30);"
                       "border-style:inset;"
                       "color:rgba(0,0,0,100);"
                       "}"

                       //鼠标悬停样式
                       "QPushButton:hover"
                       "{"
                       "background-color:rgb(175,193,209);"
                       "border-color:rgba(135,206,255,30);"
                       "color:rgba(0,0,0,200);"
                       "}"
                );

    showButton->setStyleSheet(
                       //正常状态样式
                       "QPushButton"
                       "{"
                       "background-color:rgb(175,193,209);"    //背景色（也可以设置图片）
                       "border-width:10px;"                    //边框宽度像素
                       "border-color:rgb(126,192,238);"        //边框颜色

                       "font:bold 13px;"                       //字体，字体大小
                       "color:rgb(0,0,0);"                     //字体颜色
                       "padding:1px;"                          //填衬
                       "}"

                       //鼠标按下样式
                       "QPushButton:pressed"
                       "{"
                       "background-color:rgb(217,218,218);"
                       "border-color:rgba(135,206,255,30);"
                       "border-style:inset;"
                       "color:rgba(0,0,0,100);"
                       "}"

                       //鼠标悬停样式
                       "QPushButton:hover"
                       "{"
                       "background-color:rgb(217,218,218);"
                       "border-color:rgba(135,206,255,30);"
                       "color:rgba(0,0,0,200);"
                       "}"
                );

    saveButton->setStyleSheet(
                       //正常状态样式
                       "QPushButton"
                       "{"
                       "background-color:rgb(175,193,209);"    //背景色（也可以设置图片）
                       "border-width:10px;"                    //边框宽度像素
                       "border-color:rgb(126,192,238);"        //边框颜色

                       "font:bold 13px;"                       //字体，字体大小
                       "color:rgb(0,0,0);"                     //字体颜色
                       "padding:1px;"                          //填衬
                       "}"

                       //鼠标按下样式
                       "QPushButton:pressed"
                       "{"
                       "background-color:rgb(217,218,218);"
                       "border-color:rgba(135,206,255,30);"
                       "border-style:inset;"
                       "color:rgba(0,0,0,100);"
                       "}"

                       //鼠标悬停样式
                       "QPushButton:hover"
                       "{"
                       "background-color:rgb(217,218,218);"
                       "border-color:rgba(135,206,255,30);"
                       "color:rgba(0,0,0,200);"
                       "}"
                );

    //不显示标题栏
    this->setWindowFlags(Qt::FramelessWindowHint|Qt::WindowStaysOnTopHint);

    ui->setupUi(this);
}

signBookWidget::~signBookWidget()
{
    delete ui;
}

void signBookWidget::sendsigned()
{
    emit signedSignal();
}

void signBookWidget::paintEvent(QPaintEvent *)
{

}


void signBookWidget::showButtonClicked()
{


}

void signBookWidget::saveButtonClick()
{

}

void signBookWidget::rebackButtonClicked()
{
    ui->textEdit->document()->clear();
    ui->textBrowser->document()->clear();
}


void signBookWidget::on_textBrowser_destroyed()
{

}

void signBookWidget::on_scrollArea_destroyed()
{

}
