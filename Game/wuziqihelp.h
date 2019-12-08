#ifndef WUZIQIHELP_H
#define WUZIQIHELP_H

#include <QWidget>

namespace Ui {
class wuziqiHelp;
}

class wuziqiHelp : public QWidget
{
    Q_OBJECT

public:
    explicit wuziqiHelp(QWidget *parent = nullptr);
    ~wuziqiHelp();

private:
    Ui::wuziqiHelp *ui;
};

#endif // WUZIQIHELP_H
