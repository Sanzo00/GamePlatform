#include "UserinFormation.h"
#include <QApplication>
#include <QDesktopWidget>
#include <QTableWidget>
UserInformation::UserInformation(QWidget *parent) : QWidget(parent)
{
    QDesktopWidget *desktop = QApplication::desktop();
    int win_width = desktop->width() / 2;
    int win_height = desktop->height() / 2;

    int width = this->width() / 2;
    int height = this->height() / 2;
    int x = win_width - width;
    int y = win_height - height;
    move(x, y);

     //tableWidget使用
     //设置列数
    QTableWidget *tw = new QTableWidget;
    this->setTableWidget(tw);
    tw->setColumnCount(3);
    // 设置行数
    tw->setRowCount(5);
    // 水平表头名
    tw->setHorizontalHeaderLabels(QStringList() << "性别" << "性别" << "年龄");
    // 添加内容
    tw->setItem(0, 0, new QTableWidgetItem("yh"));
    tw->setItem(0, 1, new QTableWidgetItem("male"));
    tw->setItem(0, 2, new QTableWidgetItem("19"));
    QList<QString> names;
    names << "鲁班" << "亚瑟" << "安琪拉" << "上官婉儿" << "孙尚香";
    QList<QString> sexs;
    sexs << "男" << "男" << "女" << "女" << "女";
    for (int i = 0; i < 5; ++i) {
        int now = 0;
        tw->setItem(i, now++, new QTableWidgetItem(names[i]));
        tw->setItem(i, now++, new QTableWidgetItem(sexs.at(i)));
        tw->setItem(i, now++, new QTableWidgetItem(QString::number(18 + i)));
    }
    tw->show();

}
