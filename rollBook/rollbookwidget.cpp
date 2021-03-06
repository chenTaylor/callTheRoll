#include "rollbookwidget.h"
#include "ui_rollbookwidget.h"

rollBookWidget::rollBookWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::rollBookWidget)
{
    this->setWindowFlags(Qt::Window);
    this->setWindowTitle(tr("点名"));//设置窗口名
    this->setFixedSize(700,160);        //设置窗口固定大小

    QTime time = QTime::currentTime();  //获得当前时间
    qsrand(time.msec()+time.second()*10000);    //用时间初始化随机数种子

    mainLayout = new QGridLayout(this); //创建格子布局

    nameDisplayLabel = new QLabel(tr("点名")); //新建QLabel
    nameDisplayLabel->setAlignment(Qt::AlignCenter);//QLabel控件居中显示
    nameDisplayLabel->setFont(QFont("隶书", 40));

    //控制点名开始暂停
    beginButton = new QPushButton(tr("开始"));

    //控制名单导入
    inputButton= new QPushButton(tr("导入"));

    //控制窗口关闭
    quitButton = new QPushButton(tr("退出"));
    connect(quitButton,&QPushButton::clicked,this,&rollBookWidget::close);
    connect(quitButton,&QPushButton::clicked,this,&rollBookWidget::quitButtonClicked);

    //控制窗口最小化
    miniButton =new QPushButton(tr("最小化"));
    connect(miniButton,&QPushButton::clicked,this,&rollBookWidget::showMinimized);

    //标记学生
    markButton =new QPushButton(tr("标记"));

    //标记学生名单
    signedButton =new QPushButton(tr("名单"));

    switchTime = new QTimer;//新建一个定时器

    //添加nameDisplayLabel控件到mainlayout的第0行0列，并占1行2列
    mainLayout->addWidget(nameDisplayLabel, 0,2,1,4);

    //添加按钮到mainlayout的第几行几列
    mainLayout->addWidget(inputButton, 0,0);
    mainLayout->addWidget(beginButton, 1,0);
    mainLayout->addWidget(quitButton, 0,6);
    mainLayout->addWidget(miniButton, 1,6);

    this->connect(switchTime, SIGNAL(timeout()), this, SLOT(switchTimeOut()));
    this->connect(inputButton, SIGNAL(clicked()), this, SLOT(inputButtonClicked()));
    this->connect(beginButton, SIGNAL(clicked()), this, SLOT(beginButtonClicked()));

    inputButton->setStyleSheet(
                       //正常状态样式
                       "QPushButton"
                       "{"
                       "background-color:rgb(135,193,181);"//背景色（也可以设置图片）
                       "border-width:10px;"                    //边框宽度像素
                       "border-color:rgb(126,192,238);"    //边框颜色

                       "font:bold 20px;"                       //字体，字体大小
                       "color:rgb(0,0,0);"                //字体颜色
                       "padding:6px;"                          //填衬
                       "}"

                       //鼠标按下样式
                       "QPushButton:pressed"
                       "{"
                       "background-color:rgb(85,140,108);"
                       "border-color:rgba(135,206,255,30);"
                       "border-style:inset;"
                       "color:rgba(0,0,0,100);"
                       "}"

                       //鼠标悬停样式
                       "QPushButton:hover"
                       "{"
                       "background-color:rgb(85,140,108);"
                       "border-color:rgba(135,206,255,30);"
                       "color:rgba(0,0,0,200);"
                       "}"
                );

    beginButton->setStyleSheet(
                       //正常状态样式
                       "QPushButton"
                       "{"
                       "background-color:rgb(48,108,48);"//背景色（也可以设置图片）
                       "border-width:10px;"                    //边框宽度像素
                       "border-color:rgb(126,192,238);"    //边框颜色

                       "font:bold 20px;"                       //字体，字体大小
                       "color:rgb(0,0,0);"                //字体颜色
                       "padding:6px;"                          //填衬
                       "}"

                       //鼠标按下样式
                       "QPushButton:pressed"
                       "{"
                       "background-color:rgb(85,140,108);"
                       "border-color:rgba(135,206,255,30);"
                       "border-style:inset;"
                       "color:rgba(0,0,0,100);"
                       "}"

                       //鼠标悬停样式
                       "QPushButton:hover"
                       "{"
                       "background-color:rgb(85,140,108);"
                       "border-color:rgba(135,206,255,30);"
                       "color:rgba(0,0,0,200);"
                       "}"
                );

    quitButton->setStyleSheet(
                       //正常状态样式
                       "QPushButton"
                       "{"
                       "background-color:rgb(206,215,196);"//背景色（也可以设置图片）
                       "border-width:10px;"                    //边框宽度像素
                       "border-color:rgb(126,192,238);"    //边框颜色

                       "font:bold 20px;"                       //字体，字体大小
                       "color:rgb(0,0,0);"                //字体颜色
                       "padding:6px;"                          //填衬
                       "}"

                       //鼠标按下样式
                       "QPushButton:pressed"
                       "{"
                       "background-color:rgb(85,140,108);"
                       "border-color:rgba(135,206,255,30);"
                       "border-style:inset;"
                       "color:rgba(0,0,0,100);"
                       "}"

                       //鼠标悬停样式
                       "QPushButton:hover"
                       "{"
                       "background-color:rgb(85,140,108);"
                       "border-color:rgba(135,206,255,30);"
                       "color:rgba(0,0,0,200);"
                       "}"
                );

    miniButton->setStyleSheet(
                       //正常状态样式
                       "QPushButton"
                       "{"
                       "background-color:rgb(94,144,85);"//背景色（也可以设置图片）
                       "border-width:10px;"                    //边框宽度像素
                       "border-color:rgb(126,192,238);"    //边框颜色

                       "font:bold 20px;"                       //字体，字体大小
                       "color:rgb(0,0,0);"                //字体颜色
                       "padding:6px;"                          //填衬
                       "}"

                       //鼠标按下样式
                       "QPushButton:pressed"
                       "{"
                       "background-color:rgb(85,140,108);"
                       "border-color:rgba(135,206,255,30);"
                       "border-style:inset;"
                       "color:rgba(0,0,0,100);"
                       "}"

                       //鼠标悬停样式
                       "QPushButton:hover"
                       "{"
                       "background-color:rgb(85,140,108);"
                       "border-color:rgba(135,206,255,30);"
                       "color:rgba(0,0,0,200);"
                       "}"
                );

    signedButton->setStyleSheet(
                       //正常状态样式
                       "QPushButton"
                       "{"
                       "background-color:rgb(110,151,72);"//背景色（也可以设置图片）
                       "border-width:10px;"                    //边框宽度像素
                       "border-color:rgb(126,192,238);"    //边框颜色

                       "font:bold 20px;"                       //字体，字体大小
                       "color:rgb(0,0,0);"                //字体颜色
                       "padding:6px;"                          //填衬
                       "}"

                       //鼠标按下样式
                       "QPushButton:pressed"
                       "{"
                       "background-color:rgb(85,140,108);"
                       "border-color:rgba(135,206,255,30);"
                       "border-style:inset;"
                       "color:rgba(0,0,0,100);"
                       "}"

                       //鼠标悬停样式
                       "QPushButton:hover"
                       "{"
                       "background-color:rgb(85,140,108);"
                       "border-color:rgba(135,206,255,30);"
                       "color:rgba(0,0,0,200);"
                       "}"
                );

    markButton->setStyleSheet(
                       //正常状态样式
                       "QPushButton"
                       "{"
                       "background-color:rgb(237,234,203);"//背景色（也可以设置图片）
                       "border-width:10px;"                    //边框宽度像素
                       "border-color:rgb(126,192,238);"    //边框颜色

                       "font:bold 20px;"                       //字体，字体大小
                       "color:rgb(0,0,0);"                //字体颜色
                       "padding:6px;"                          //填衬
                       "}"

                       //鼠标按下样式
                       "QPushButton:pressed"
                       "{"
                       "background-color:rgb(85,140,108);"
                       "border-color:rgba(135,206,255,30);"
                       "border-style:inset;"
                       "color:rgba(0,0,0,100);"
                       "}"

                       //鼠标悬停样式
                       "QPushButton:hover"
                       "{"
                       "background-color:rgb(85,140,108);"
                       "border-color:rgba(135,206,255,30);"
                       "color:rgba(0,0,0,200);"
                       "}"
                );

    mainLayout->addWidget(markButton, 0,7);
    mainLayout->addWidget(signedButton, 1,7);

    //子窗口的信号和槽
    connect(signedButton,&QPushButton::clicked,this,&rollBookWidget::signS);
    //处理子窗口的信号
    connect(&w,&signBookWidget::signedSignal,this,&rollBookWidget::dealsign);
    //connect(signedButton,&QPushButton::clicked,this,&NatureWidget::signedButtonClicked);

    //标记学生
    this->connect(markButton, SIGNAL(clicked()), this, SLOT(markButtonClicked()));

    //不显示标题栏
    this->setWindowFlags(Qt::FramelessWindowHint|Qt::WindowStaysOnTopHint);

    movewidget = false;//窗口移动

    QTextCodec *codec = QTextCodec::codecForName("UTF-8");
    QTextCodec::setCodecForLocale(codec);



    ui->setupUi(this);
}

rollBookWidget::~rollBookWidget()
{
    delete ui;
}

void rollBookWidget::markButtonClicked()
{
    QFile file("D:/qt_user/field/sign.txt");
    QString str = strListImport.at(test);
    QString change="\r\n";
    //file.open(QIODevice::WriteOnly | QIODevice::Text);
    file.open(QIODevice::WriteOnly|QIODevice::Append);
    file.write(str.toUtf8());
    file.write(change.toUtf8());
    file.close();


}

void rollBookWidget::signedButtonClicked()
{

}

//退出
void rollBookWidget::quitButtonClicked()
{
    QFile file("D:/qt_user/field/sign.txt");
    file.open(QFile::WriteOnly|QFile::Truncate);
    file.close();
}

//导入
void rollBookWidget::inputButtonClicked()
{
    if (strListImport.isEmpty())//数据导入为空则导入，否则给出提示信息
    {
        importData();
    }

    else
    {
        //提示信息
        switch(QMessageBox::question(this, tr("提示："), tr("本次导入会覆盖上一次数据，是否继续？"), QMessageBox::No|QMessageBox::No, QMessageBox::Yes))
        {
        case QMessageBox::Yes:
            strListImport.clear();//选择yes则清空数据表，计数器清0， 再导入数据信息
            count = 0;
            importData();
            break;

        default:
            break;
        }
    }
}

//开始
void rollBookWidget::beginButtonClicked()
{

    if (count == 0)//若计数器为0，给出提示信息
        QMessageBox::information(this, tr("提示："), tr("您还没有导入数据！"));

    else
    {//开关按钮标志位，每按一次取反一次
        switchButtonFlg = !switchButtonFlg;

        if (switchButtonFlg)
        {
            beginButton->setText(tr("停止"));
            switchTime->start(50);
            qDebug()<<strListImport;
        }

        else
        {
            beginButton->setText(tr("开始"));
            switchTime->stop();
            //strListImport.removeAt(test);//移除已被点名的人
            count--;
            qDebug()<<strListImport;
        }

    }
}



void rollBookWidget::switchTimeOut()//定时器溢出处理函数
{
    test = qrand()%count;//初始化随机数
    nameDisplayLabel->setText(strListImport.at(test));
    qDebug() << "随机数：" << test << " count: " << count;

}

//数据导入函数
void rollBookWidget::importData()
{
    //获取文件
    QString fileName = QFileDialog::getOpenFileName(this);
    if(!fileName.isEmpty())
    {
        QFile file(fileName);

        if (file.open(QIODevice::ReadOnly|QIODevice::Text))//以只读方式打开文本信息
        {
            QTextStream textStream(&file);
            while(!textStream.atEnd())
            {//一行一行的读取数据

                QString temp = textStream.readLine();

                if (!temp.isEmpty())//数据把不为空加入QStringList表中，且计数器加1
                {
                    strListImport.append(temp);
                    count++;
                }
            }

            QMessageBox::information(this, tr("提示："), tr("您成功导入 %1 个名字！").arg(count));
        }
    }

    else

        QMessageBox::information(this, tr("提示："), tr("导入失败！"));

}


//控制另一个窗口
void rollBookWidget::signS()
{
    w.show();
    this->hide();
}

void rollBookWidget::dealsign()
{
    w.hide();
    show();
}

//改变窗口背景
void rollBookWidget::paintEvent(QPaintEvent *event)
{

    QPixmap pixmap = QPixmap("D:/qt_user/field/field.png").scaled(this->size());//nature、ballon、sea
    QPainter painter(this);
    painter.drawPixmap(this->rect(), pixmap);
}


//{控制窗口移动
void rollBookWidget::mousePressEvent(QMouseEvent *event)
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

void rollBookWidget::mouseMoveEvent(QMouseEvent *event)
{
    if (event->buttons() & Qt::LeftButton)
    {
        //移动中的鼠标位置相对于初始位置的相对位置
        QPoint relativePos = event->globalPos() - m_startPoint;
        //然后移动窗体即可
        this->move(m_windowPoint + relativePos );
    }

}

void rollBookWidget::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        //改变移动状态
        movewidget = false;
    }

}
//控制窗口移动}

void rollBookWidget::enterEvent(QEvent *)
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

void rollBookWidget::leaveEvent(QEvent *)
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
