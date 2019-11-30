#ifndef USERSIGNUP_H
#define USERSIGNUP_H

#include <QDialog>
#include <QSql>
#include <QSqlQueryModel>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QRadioButton>
#include <QLineEdit>
#include "dbhelper.h"
namespace Ui {
class userSignup;
}

class signUp : public QDialog
{
    Q_OBJECT

public:
    explicit signUp(QWidget *parent = nullptr);
    ~signUp();
    QString textSex;
    QPushButton *clear;
    QPushButton *submit;
    void closeEvent(QCloseEvent *event);


public: signals:
    void submitSignup(QString name, QString pwd, QString sex);
    void signOut();


public slots:
    void signShow();
    void signHidden();
    void addUser();
    void textClear();

private:
    Ui::userSignup *ui;
    void setDataBase(QSqlDatabase *dbconn);
};

#endif // USERSIGNUP_H
