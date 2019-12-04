#include "control.h"

const QPointF scoreTextPos = QPointF(650, 520);
const QPointF lifeBarPos = QPointF(650, 550);
const QPointF skillBarPos = QPointF(650, 570);

const int myBulletShootTimerItv = 300;
const int enemyBulletShootTimerItv = 1000;
const int allBulletMoveTimerItv = 10;

const int myPlaneMoveTimerItv = 30;
const int enemyPlaneMoveTimerItv = 50;
const int enemyPlaneGenerateTimerItv = 3000;
const int bossGenerateTimeItv = 5000;

Control::Control()
{
    setSceneRect(0, 0, 800, 600);
}
