#ifndef DBHELPER_H
#define DBHELPER_H

#include <QObject>
#include <QSql>
#include <QSqlQueryModel>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
class dbHelper : public QObject
{
    Q_OBJECT
public:
    dbHelper(); // 默认构造
    dbHelper(QString ip, QString database, QString user, QString pwd); // 带参构造
    QString hostName;
    QString dbName;
    QString userName;
    QString userPwd;
    QSqlDatabase dbconn;

    // del checkLogin --------------
    int checkLogin(QString name, QString pwd); // 1: 连接成功, -1: 用户名错误, -2: 密码错误
    int checkUser(QString name); // 1: 用户存在, 0: 用户不存在
    int checkPwd(QString name, QString pwd); // 1: 密码正确, 0: 密码错误
    void dbConnect(); // 连接数据库

signals:

public slots:

};

#endif // DBHELPER_H
