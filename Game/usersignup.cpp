#include "usersignup.h"
#include "ui_usersignup.h"
#include <QPushButton>
#include <QDebug>
#include <QMessageBox>
signUp::signUp(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::userSignup)
{
    QPalette pal = this->palette();
    pal.setBrush(QPalette::Background, QBrush(QPixmap(":/img/signup.png")));
    setPalette(pal);
    ui->setupUi(this);
    clear = ui->pushButton1;
    submit = ui->pushButton2;
    ui->radioButton1->setChecked(true);
}

signUp::~signUp()
{
    delete ui;
}

void signUp::signShow() {
    this->show();
}

void signUp::signHidden() {
    this->hide();
}

void signUp::textClear() { // 重置输入
    ui->lineEdit1->clear();
    ui->lineEdit2->clear();
    ui->radioButton1->setChecked(true);
    ui->radioButton2->setChecked(false);
}

void signUp::addUser() { // 注册用户
    QString name = ui->lineEdit1->text();
    QString pwd = ui->lineEdit2->text();
    QString sex = "male";
    if (ui->radioButton2->isChecked()) sex = "female";

    dbHelper *db = new dbHelper;
    db->dbConnect();
    if (name == "") {
        QMessageBox::about(this, "提示", "用户名不能为空");
    }else if (db->checkUser(name) == 1) {
        QMessageBox::about(this, "提示", "用户已经存在");
    }else if (pwd == "") {
        QMessageBox::about(this, "提示", "密码不能为空");
    }else {
        db->dbconn.open();
        QSqlQuery query;
        query.prepare("insert into " + db->dbName + ".users(uname, upwd, usex) values(:name, :pwd, :sex)");
        query.bindValue(":name", name);
        query.bindValue(":pwd", pwd);
        query.bindValue(":sex", sex);
        bool flag = query.exec();
        if (flag == true)
            QMessageBox::about(this, "提示", "注册成功");
        else
            QMessageBox::about(this, "提示", "网络有点问题");
        db->dbconn.close();
    }
    if (db) {
        delete(db);
        db = NULL;
    }
}

void signUp::closeEvent(QCloseEvent *event) {
    signOut();
}
