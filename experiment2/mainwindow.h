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
    int n=1;
    float yy=0,zz=0,sx=0,zyk=0;

protected:
    void timerEvent(QTimerEvent* event);

private:
    Ui::MainWindow *ui;


private slots:
    // 槽函数，响应按钮点击事件
    void onAddNewButtonClicked(); // 添加按钮

private:

    // 私有成员变量，存储界面控件对象指针
    QLabel *nameLabel; //姓名标签
    QLabel *yyLabel; // 英语标签
    QLabel *zzLabel; // 政治标签
    QLabel *sxLabel; // 数学标签
    QLabel *zykLabel; // 专业课标签
    QLabel *aveLabel; // 专业课标签

    QLineEdit *nameLineEdit[100]; // 姓名输入框
    QLineEdit *yyLineEdit[100];
    QLineEdit *zzLineEdit[100];
    QLineEdit *sxLineEdit[100];
    QLineEdit *zykLineEdit[100];
    QLineEdit *aveyyLineEdit;
    QLineEdit *avezzLineEdit;
    QLineEdit *avesxLineEdit;
    QLineEdit *avezykLineEdit;

    QPushButton *addnewButton; // 添加按钮
    int id1;

};
#endif // MAINWINDOW_H
