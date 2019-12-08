#ifndef WUZIQIGAME_H
#define WUZIQIGAME_H

#include <QMainWindow>
#include "wuziqimodel.h"
class wuziqiGame : public QMainWindow
{
    Q_OBJECT
public:
    explicit wuziqiGame(QWidget *parent = nullptr);
    ~wuziqiGame();
    GameModel *game;
    GameType game_type;
    int clickPosRow, clickPosCol;
    void initGame();
    void checkGame(int x, int y);
    void chessOneByPerson();
    void chessOneByAI();
    void initPVPGame();
    void initPVEGame();
    // 绘图
    void paintEvent(QPaintEvent *event);
    // 监听鼠标移动
    void mouseMoveEvent(QMouseEvent *event);
    // 落子
    void mouseReleaseEvent(QMouseEvent *event);
    void closeEvent(QCloseEvent *event);
    void showHelpMessage();
protected:
    void updateGrade(int delt);
signals:
    void wuziqiOut();

public slots:
    void wuziqiShow();
    void wuziqiHidden();
    void sleepAI();

};

#endif //  WUZIQIGAME_H
