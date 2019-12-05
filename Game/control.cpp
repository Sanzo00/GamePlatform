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

    this->myPlaneImageFile = ":/img/myplane.png";
    this->myLife = 50;
    this->mySkill = 5;

    this->myBulletImageFile = ":/img/mybullet.png";
    this->myBulletPower = 1;

    this->enemyPlaneImageFile = ":/img/enemyplane.png";
    this->enemyLife = 1;

    this->enemyBulletImageFile = ":/img/enemybullet.png";
    this->enemyBulletPower = 1;

    this->bossImageFile = ":/img/boss.png";
    this->bossLife = 10;

    this->bossBulletImageFile = ":/img/bossbullet.png";
    this->bossBulletPower = 2;

    this->lifeSupplyImageFile = ":/img/lifesupply.png";

    // 生命条
    lifeFrameBar = new QGraphicsRectItem(lifeBarPos.x(), lifeBarPos.y(), myLife*2, 5);
    lifeFrameBar->setPen(QPen(Qt::white));
    addItem(lifeFrameBar);
    lifeFrameBar->hide();

    lifeBar = new QGraphicsRectItem(lifeBarPos.x(), lifeBarPos.y(), myLife*2, 5);
    lifeBar->setBrush(QBrush(Qt::green));
    addItem(lifeBar);
    lifeBar->hide();

    // 技能条
    skillFrameBar = new QGraphicsRectItem(skillBarPos.x(), skillBarPos.y(), myLife*2, 5);
    skillFrameBar->setPen(QPen(Qt::white));
    addItem(skillFrameBar);
    skillFrameBar->hide();

    skillBar = new QGraphicsRectItem(skillBarPos.x(), skillBarPos.y(), mySkill*2, 5);
    skillBar->setBrush(QBrush(Qt::blue));
    addItem(skillBar);
    skillBar->hide();

    // 初始化背景, 播放音乐
    playList = new QMediaPlaylist;
    playList->addMedia(QUrl("qrc:///music/starwars.mp3"));
    playList->setPlaybackMode(QMediaPlaylist::CurrentItemInLoop);
    player = new QMediaPlayer(this);
    player->setPlaylist(playList);
    player->play();

    // 遮挡面板
    QWidget *mask = new QWidget;
    mask->setAutoFillBackground(true);
    mask->setPalette(QPalette(QColor(0, 0, 0, 80)));
    mask->resize(width(), height());
    maskWidget = addWidget(mask);
    maskWidget->setPos(0, 0);
    maskWidget->setZValue(1);
    maskWidget->hide();

    // 子弹类型初始化
    myBulletType = 0;
    score = 0;
    scoreText = new QGraphicsTextItem;
    scoreText->setPos(scoreTextPos);
    scoreText->setHtml(tr("<font color=white>Score: %1</font>").arg(score));
    scoreText->setFont(QFont("Courier"));
    addItem(scoreText);
    scoreText->hide();

    // 游戏开始
    QPushButton *startGameBtn = new QPushButton("开始游戏");
    startGameBtn->setFont(QFont("Algerian", 18));
    startGameBtn->setStyleSheet("QPushButton{background: transparent; color:white; }"
                                "QPushButton:hover{color:red;}");
    connect(startGameBtn, &QPushButton::clicked, this, &Control::startGame);
    startGameButton = addWidget(startGameBtn);
    startGameButton->setPos(300, 250);
    startGameButton->setZValue(2);
    startGameButton->hide();

    //游戏帮助
    QPushButton *helpGameBtn = new QPushButton(tr("帮助"));
    helpGameBtn->setFont(QFont("Algerian", 18));
    helpGameBtn->setStyleSheet("QPushButton{background: transparent; color:white;}"
                               "QPushButton:hover{color:red;}");
    connect(helpGameBtn, &QPushButton::clicked, this, &Control::showHelpMessage);
    helpGameButton = addWidget(helpGameBtn);
    helpGameButton->setPos(350, 300);
    helpGameButton->setZValue(2);
    helpGameButton->hide();

    // 退出游戏
    QPushButton *quitGameBtn = new QPushButton(tr("退出游戏"));
    quitGameBtn->setFont(QFont("Alerian", 18));
    quitGameBtn->setStyleSheet("QPushButton{background: transparent; color:white;}"
                               "QPushButton:hover{color:red;}");
    connect(quitGameBtn, &QPushButton::clicked, this, &Control::quitGame);
    quitGameButton = addWidget(quitGameBtn);
    quitGameButton->setPos(310, 350);
    quitGameButton->setZValue(2);
    quitGameButton->hide();

    // 游戏暂停



}



void Control::timerEvent(QTimerEvent *event) {

}

void Control::keyPressEvent(QKeyEvent *event) {

}

void Control::keyReleaseEvent(QKeyEvent *event) {

}

bool Control::generateEnemyPlane() {

}

bool Control::generateBoss(){ // 生成BOSS

}

bool Control::changePlanePosition(Plane *plane, int newX, int newY) {

}

bool Control::updateEnemyPlanes(){ // 根据敌机方向更新敌机位置

}

bool Control::changeBulletPosition(Bullet *bullet, int newX, int newY) {

}

void Control::shootEnemyBullets(){ // 敌机发射子弹

}

void Control::updateMyBullets(){ // 更新玩家子弹位置

}

void Control::shootBullet(){ // 玩家发射子弹

}

void Control::updateBar(QGraphicsRectItem *bar, QGraphicsRectItem *grameBar,
                        const QPointF &pos, qreal var, const QBrush &brush){ // 更新血条和技能条

}

void Control::welcomeGame() {

}

void Control::startGame() {

}

void Control::showHelpMessage(){ // 显示帮助文档

}

void Control::pauserGame() {

}

void Control::loseGame() {

}

void Control::retryGame() {

}

void Control::quitGame() {

}



































