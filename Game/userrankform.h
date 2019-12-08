#ifndef USERRANKFORM_H
#define USERRANKFORM_H

#include <QWidget>

namespace Ui {
class userRankForm;
}

class userRankForm : public QWidget
{
    Q_OBJECT

public:
    explicit userRankForm(QWidget *parent = nullptr);
    ~userRankForm();
    void closeEvent(QCloseEvent *event);
    void userRankShow();

signals:
    void userRankOut();

private:
    Ui::userRankForm *ui;
};

#endif // USERRANKFORM_H
