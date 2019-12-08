#include "userspace.h"
#include "ui_userspace.h"
#include <QDebug>
#include <QWidget>
#include "userlogin.h"
#include <QPushButton>
#include <QMessageBox>
extern QString user_name;
userSpace::userSpace(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::userSpace)
{
    ui->setupUi(this);
    QPalette pal = this->palette();
    pal.setBrush(QPalette::Background, QBrush(QPixmap(":/img/space.jpg")));
    setPalette(pal);
    btnWuziqi = ui->btn_Wuziqi;
    btnPlane = ui->btn_Plane;
    btnInfo = ui->btn_Info;
    btnRank = ui->btn_Rank;
    ui->btn_Info->setStyleSheet("color:red");
    ui->btn_Rank->setStyleSheet("color:red");
    ui->btn_Plane->setStyleSheet("color:pink");
    ui->btn_Wuziqi->setStyleSheet("color:pink");
    QFont  font_ = QFont( "Microsoft YaHei", 20, 75); //第一个属性是字体（微软雅黑），第二个是大小，第三个是加粗（权重是75）
    ui->btn_Info->setFont(font_);

    font_ = QFont( "Microsoft YaHei", 13, 63);
    ui->btn_Plane->setFont(font_);

    font_ = QFont( "Microsoft YaHei", 13, 63);
    ui->btn_Wuziqi->setFont(font_);

    font_ = QFont( "Microsoft YaHei", 20, 75);
    ui->btn_Rank->setFont(font_);
}

userSpace::~userSpace()
{
    delete ui;
}

void userSpace::userSpaceShow() {
    this->show();
}

void userSpace::userSpaceHidden(){
    this->hide();
}

void userSpace::userSpaceWelcom()
{

    QString tmp = QString("%1, 欢迎来到联机互游平台").arg(user_name);
    ui->label->setText(tmp);
    QFont font ( "Microsoft YaHei", 20, 75); //第一个属性是字体（微软雅黑），第二个是大小，第三个是加粗（权重是75）
    font.setItalic(true);
    ui->label->setFont(font);

//    QFont::Light - 25 高亮
//    QFont::Normal - 50 正常
//    QFont::DemiBold - 63 半粗体
//    QFont::Bold - 75 粗体
//    QFont::Black - 87 黑体

    qDebug() << tmp << endl;


}
