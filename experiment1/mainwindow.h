#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMainWindow>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QComboBox>
#include <QMessageBox>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();



private:
    Ui::MainWindow *ui;


private slots:
    // 槽函数，响应按钮点击事件
    void onAddDetailButtonClicked(); // 添加详细信息按钮
    void onRegisterButtonClicked(); // 注册按钮
    void onLoginButtonClicked(); // 登录按钮

private:
    // 私有成员变量，存储界面控件对象指针
    QLabel *accountLabel; // 账号标签
    QLabel *passwordLabel; // 密码标签
    QLabel *confirmPasswordLabel; // 确认密码标签
    QLabel *genderLabel; // 性别标签
    QLabel *ageLabel; // 年龄标签

    QLineEdit *accountLineEdit; // 账号输入框
    QLineEdit *passwordLineEdit; // 密码输入框
    QLineEdit *confirmPasswordLineEdit; // 确认密码输入框
    QPushButton *addDetailButton; // 添加详细信息按钮
    QPushButton *registerButton; // 注册按钮
    QPushButton *loginButton; // 登录按钮

    QComboBox *genderComboBox; // 性别选择框
    QComboBox *ageComboBox; // 年龄选择框

};
#endif // MAINWINDOW_H
