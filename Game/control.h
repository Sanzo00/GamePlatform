#ifndef CONTROL_H
#define CONTROL_H
#include <ctime>
#include <vector>
#include <cassert>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <sys/stat.h>
#include <QUrl>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include "plane.h"
#include "myplane.h"
#include "enemyplane.h"

class Control: public QGraphicsScene
{
    Q_OBJECT
public:
    Control();

protected:
    void timerEvent(QTimerEvent *event);
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);

private:
    std::string myPlaneImageFile;
    int myLife;
    int mySkill;

    std::string myBulletImageFile;
    int myBulletPower;

    std::string enemyPlaneImageFile;
    int enemyLife;

    std::string enemyBulletImageFile;
    int enemyBulletPower;

    std::string bossImageFile;
    int bossLife;

    std::string bossBulletImageFile;
    int bossBulletPower;

    int myBulletShootTimerId;
    int enemyBulletShootTimerId;
    int allBulletMoveTimerId;

    QPointF myPlaneMove;
    int myPlaneMoveTimerId;
    int enemyPlaneMoveTimerId;
    int bossGenerateTimeId;

    std::string lifeSupplyImageFile;

    myPlane *myplane;
    std::vector<Bullet*> mybullets;
    std::vector<enemyPlane*> enemyplanes;
    std::vector<Bullet*> enemybullets;
    std::vector<Object*> lifesupplys;

    QGraphicsRectItem *lifeFrameBar;
    QGraphicsRectItem *lifeBar;
    QGraphicsRectItem *skillFrameBar;
    QGraphicsRectItem *skillBar;

    QMediaPlayer *player;
    QMediaPlaylist *playList;

    bool generateEnemyPlane(); // 生成敌机
    bool generateBoss(); // 生成BOSS
    bool changePlanePosition(Plane *plane, int newX, int newY);
    bool updateEnemyPlanes(); // 根据敌机方向更新敌机位置
    bool changeBulletPosition(Bullet *bullet, int newX, int newY);
    void shootEnemyBullets(); // 敌机发射子弹
    void updateMyBullets(); // 更新玩家子弹位置
    void shootBullet(); // 玩家发射子弹
    void updateBar(QGraphicsRectItem *bar, QGraphicsRectItem *grameBar,
                   const QPointF &pos, qreal var, const QBrush &brush); // 更新血条和技能条
    bool hasStarted;
    bool isPause;
    int myBulletType; // 使用技能
    int skillQTimerId; // 技能使用时间
    int score;

    QGraphicsTextItem *titleText; // 游戏标题
    QGraphicsTextItem *authorText; // 作者信息
    QGraphicsTextItem *scoreText; // 显示打掉的飞机
    QGraphicsTextItem *gameLostText; // 玩家死亡显示文本
    QGraphicsTextItem *gameHelpText; // 游戏帮助文档
    void welcomeGame();

    QGraphicsWidget *maskWidget;
    QGraphicsWidget *startGameButton;
    QGraphicsWidget *helpGameButton;
    QGraphicsWidget *continueGameButton;
    QGraphicsWidget *retryGameButton;
    QGraphicsWidget *quitGameButton;

protected slots:
    void startGame();
    void showHelpMessage(); // 显示帮助文档
    void pauserGame();
    void loseGame();
    void retryGame();
    void quitGame();
};

#endif // CONTROL_H









































