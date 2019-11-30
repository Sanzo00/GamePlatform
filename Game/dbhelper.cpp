#include "dbhelper.h"

//dbHelper::dbHelper(QObject *parent) : QObject(parent)
//{

//}

dbHelper::dbHelper() {
    hostName = "127.0.0.1";
    dbName = "test";
    userName = "root";
    userPwd = "jiezhi";
}
dbHelper::dbHelper(QString ip, QString database, QString user, QString pwd): hostName(ip), dbName(database), userName(user), userPwd(pwd){}

int dbHelper::checkLogin(QString name, QString pwd) {
    // ret = 0 数据库连接问题
    // ret = 1 登录成功
    // ret = -1 用户名不存在
    // ret = -2 密码错误
    int ret = 0;

    if (checkUser(name) == 0) ret = -1;
    else if (checkPwd(name, pwd) == 0) ret = -2;
    else ret = 1;
    return ret;
}

int dbHelper::checkUser(QString name) {
    int ret;
    if (dbconn.open()) {
        QString sql = "select count(uname) from " + dbName + ".users where uname = '" + name + "'";
        QSqlQueryModel *model = new QSqlQueryModel;
        model->setQuery(sql);
        if (model->index(0, 0).data() == 0) ret = 0;
        else ret = 1;
    }else ret = -1;
    dbconn.close();
    return ret;
}

int dbHelper::checkPwd(QString name, QString pwd) {
    int ret;
    if (dbconn.open()) {
        QString sql = "select upwd from " + dbName + ".users where uname = '" + name + "'";
        QSqlQueryModel *model = new QSqlQueryModel;
        model->setQuery(sql);
        if (model->index(0, 0).data() != pwd) ret = 0;
        else ret = 1;
    }else ret = -1;
    dbconn.open();
    return ret;
}

void dbHelper::dbConnect() {
    if (QSqlDatabase::contains("qt_sql_default_connection")) { // 避免重复调用adddatabase
        dbconn = QSqlDatabase::database("qt_sql_default_connection");
    }else {
        dbconn = QSqlDatabase::addDatabase("QMYSQL");
    }

    dbconn.setHostName(hostName);
    dbconn.setDatabaseName(dbName);
    dbconn.setUserName(userName);
    dbconn.setPassword(userPwd);
}


















