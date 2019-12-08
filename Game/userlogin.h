#ifndef USERLOGIN_H
#define USERLOGIN_H
#include <QMainWindow>
#include "dbhelper.h"
#include <QLineEdit>
#include <QPushButton>
#include "Object.h"
extern QString user_name;
QT_BEGIN_NAMESPACE
namespace Ui { class userLogin; }
QT_END_NAMESPACE

class userLogin : public QMainWindow
{
    Q_OBJECT

public:
    userLogin(QWidget *parent = nullptr);
    ~userLogin();
    QString textName; // 登录窗口输入的用户名
    QString textPwd; // 登录窗口输入的密码
    QPushButton *btnLogin;
    QPushButton *btnSign;

public: signals:
    void loginOver();

public slots:
    void showLogin();
    void loginShow();
    void loginHidden();
    void getLoginText();
    void checkLogin();
private:
    Ui::userLogin *ui;
};
#endif // USERLOGIN_H
