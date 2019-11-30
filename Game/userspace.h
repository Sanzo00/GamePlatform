#ifndef USERSPACE_H
#define USERSPACE_H

#include <QDialog>
#include "userlogin.h"
namespace Ui {
class userSpace;
}

class userSpace : public QDialog
{
    Q_OBJECT

public:
    explicit userSpace(QWidget *parent = nullptr);
    ~userSpace();
    QPushButton *btnWuziqi;


public: signals:
    void wiziqiShow();

public slots:
    void userSpaceShow();
    void userSpaceHidden();

private:
    Ui::userSpace *ui;

};

#endif // LOGIN_H
