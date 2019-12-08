#include "userspace.h"
#include "ui_userspace.h"
#include <QDebug>
#include <QWidget>
#include "userlogin.h"
#include <QPushButton>
#include <QMessageBox>

userSpace::userSpace(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::userSpace)
{
    ui->setupUi(this);
    btnWuziqi = ui->btn_Wuziqi;
    btnPlane = ui->btn_Plane;

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
