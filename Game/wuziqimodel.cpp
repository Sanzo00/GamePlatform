#include "wuziqimodel.h"
#include <time.h>
#include <stdlib.h>
#include <QDebug>
GameModel::GameModel()
{

}

void GameModel::startGame(GameType type) {
    gameType = type;
    // 初始化棋盘
    gameMapVec.clear();
    for (int i = 0; i <= kBoardSizeNum; ++i) {
        std::vector<int> lineVec;
        for (int j = 0; j <= kBoardSizeNum; ++j) {
            lineVec.push_back(0);
        }
        gameMapVec.push_back(lineVec);
    }

    // AI模式:初始化评分数组
    if (gameType == BOT) {
        scoreMapVec.clear();
        for (int i = 0; i <= kBoardSizeNum; ++i) {
            std::vector<int> lineVec;
            for (int j = 0; j <= kBoardSizeNum; ++j) {
                lineVec.push_back(j);
            }
            scoreMapVec.push_back(lineVec);
        }
    }

    // 对方执棋 false, 自己执棋 true
    playerFlag = true;
}

// 更新落子
void GameModel::updateGameMap(int row, int col) {
    lastRow = row;
    lastCol = col;
//    qDebug() << "updateGameMap " << row << " " << col << endl;
    if (playerFlag) {
        gameMapVec[row][col] = 1;
    }else {
        gameMapVec[row][col] = -1;
    }
    playerFlag ^= 1;
}

void GameModel::actionByPerson(int row, int col) {
//    qDebug() << "actionByPerson " << row << " " << col << endl;
    updateGameMap(row, col);
}

void GameModel::actionByAI(int &row, int &col) {
    // 计算落点的得分
    calculateScore();

    // 找得分最大的位置
    int maxScore = 0;
    std::vector<std::pair<int, int> > maxPoints;
    for (int i = 0; i <= kBoardSizeNum; ++i) {
        for (int j = 0; j <= kBoardSizeNum; ++j) {
            if (gameMapVec[i][j] != 0) continue;
            if (scoreMapVec[i][j] > maxScore) {
                maxPoints.clear();
                maxScore = scoreMapVec[i][j];
                maxPoints.push_back(std::make_pair(i, j));
            } else if (scoreMapVec[i][j] == maxScore) {
                maxPoints.push_back(std::make_pair(i, j));
            }
        }
    }
    qDebug() << "maxScore: " << maxScore << endl;
    // 多个位置得分相同, 随机一个位置
    srand((unsigned)time(0));
    int idx = rand() % maxPoints.size();
    std::pair<int, int> pointPair = maxPoints.at(idx);
    row = pointPair.first;
    col = pointPair.second;
    updateGameMap(row, col);
}

void GameModel::calculateScore() {
    int personNum = 0; // PERSON在同一个方向连接的棋子个数
    int botNum = 0; // BOT在同一方向连接的棋子个数
    int emptyNum = 0; // 遇到空白停止

    // 初始化计分数组
    scoreMapVec.clear();
    for (int i = 0; i <= kBoardSizeNum; ++i) {
        std::vector<int> lineScores;
        for (int j = 0; j <= kBoardSizeNum; ++j) {
            lineScores.push_back(0);
        }
        scoreMapVec.push_back(lineScores);
    }

    // 计分 暴力统计

    for (int i = 0; i <= kBoardSizeNum; ++i) {
        for (int j = 0; j <= kBoardSizeNum; ++j) {
            if (gameMapVec[i][j] != 0) continue;
            for (int k = 0; k < 4; ++k) { // 4个方向
                // 当前落子对PERSON的贡献
                personNum = botNum = emptyNum = 0;
                sumChessNum(i, j, d[k][0], d[k][1], 1, personNum, emptyNum);
                sumChessNum(i, j, -d[k][0], -d[k][1], 1, personNum, emptyNum);
                if (personNum == 1) { // 1
                    scoreMapVec[i][j] += 10;
                }else if (personNum == 2) { // 2
                    if (emptyNum == 1) scoreMapVec[i][j] += 30;
                    else if (emptyNum == 2) scoreMapVec[i][j] += 40;
                }else if (personNum == 3) { // 3
                    if (emptyNum == 1) scoreMapVec[i][j] += 60;
                    else if (emptyNum == 2) scoreMapVec[i][j] += 110;
                }else if (personNum == 4) { // 4
                    scoreMapVec[i][j] += 10100;
                }
                // 当前落子对BOT的贡献
                emptyNum = 0;
                sumChessNum(i, j, d[k][0], d[k][1], -1, botNum, emptyNum);
                sumChessNum(i, j, -d[k][0], -d[k][1], -1, botNum, emptyNum);
                if (botNum == 0) { // 0
                    scoreMapVec[i][j] += 5;
                }else if (botNum == 1) { // 1
                    scoreMapVec[i][j] += 10;
                }else if (botNum == 2) { // 2
                     if (emptyNum == 1) scoreMapVec[i][j] += 25;
                     else if (emptyNum == 2) scoreMapVec[i][j] += 50;
                }else if (botNum == 3) { // 3
                    if (emptyNum == 1) scoreMapVec[i][j] += 55;
                    else if (emptyNum == 2) scoreMapVec[i][j] += 100;
                }else if (botNum == 4) {
                    scoreMapVec[i][j] += 10000;
                }
            }
        }
    }
}

void GameModel::sumChessNum(int x, int y, int dx, int dy, int type,
                            int &num, int &emptyNum) {
    for (int i = 1; i <= 4; ++i) {
        int nx = x + dx*i;
        int ny = y + dy*i;
        if (nx < 0 || ny < 0 || nx > kBoardSizeNum || ny > kBoardSizeNum) return;
        if (gameMapVec[nx][ny] == type) num++;
        else {
            if (gameMapVec[nx][ny] == 0) emptyNum++;
            return;
        }
    }
}

int GameModel::sumChessNum(int x, int y, int dx, int dy, int type) {
    int cnt = 0;
    if (type == 0) return cnt;
    for (int i = 1; i <= 4; ++i) {
        int nx = x + dx*i;
        int ny = y + dy*i;
        if (nx < 0 || ny < 0 || nx > kBoardSizeNum || ny > kBoardSizeNum || gameMapVec[nx][ny] != type) break;
        cnt++;
    }
    return cnt;
}

// 判断当前落子输赢
bool GameModel::isWin(int x, int y) {
    bool flag = 0;
    for (int k = 0; k < 4; ++k) {

        int cnt = 1;
        cnt += sumChessNum(x, y, d[k][0], d[k][1], gameMapVec[x][y]);
       // qDebug() << x << " " << y << " -> " << d[k][0] << " " << d[k][1] << " " << cnt << endl;
        cnt += sumChessNum(x, y, -d[k][0], -d[k][1], gameMapVec[x][y]);
        // qDebug() << x << " " << y << " -> " << -d[k][0] << " " << -d[k][1] << " " << cnt << endl;
        if (cnt >= 5) {
            flag = 1;
            break;
        }

    }
    return flag;
}

// 判断是否和棋
bool GameModel::isDeadGame() {
    bool flag = true;
    for (int i = 0; i <= kBoardSizeNum; ++i) {
        for (int j = 0; j <= kBoardSizeNum; ++j) {
            if (gameMapVec[i][j] == 0) return false;
        }
    }
    return flag;
}
















































































