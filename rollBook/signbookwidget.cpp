#include "signbookwidget.h"
#include "ui_signbookwidget.h"

signBookWidget::signBookWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::signBookWidget)
{
    this->setFixedSize(700,160);

    rebackButton = new QPushButton(tr("返回"));
    showButton = new QPushButton(tr("显示"));
    saveButton=new QPushButton(tr("记录"));
    //saveAbsentButton=new QPushButton(tr("缺课"));
    //创建格子布局
    signLayout = new QGridLayout(this);

    signnameDisplayLabel = new QLabel(); //新建QLabel
    signnameDisplayLabel->setFont(QFont("隶书", 20));

    connect(rebackButton,&QPushButton::clicked,this,&signBookWidget::sendsigned);
    connect(showButton,&QPushButton::clicked,this,&signBookWidget::showButtonClicked);
    connect(rebackButton,&QPushButton::clicked,this,&signBookWidget::rebackButtonClicked);
    connect(saveButton,&QPushButton::clicked,this,&signBookWidget::saveButtonClicked);
    //connect(saveAbsentButton,&QPushButton::clicked,this,&signBookWidget::saveAbsentButtonClicked);

    signLayout->addWidget(rebackButton, 0,7);
    signLayout->addWidget(showButton,1,6);
    signLayout->addWidget(saveButton, 2,7);
    //signLayout->addWidget(saveAbsentButton, 1,6);
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
/*
    saveAbsentButton->setStyleSheet(
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
*/

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
    QPixmap pixmap = QPixmap("D:/qt_user/field/sea.png").scaled(this->size());//nature、sea、ballon
    QPainter p(this);
    p.drawPixmap(this->rect(), pixmap);
}


void signBookWidget::showButtonClicked()
{
    ui->textEdit->document()->clear();
    QTextCodec *codec = QTextCodec::codecForName("UTF-8");        //此处使用UTF-8不行
    QTextCodec::setCodecForLocale(codec);
    QFile file("D:/qt_user/field/sign.txt");
    if (file.open(QIODevice::ReadOnly|QIODevice::Text))//以只读方式打开文本信息
    {
        QTextStream textStream(&file);
        while(!textStream.atEnd())
        {//一行一行的读取数据
            QString temp = textStream.readLine();

            if (!temp.isEmpty())//数据把不为空加入QStringList表中，且计数器加1
            {
                strListImport.append(temp);
            }
        }

    }
    //signnameDisplayLabel->setText(strListImport.join("\n"));
    //ui->scrollArea->widget()->setLayout(signLayout);
    //ui->scrollArea->setWidget(signnameDisplayLabel);
    //ui->textBrowser->setText(strListImport.join("\n"));
    ui->textEdit->insertPlainText(strListImport.join("\n"));
    file.close();


}

void signBookWidget::saveButtonClicked()
{

    QDateTime datetime;
    QString timestr=datetime.currentDateTime().toString("yyyyMMdd");
    QString fileName = "D:/qt_user/rollBook/list/" + timestr + ".txt";//假设指定文件夹路径为D盘根目录
    QFile file(fileName);
        if (!file.open(QFile::WriteOnly | QFile::Text))		//检测文件是否打开
        {
            QMessageBox::information(this, "Error Message", "Please Select a Text File!");
            return;
        }
        QTextStream out(&file);					//分行写入文件
        out << ui->textEdit->toPlainText();
   file.close();
}

/*void signBookWidget::saveAbsentButtonClicked()
{

    QDateTime datetime;
    QString timestr=datetime.currentDateTime().toString("yyyyMMdd")+"缺课名单";
    QString fileName = "D:/qt_user/rollBook/list/" + timestr + ".txt";//假设指定文件夹路径为D盘根目录
    QFile file(fileName);
        if (!file.open(QFile::WriteOnly | QFile::Text))		//检测文件是否打开
        {
            QMessageBox::information(this, "Error Message", "Please Select a Text File!");
            return;
        }
        QTextStream out(&file);					//分行写入文件
        out << ui->textEdit->toPlainText();
   file.close();
}*/

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

void signBookWidget::mousePressEvent(QMouseEvent *event)
{
    //当鼠标左键点击时
    if (event->button() == Qt::LeftButton)
    {
        movewidget = true;
        //记录鼠标的世界坐标
        m_startPoint = event->globalPos();
        //记录窗体的世界坐标
        m_windowPoint = this->frameGeometry().topLeft();
    }

}

void signBookWidget::mouseMoveEvent(QMouseEvent *event)
{
    if (event->buttons() & Qt::LeftButton)
    {
        //移动中的鼠标位置相对于初始位置的相对位置
        QPoint relativePos = event->globalPos() - m_startPoint;
        //然后移动窗体即可
        this->move(m_windowPoint + relativePos );
    }

}

void signBookWidget::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        //改变移动状态
        movewidget = false;
    }

}
//控制窗口移动}

void signBookWidget::enterEvent(QEvent *)
{
    QRect rc;
    QRect rect;
    rect = this->geometry();
    rc.setRect(rect.x(),rect.y(),rect.width(),rect.height());
    if(rect.top()<0)
    {
        rect.setX(rc.x());
        rect.setY(0);
        move(rc.x(),-2);
    }
}

void signBookWidget::leaveEvent(QEvent *)
{
    QRect rc;
    QRect rect;
    rect = this->geometry();
    rc.setRect(rect.x(),rect.y(),rect.width(),rect.height());
    if(rect.top()<0)
    {
        move(rc.x(),-rc.height()+2);
    }
}
