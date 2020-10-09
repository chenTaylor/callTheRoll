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
