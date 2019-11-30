#include "wuziqigame.h"
#include <QMenuBar>
#include <QPainter>
#include <QMenu>
#include <QApplication>
#include <QMessageBox>
#include <QMouseEvent>
#include <QDebug>
#include <QDesktopWidget>
#include <QTimer>
#include <math.h>
#include <QSound>

#define CHESS_ONE_SOUND ":/sound/chessone.wav"
#define WIN_SOUND ":/sound/win.wav"
#define LOSE_SOUND ":/res/sound/lose.wav"
const int kBoardMargin = 70; // 棋盘边缘
const int kRadius = 15; // 棋子半径
const int kMarkSize = 15; // 落子标记边长
const int kBlockSize = 40; // 格子大小
const int kPosDelta = 15;
const int kAIDelay = 700; // AI下棋时间

wuziqiGame::wuziqiGame(QWidget *parent) : QMainWindow(parent)
{

    // 棋盘大小
    int width = kBoardMargin*2 + kBlockSize*kBoardSizeNum;
    int height = kBoardMargin*2 + kBlockSize*kBoardSizeNum;
    setFixedSize(width, height);

    QDesktopWidget *desktop = QApplication::desktop();
    move((desktop->width() - width) / 2, (desktop->height() - height) /2);

    // 窗口标题
    this->setWindowTitle("五子棋");

    // 开启鼠标hover功能
    setMouseTracking(true);

    // 添加菜单
    QMenuBar *bar = menuBar();
    setMenuBar(bar);
    QMenu *gameMenu = bar->addMenu("Game");
    QAction *actionPVP = new QAction("双人对战", this);
    gameMenu->addAction(actionPVP);
    QAction *actionPVG = new QAction("人机对战", this);
    gameMenu->addAction(actionPVG);

    // 连接槽函数
    connect(actionPVP, &QAction::triggered, this, &wuziqiGame::initPVPGame);
    connect(actionPVG, &QAction::triggered, this, &wuziqiGame::initPVEGame);

//    for (int i = 0; i < 4; ++i) {
//        qDebug() << d[i][0] << d[i][1] << endl;
//    }
    initGame(); // 开始游戏
}

wuziqiGame::~wuziqiGame(){
    if (game) {
        delete game;
        game = nullptr;
    }
}

void wuziqiGame::initGame() {
    game = new GameModel;
    // 默认人机
    initPVEGame();
}

void wuziqiGame::initPVPGame(){
    qDebug() << "双人对战" << endl;
    game_type = PERSON;
    game->gameStatus = PLAY;
    game->startGame(game_type);
    game->lastRow = game->lastCol = -1;
    update();
}

void wuziqiGame::initPVEGame() {
    qDebug() << "人机对战" << endl;
    game_type = BOT;
    game->gameStatus = PLAY;
    game->startGame(game_type);
    game->lastRow = game->lastCol = -1;
    update();
}

void wuziqiGame::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    // 抗锯齿 防走样
    painter.setRenderHint(QPainter::Antialiasing, true);
    // 画棋盘
    for (int i = 0; i < kBoardSizeNum+1; ++i) {
        int x1 = kBoardMargin + kBlockSize * i;
        int y1 = kBoardMargin;
        int x2 = kBoardMargin + kBlockSize * i;
        int y2 = size().height() - kBoardMargin;
        painter.drawLine(x1, y1, x2, y2);
        painter.drawLine(y1, x1, y2, x2);
    }
    // 画刷, 用于填充
    QBrush brush;
    // 设置为统一的颜色
    brush.setStyle(Qt::SolidPattern);

    // qDebug() << "update" << clickPosRow << " " << clickPosCol << endl;
    // 绘制落子
    if (clickPosRow >= 0 && clickPosRow <= kBoardSizeNum &&
            clickPosCol >= 0 && clickPosCol <= kBoardSizeNum &&
            game->gameMapVec[clickPosRow][clickPosCol] == 0) {
        if (game->playerFlag) brush.setColor(Qt::white);
        else brush.setColor(Qt::black);
        painter.setBrush(brush);
        int x = kBoardMargin + kBlockSize * clickPosCol - kMarkSize / 2;
        int y = kBoardMargin + kBlockSize * clickPosRow - kMarkSize / 2;
//        painter.drawRect(x, y, kMarkSize, kMarkSize);
        painter.drawEllipse(x, y, kMarkSize, kMarkSize);
    }

    // 绘制棋子
    for (int i = 0; i <= kBoardSizeNum; ++i) {
        for (int j = 0; j <= kBoardSizeNum; ++j) {
            if (game->gameMapVec[i][j] == 0) continue;
            if (game->gameMapVec[i][j] == 1) brush.setColor(Qt::white);
            else brush.setColor(Qt::black);
            painter.setBrush(brush);
            painter.drawEllipse(kBoardMargin + kBlockSize*j - kRadius,
                                kBoardMargin + kBlockSize*i - kRadius,
                                kRadius*2, kRadius*2);
        }
    }
    if (game->lastRow != -1 && game->lastCol != -1) {
        brush.setColor(Qt::red);
        painter.setBrush(brush);
        painter.drawEllipse(kBoardMargin + kBlockSize*game->lastCol,
                            kBoardMargin + kBlockSize*game->lastRow,
                            4, 4);
    }
    // 判断输赢
    if (clickPosRow >= 0 && clickPosRow <= kBoardSizeNum &&
            clickPosCol >= 0 && clickPosCol <= kBoardSizeNum &&
            game->gameMapVec[clickPosRow][clickPosCol] != 0 && game->gameStatus == PLAY) {
        // 判断输赢
        if (game->isWin(clickPosRow, clickPosCol)) {
            qDebug() << "win";
//            update();
            game->gameStatus = WIN;
            QSound::play(WIN_SOUND);
            QString str = "白棋";
            if (game->gameMapVec[clickPosRow][clickPosCol] == -1) str = "黑棋";
            QMessageBox::StandardButton btnValue;
            if (game->gameType == PERSON) {
                btnValue = QMessageBox::information(this, "恭喜", str+"赢了!");
                game->gameStatus = WIN;
            }else {
                if (str == "黑棋") {
                    btnValue = QMessageBox::information(this, "糟糕", "你输了!");
                    game->gameStatus = LOSE;
                }else {
                    btnValue = QMessageBox::information(this, "恭喜", "你赢了!");
                    game->gameStatus = WIN;
                }
            }
            if (btnValue == QMessageBox::Ok) {
                game->startGame((game_type));
                game->gameStatus = PLAY;
            }
            game->lastRow = game->lastCol = -1;
        }
        if (game->isDeadGame()) {
            game->gameStatus = DEAD;
            QSound::play(LOSE_SOUND);
            QMessageBox::StandardButton btnValue = QMessageBox::information(this, "糟糕", "和棋!");
            if (btnValue == QMessageBox::Ok) {
                game->startGame(game_type);
                game->gameStatus = PLAY;
            }
        }
    }
}

void wuziqiGame::mouseMoveEvent(QMouseEvent *event) {
    int x = event->x();
    int y = event->y();
//    qDebug() << x << " -- " << y << endl;
    if (x >= kBlockSize && x <= size().width() - kBlockSize &&
            y >= kBlockSize && y <= size().height() - kBlockSize) {
        int col = (x - kBoardMargin) / kBlockSize;
        int row = (y - kBoardMargin) / kBlockSize;
        int Lx = kBoardMargin + kBlockSize * col;
        int Ly = kBoardMargin + kBlockSize * row;
        clickPosRow = clickPosCol = -1;
       double tmp = 100000, len;
       // 左上
       len = sqrt((x-Lx) * (x-Lx) + (y-Ly) * (y-Ly));
       if (len < tmp) clickPosRow = row, clickPosCol = col, tmp = len;
       // 右上
       len = sqrt((x-Lx-kBlockSize) * (x-Lx-kBlockSize) + (y-Ly) * (y-Ly));
       if (len < tmp) clickPosRow = row, clickPosCol = col+1, tmp = len;
       // 左下
       len = sqrt((x-Lx) * (x-Lx) + (y-Ly-kBlockSize) * (y-Ly-kBlockSize));
       if (len < tmp) clickPosRow = row+1, clickPosCol = col, tmp = len;
       // 右下
       len = sqrt((x-Lx-kBlockSize) * (x-Lx-kBlockSize) + (y-Ly) * (y-Ly));
       if (len < tmp) clickPosRow = row+1, clickPosCol = col+1, tmp = len;


    }
    // 重绘
    update();
    // qDebug() << clickPosRow << " " << clickPosCol << endl;
}

void wuziqiGame::mouseReleaseEvent(QMouseEvent *event) {
    qDebug() << "Release!! " << game_type << " " << game->playerFlag << endl;
    // 人下棋
    if (!(game_type == BOT && game->playerFlag == 0)) {
        chessOneByPerson();
        if (game->gameType == BOT && game->playerFlag == 0) {
            QTimer::singleShot(kAIDelay, this, SLOT(sleepAI()));
//            QTimer::singleShot(kAIDelay, this, SLOT(chessOneByAI()));
        }
    }
}

void wuziqiGame::chessOneByPerson(){
    // qDebug() << "now:" << clickPosRow << " " << clickPosCol << " " << game->gameMapVec[clickPosRow][clickPosCol] << endl;
    if (clickPosRow != -1 && clickPosCol != -1 &&
            game->gameMapVec[clickPosRow][clickPosCol] == 0) {
//        qDebug() << "chessOneByPerson " << clickPosRow << " " << clickPosCol << endl;
        game->actionByPerson(clickPosRow, clickPosCol);
        QSound::play(CHESS_ONE_SOUND);
        update();
    }
}

void wuziqiGame::chessOneByAI(){
    qDebug() << "chessOneByAI" << endl;
    game->actionByAI(clickPosRow, clickPosCol);
    QSound::play(CHESS_ONE_SOUND);
    update();
}


void wuziqiGame::wuziqiShow() {
    this->show();
}

void wuziqiGame::wuziqiHidden() {
    this->hide();
}

void wuziqiGame::sleepAI()
{
    chessOneByAI();
}

void wuziqiGame::closeEvent(QCloseEvent *event) {
    wuziqiOut();
}
