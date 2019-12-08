#include "wuziqihelp.h"
#include "ui_wuziqihelp.h"

wuziqiHelp::wuziqiHelp(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::wuziqiHelp)
{
    ui->setupUi(this);

    QStringList list;
    list << "五子棋规则:"
         << "人机模式(竞技):"
         << "玩家执白起先手, 电脑执黑旗后手. 每局游戏玩家获胜加10分, 失败扣2分, 平局加3分."
         << "人人模式(休闲):"
         << "两位玩家轮流下棋, 由电脑判断输赢."
         << "一共有两种模式:"
         << "一共有两种模式:"
         << "一共有两种模式:"
         << "一共有两种模式:"
         << "一共有两种模式:"
         << "一共有两种模式:"
         << "一共有两种模式:"
         << "一共有两种模式:"
         << "一共有两种模式:"
         << "一共有两种模式:";
    ui->listWidget->addItems(list);


}

wuziqiHelp::~wuziqiHelp()
{
    delete ui;
}
