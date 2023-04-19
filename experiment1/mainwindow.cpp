#include "mainwindow.h"
#include <QMessageBox>
#include "ui_mainwindow.h"
#include <QSettings>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("注册登录界面");
    // 设置界面初始大小为800x600
    this->resize(400, 500);
    // 创建界面控件对象，并设置属性
    accountLabel = new QLabel("账号：", this);
    accountLabel->setGeometry(50, 50, 50, 30);

    passwordLabel = new QLabel("密码：", this);
    passwordLabel->setGeometry(50, 100, 50, 30);

    confirmPasswordLabel = new QLabel("确认密码：", this);
    confirmPasswordLabel->setGeometry(20, 150, 80, 30);

    genderLabel = new QLabel("性别：", this);
    genderLabel->setGeometry(50, 250, 50, 30);

    ageLabel = new QLabel("年龄：", this);
    ageLabel->setGeometry(50, 300, 50 ,30);
    accountLineEdit = new QLineEdit(this);
    accountLineEdit->setGeometry(100 ,50 ,200 ,30);

    passwordLineEdit = new QLineEdit(this);
    passwordLineEdit->setGeometry(100 ,100 ,200 ,30);
    passwordLineEdit->setEchoMode(QLineEdit::Password); // 设置为密码输入模式
    confirmPasswordLineEdit = new QLineEdit(this);
    confirmPasswordLineEdit->setGeometry(100 ,150 ,200 ,30);
    confirmPasswordLineEdit->setEchoMode(QLineEdit::Password); // 设置为密码输入模式

    addDetailButton = new QPushButton("添加详细信息", this);
    addDetailButton->setGeometry(100 ,200 ,200 ,30);

    registerButton = new QPushButton("注册", this);
    registerButton->setGeometry(100 ,350 ,200 ,30);

    loginButton = new QPushButton("登录", this);
    loginButton->setGeometry(100 ,150 ,200 ,30);

    genderComboBox = new QComboBox(this);
    genderComboBox->setGeometry(100, 250, 200, 30);
    genderComboBox->addItem("男");
    genderComboBox->addItem("女");

    ageComboBox = new QComboBox(this);
    ageComboBox->setGeometry(100, 300, 200, 30);
    // 添加年龄选项
    for (int i = 18; i <= 60; i++) {
        ageComboBox->addItem(QString::number(i));
    }
    // 连接信号和槽
    connect(addDetailButton, SIGNAL(clicked()), this, SLOT(onAddDetailButtonClicked()));
    connect(registerButton, SIGNAL(clicked()), this, SLOT(onRegisterButtonClicked()));
    connect(loginButton, SIGNAL(clicked()), this, SLOT(onLoginButtonClicked()));

    // 初始界面，隐藏性别、年龄、注册按钮
    genderLabel->hide();
    ageLabel->hide();
    registerButton->hide();
    genderComboBox->hide();
    ageComboBox->hide();
    loginButton->hide();



}

MainWindow::~MainWindow()
{
    delete ui;
}

// 槽函数，响应添加详细信息按钮点击事件
void MainWindow::onAddDetailButtonClicked()
{
    // 显示性别、年龄、注册按钮，隐藏添加详细信息按钮
    genderLabel->show();
    ageLabel->show();
    registerButton->show();
    genderComboBox->show();
    ageComboBox->show();

    //addDetailButton->hide();
}

// 槽函数，响应注册按钮点击事件
void MainWindow::onRegisterButtonClicked()
{

    addDetailButton->hide();

    // 获取输入框和选择框的内容
    QString account = accountLineEdit->text();
    QString password = passwordLineEdit->text();
    QString confirmPassword = confirmPasswordLineEdit->text();
    QString gender = genderComboBox->currentText();
    QString age = ageComboBox->currentText();

    // 创建一个QSettings对象
    QSettings settings("MyApp", "MyCompany");

    // 将账户密码保存到配置文件中
    settings.setValue("account", account);
    settings.setValue("password", password);


    // 判断输入是否合法
    if (account.isEmpty() || password.isEmpty() || confirmPassword.isEmpty()) {
        QMessageBox::warning(this, "警告", "账号或密码不能为空！");
        return;
    }
    if (password != confirmPassword) {
        QMessageBox::warning(this, "警告", "两次输入的密码不一致！");
        return;
    }
    // 弹出消息框，显示注册信息
    QMessageBox::information(this, "注册成功", QString("账号：%1\n密码：%2\n性别：%3\n年龄：%4").arg(account).arg(password).arg(gender).arg(age));




    // 隐藏注册内容，显示登录框
    accountLabel->setText("账号：");
    passwordLabel->setText("密码：");
    confirmPasswordLabel->hide();
    confirmPasswordLineEdit->hide();
    genderLabel->hide();
    ageLabel->hide();
    registerButton->hide();
    genderComboBox->hide();
    ageComboBox->hide();

    loginButton->show();
    // 清空输入框
    accountLineEdit->clear();
    passwordLineEdit->clear();
    confirmPasswordLineEdit->clear();


}




// 槽函数，响应登录按钮点击事件
void MainWindow::onLoginButtonClicked()
{
    // 创建一个QSettings对象
    QSettings settings("MyApp", "MyCompany");
    // 读取之前保存的账户密码
    QString account = settings.value("account").toString();
    QString password = settings.value("password").toString();


    // 获取输入框的内容
    QString account1 = accountLineEdit->text();
    QString password1 = passwordLineEdit->text();

    // 判断输入是否合法
    if (account1.isEmpty() || password1.isEmpty()) {
        QMessageBox::warning(this, "警告", "账号或密码不能为空！");
        return;
    }

    // 模拟登录验证，假设账号为admin，密码为123456
    if (account1 == account && password1 == password) {
        QMessageBox::information(this, "登录成功", "欢迎使用本系统！");
        this->close(); // 关闭窗口
    } else {
        QMessageBox::warning(this, "登录失败", "账号或密码错误！");
    }

}
