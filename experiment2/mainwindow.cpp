#include "mainwindow.h"
#include <QMessageBox>
#include "ui_mainwindow.h"
#include <QSettings>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    id1=startTimer(1000);//定时器
    this->setWindowTitle(QString::fromUtf8("成绩管理系统"));
    // 设置界面初始大小为600x600
    this->resize(600, 250);
    // 创建界面控件对象，并设置属性
    nameLabel = new QLabel(QString::fromUtf8("姓名"), this);
    nameLabel->setGeometry(50, 20, 80, 30);// x，y，宽，高
    nameLabel->setAlignment(Qt::AlignCenter);
    yyLabel = new QLabel(QString::fromUtf8("英语"), this);
    yyLabel->setGeometry(150, 20, 80, 30);
    yyLabel->setAlignment(Qt::AlignCenter);
    zzLabel = new QLabel(QString::fromUtf8("政治"), this);
    zzLabel->setGeometry(250, 20, 80, 30);
    zzLabel->setAlignment(Qt::AlignCenter);
    sxLabel = new QLabel(QString::fromUtf8("数学"), this);
    sxLabel->setGeometry(350, 20, 80, 30);
    sxLabel->setAlignment(Qt::AlignCenter);
    zykLabel = new QLabel(QString::fromUtf8("专业课"), this);
    zykLabel->setGeometry(450, 20, 80 ,30);
    zykLabel->setAlignment(Qt::AlignCenter);

    for(int i=1;i<=n;i++){
    int tmp=i*40+20;
    nameLineEdit[i] = new QLineEdit(this);
    nameLineEdit[i]->setGeometry(50 ,tmp ,80 ,30);
    yyLineEdit[i] = new QLineEdit(this);
    yyLineEdit[i]->setGeometry(150 ,tmp ,80 ,30);
    zzLineEdit[i] = new QLineEdit(this);
    zzLineEdit[i]->setGeometry(250 ,tmp ,80 ,30);
    sxLineEdit[i] = new QLineEdit(this);
    sxLineEdit[i]->setGeometry(350 ,tmp ,80 ,30);
    zykLineEdit[i] = new QLineEdit(this);
    zykLineEdit[i]->setGeometry(450 ,tmp ,80 ,30);
    }

    aveLabel = new QLabel(QString::fromUtf8("均分"), this);
    aveLabel->setGeometry(50 ,n*40+90 ,80 ,30);
    aveLabel->setAlignment(Qt::AlignCenter);
    aveyyLineEdit = new QLineEdit(this);
    aveyyLineEdit->setGeometry(150 ,n*40+90,80 ,30);
    aveyyLineEdit->setReadOnly(true);
    avezzLineEdit = new QLineEdit(this);
    avezzLineEdit->setGeometry(250 ,n*40+90 ,80 ,30);
    avezzLineEdit->setReadOnly(true);
    avesxLineEdit = new QLineEdit(this);
    avesxLineEdit->setGeometry(350 ,n*40+90 ,80 ,30);
    avesxLineEdit->setReadOnly(true);
    avezykLineEdit = new QLineEdit(this);
    avezykLineEdit->setGeometry(450 ,n*40+90 ,80 ,30);
    avezykLineEdit->setReadOnly(true);


    addnewButton = new QPushButton(QString::fromUtf8("新增"), this);
    addnewButton->setGeometry(50 ,n*40+130 ,80 ,30);

    connect(addnewButton, SIGNAL(clicked()), this, SLOT(onAddNewButtonClicked()));
    //connect(registerButton, SIGNAL(clicked()), this, SLOT(onRegisterButtonClicked()));
    //connect(loginButton, SIGNAL(clicked()), this, SLOT(onLoginButtonClicked()));


}

MainWindow::~MainWindow()
{
    delete ui;
}

// 槽函数，响应添加按钮点击事件
void MainWindow::onAddNewButtonClicked()
{
    n++;
    yy=0,zz=0,sx=0,zyk=0;
    int i=n;
    int tmp=i*40+20;
    nameLineEdit[i] = new QLineEdit(this);
    nameLineEdit[i]->setGeometry(50 ,tmp ,80 ,30);
    nameLineEdit[i]->show();
    yyLineEdit[i] = new QLineEdit(this);
    yyLineEdit[i]->setGeometry(150 ,tmp ,80 ,30);
    yyLineEdit[i]->show();
    zzLineEdit[i] = new QLineEdit(this);
    zzLineEdit[i]->setGeometry(250 ,tmp ,80 ,30);
    zzLineEdit[i]->show();
    sxLineEdit[i] = new QLineEdit(this);
    sxLineEdit[i]->setGeometry(350 ,tmp ,80 ,30);
    sxLineEdit[i]->show();
    zykLineEdit[i] = new QLineEdit(this);
    zykLineEdit[i]->setGeometry(450 ,tmp ,80 ,30);
    zykLineEdit[i]->show();

    aveLabel->move(50 ,n*40+90);
    aveyyLineEdit->move(150 ,n*40+90);
    avezzLineEdit->move(250 ,n*40+90);
    avesxLineEdit->move(350 ,n*40+90);
    avezykLineEdit->move(450 ,n*40+90);

    addnewButton->move(50 ,n*40+130);

    this->resize(600, n*40+210);

}

//每1000ms更新均分
void MainWindow::timerEvent(QTimerEvent *event)
{
    if(event->timerId() == id1)
    {
        yy=0,zz=0,sx=0,zyk=0;
        for(int j=1;j<=n;j++){
        float yynew = yyLineEdit[j]->text().toFloat();
        float zznew = zzLineEdit[j]->text().toFloat();
        float sxnew = sxLineEdit[j]->text().toFloat();
        float zyknew= zykLineEdit[j]->text().toFloat();
        yy+=yynew;
        zz+=zznew;
        sx+=sxnew;
        zyk+=zyknew;
        }
        QString aveyy,avezz,avesx,avezyk;
        aveyy=QString::number(yy/n,'f',2);
        aveyyLineEdit->setText(aveyy);
        avezz=QString::number(zz/n,'f',2);
        avezzLineEdit->setText(avezz);
        avesx=QString::number(sx/n,'f',2);
        avesxLineEdit->setText(avesx);
        avezyk=QString::number(zyk/n,'f',2);
        avezykLineEdit->setText(avezyk);
    }
}
