#include "userinfoform.h"
#include "ui_userinfoform.h"
#include <QApplication>
#include <QDesktopWidget>
#include <QDebug>
#include "dbhelper.h"
extern QString user_name;
UserInfoForm::UserInfoForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UserInfoForm)
{
    ui->setupUi(this);
}

UserInfoForm::~UserInfoForm()
{
    delete ui;
}

void UserInfoForm::closeEvent(QCloseEvent *event)
{
    userInfoOut();
}

void UserInfoForm::userInfoShow() {

    qDebug() << "info " << user_name << endl;

    QDesktopWidget *desktop = QApplication::desktop();
    int win_width = desktop->width() / 2;
    int win_height = desktop->height() / 2;

    int width = this->width() / 2;
    int height = this->height() / 2;
    int x = win_width - width;
    int y = win_height - height;
    move(x, y);

    ui->userTable->setColumnCount(2);
    // 设置行数
    ui->userTable->setRowCount(2);
    // 水平表头名
    ui->userTable->setHorizontalHeaderLabels(QStringList() << "游戏" << "得分");
    QTableWidgetItem *item1 =  new QTableWidgetItem("五子棋");
    item1->setTextAlignment(Qt::AlignCenter);
    ui->userTable->setItem(0, 0, item1);

    QTableWidgetItem *item2;

    QTableWidgetItem *item3 =  new QTableWidgetItem("飞机大战");
    item3->setTextAlignment(Qt::AlignCenter);
    ui->userTable->setItem(1, 0, item3);

    QTableWidgetItem *item4;

    dbHelper *db = new dbHelper;
    db->dbConnect();
    QSqlQuery query;
    QString sql = QString("select ugrade from %1.grades where uname = '%2' and gname = '五子棋'").arg(db->dbName).arg(user_name);
    qDebug() << sql << endl;
    query.prepare(sql);
    query.exec();
    if (query.first() == false) {
        item2 =  new QTableWidgetItem("0");
        item2->setTextAlignment(Qt::AlignCenter);
        ui->userTable->setItem(0, 1, item2);
    }else {
        QString tmp = query.value(0).toString();
        item2 =  new QTableWidgetItem(tmp);
        item2->setTextAlignment(Qt::AlignCenter);
        ui->userTable->setItem(0, 1, item2);
    }
    sql = QString("select ugrade from %1.grades where uname = '%2' and gname = '飞机大战'").arg(db->dbName).arg(user_name);
    qDebug() << sql << endl;
    query.prepare(sql);
    query.exec();
    if (query.first() == false) {
        item4 =  new QTableWidgetItem("0");
        item4->setTextAlignment(Qt::AlignCenter);
        ui->userTable->setItem(1, 1, item4);
    }else {
        QString tmp = query.value(0).toString();
        item4 =  new QTableWidgetItem(tmp);
        item4->setTextAlignment(Qt::AlignCenter);
        ui->userTable->setItem(1, 1, item4);
    }

    ui->userTable_1->setColumnCount(3);
    // 设置行数
    ui->userTable_1->setRowCount(1);
    // 水平表头名
    ui->userTable_1->setHorizontalHeaderLabels(QStringList() << "用户名" << "密码" << "性别");

    sql = QString("select * from %1.users where uname = '%2'").arg(db->dbName).arg(user_name);
    qDebug() << sql << endl;
    query.prepare(sql);
    query.exec();
    query.first();
    for (int i = 0; i  < 3; ++i) {
        QString tmp = query.value(i).toString();
        if (i == 2 && tmp == "male") tmp = "男";
        if (i == 2 && tmp == "female") tmp = "女";
        QTableWidgetItem *item =  new QTableWidgetItem(tmp);
        item->setTextAlignment(Qt::AlignCenter);
        ui->userTable_1->setItem(0, i, item);
    }

    this->show();
}
