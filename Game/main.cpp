#include "userlogin.h"
#include <QApplication>
#include "userspace.h"
#include "usersignup.h"
#include <wuziqigame.h>
#include "Control.h"
#include "userinfoform.h"
#include "userrankform.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    userLogin *login = new userLogin; // 登录窗口
    userSpace *uspace = new userSpace; // 游戏大厅窗口
    signUp *sign = new signUp; // 注册窗口
    wuziqiGame *wuziqi = new wuziqiGame; // 五子棋窗口
    dbHelper *db = new dbHelper; // 连接数据库
    db->dbConnect();

    login->show(); // 显示登录窗口

    // 登录: 获取登录信息, 登录验证
    QObject::connect(login->btnLogin, &QPushButton::clicked, login, &userLogin::getLoginText);
    QObject::connect(login->btnLogin, &QPushButton::clicked, login, &userLogin::checkLogin);


    // 登录: 显示游戏大厅
    QObject::connect(login, &userLogin::loginOver, uspace, &userSpace::userSpaceShow);
    QObject::connect(login, &userLogin::loginOver, uspace, &userSpace::userSpaceWelcom);

    // 登录: 显示注册
    QObject::connect(login->btnSign, &QPushButton::clicked, login, &userLogin::loginHidden);
    QObject::connect(login->btnSign, &QPushButton::clicked, sign, &signUp::signShow);


    // 注册: 清空, 提交
    QObject::connect(sign->submit, &QPushButton::clicked, sign, &signUp::addUser);
    QObject::connect(sign->clear, &QPushButton::clicked, sign, &signUp::textClear);
    QObject::connect(sign, &signUp::signOut, login, &userLogin::loginShow);


    // 游戏大厅: 显示五子棋
    QObject::connect(uspace->btnWuziqi, &QPushButton::clicked, uspace, &userSpace::userSpaceHidden);
    QObject::connect(uspace->btnWuziqi, &QPushButton::clicked, wuziqi, &wuziqiGame::wuziqiShow);
    QObject::connect(uspace->btnWuziqi, &QPushButton::clicked, wuziqi, &wuziqiGame::showHelpMessage);

    // 五子棋: 返回游戏大厅
    QObject::connect(wuziqi, &wuziqiGame::wuziqiOut, uspace, &userSpace::userSpaceShow);

    // 游戏大厅: 显示飞机大战
    Control *ctrl = new Control;

    QObject::connect(uspace->btnPlane, &QPushButton::clicked, uspace, &userSpace::userSpaceHidden);
    QObject::connect(uspace->btnPlane, &QPushButton::clicked, ctrl, &Control::planeShow);
    QObject::connect(ctrl, &Control::planeOut, uspace, &userSpace::userSpaceShow);

    UserInfoForm *info = new UserInfoForm;
    QObject::connect(uspace->btnInfo, &QPushButton::clicked, info, &UserInfoForm::userInfoShow);
    QObject::connect(uspace->btnInfo, &QPushButton::clicked, uspace, &userSpace::userSpaceHidden);
    QObject::connect(info, &UserInfoForm::userInfoOut, uspace, &userSpace::userSpaceShow);

    userRankForm *rank = new userRankForm;
    QObject::connect(uspace->btnRank, &QPushButton::clicked, rank, &userRankForm::userRankShow);
    QObject::connect(uspace->btnRank, &QPushButton::clicked, uspace, &userSpace::userSpaceHidden);
    QObject::connect(rank, &userRankForm::userRankOut, uspace, &userSpace::userSpaceShow);

    return a.exec();
}
