#include "userrankform.h"
#include "ui_userrankform.h"
#include <QApplication>
#include <QDesktopWidget>
#include "dbhelper.h"
#include <QDebug>
extern QString user_name;
userRankForm::userRankForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::userRankForm)
{
    ui->setupUi(this);
}

userRankForm::~userRankForm()
{
    delete ui;
}

void userRankForm::userRankShow()
{
    QDesktopWidget *desktop = QApplication::desktop();
    int win_width = desktop->width() / 2;
    int win_height = desktop->height() / 2;

    int width = this->width() / 2;
    int height = this->height() / 2;
    int x = win_width - width;
    int y = win_height - height;
    move(x, y);
    ui->wuziqiRank->setColumnCount(2);
    // 设置行数
    ui->wuziqiRank->setRowCount(10);
    // 水平表头名
    ui->wuziqiRank->setHorizontalHeaderLabels(QStringList() << "用户" << "得分");

    dbHelper *db = new dbHelper;
    db->dbConnect();
    QSqlQuery query;
    QString sql = QString("select * from %1.grades where gname = '五子棋' order by ugrade desc").arg(db->dbName);
    qDebug() << "wuziqiRank_sql " << sql << endl;
    query.prepare(sql);
    query.exec();
    for (int i = 0; query.next(); ++i) {
        QTableWidgetItem *item =  new QTableWidgetItem(query.value(1).toString());
        item->setTextAlignment(Qt::AlignCenter);
        ui->wuziqiRank->setItem(i, 0, item);

        item = new QTableWidgetItem(query.value(2).toString());
        item->setTextAlignment(Qt::AlignCenter);
        ui->wuziqiRank->setItem(i, 1, item);
    }

    ui->planeRank->setColumnCount(2);
    // 设置行数
    ui->planeRank->setRowCount(10);
    // 水平表头名
    ui->planeRank->setHorizontalHeaderLabels(QStringList() << "用户" << "得分");
    sql = QString("select * from %1.grades where gname = '飞机大战' order by ugrade desc").arg(db->dbName);
    qDebug() << "wuziqiRank_sql " << sql << endl;
    query.prepare(sql);
    query.exec();
    for (int i = 0; query.next(); ++i) {
        QTableWidgetItem *item =  new QTableWidgetItem(query.value(1).toString());
        item->setTextAlignment(Qt::AlignCenter);
        ui->planeRank->setItem(i, 0, item);

        item = new QTableWidgetItem(query.value(2).toString());
        item->setTextAlignment(Qt::AlignCenter);
        ui->planeRank->setItem(i, 1, item);
    }
    this->show();
}

void userRankForm::closeEvent(QCloseEvent *e) {
    userRankOut();
}
