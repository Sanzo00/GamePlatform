#include "userlogin.h"
#include "ui_userlogin.h"
#include "userspace.h"
#include "usersignup.h"
#include "dbhelper.h"
#include <wuziqigame.h>
#include <QMessageBox>
#include <QDesktopWidget>
#include <QDebug>
//QString userLogin::user_name = "";
QString user_name;
userLogin::userLogin(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::userLogin)
{
    ui->setupUi(this);

    setStyleSheet("#userLogin{border-image:url(:/img/login.jpg);}");

    // 获取登录窗口的btn
    btnSign = ui->pushButton1;
    btnLogin = ui->pushButton2;

    // 窗口屏幕居中
    QDesktopWidget *desktop = QApplication::desktop();
    move((desktop->width() - this->width()) / 2, (desktop->height() - this->height()) /2);
}

userLogin::~userLogin()
{
    delete ui;
}

void userLogin::showLogin(){
    this->show();
}

void userLogin::loginShow() {
    this->show();
}

void userLogin::loginHidden() {
    this->hide();
}

void userLogin::getLoginText()
{
    textName = ui->uNameData->text();
    textPwd = ui->uPwdData->text();
}

void userLogin::checkLogin() {
    dbHelper *db = new dbHelper;
    db->dbConnect();
    int ret = 1; // 忽略数据库连接错误
    if (db->checkUser(textName) ==  0) ret = -1;
    else if (db->checkPwd(textName, textPwd) == 0) ret = -2;

    if (ret < 0) {
        QMessageBox::information(this, "提示", "用户名或密码错误");
    }else {
        this->hide();
        user_name = textName;
        loginOver(); // 发出登录成功信号
        qDebug() << "login : " << user_name << endl;
    }
    if (db) {
        delete(db);
        db = NULL;
    }
}
