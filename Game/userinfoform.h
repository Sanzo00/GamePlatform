#ifndef USERINFOFORM_H
#define USERINFOFORM_H

#include <QWidget>

namespace Ui {
class UserInfoForm;
}

class UserInfoForm : public QWidget
{
    Q_OBJECT

public:
    explicit UserInfoForm(QWidget *parent = nullptr);
    ~UserInfoForm();
    void closeEvent(QCloseEvent *event);

signals:
    void userInfoOut();

public slots:
    void userInfoShow();

private:
    Ui::UserInfoForm *ui;
};

#endif // USERINFOFORM_H
