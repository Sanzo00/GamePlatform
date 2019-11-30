#ifndef WUZIQIGAMEMODEL_H
#define WUZIQIGAMEMODEL_H
#include <vector>
// 双人 or AI
enum GameType{
    PERSON,
    BOT
};

// 游戏状态
enum GameStatus{
    PLAY,
    WIN,
    LOSE,
    DEAD
};

// 棋盘大小
const int kBoardSizeNum = 15;
const int d[4][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, 1}};
class GameModel
{

public:
    GameModel();

    bool playerFlag;
    GameType gameType;
    GameStatus gameStatus;
    std::vector<std::vector<int> > gameMapVec;
    std::vector<std::vector<int> > scoreMapVec;
    void startGame(GameType type);
    void calculateScore();
    void actionByPerson(int row, int col);
    void actionByAI(int &clickRow, int &clickCol);
    void updateGameMap(int row, int col);
    bool isWin(int row, int col);
    bool isDeadGame();
    bool checkPos(int row, int col);
    void sumChessNum(int x, int y, int dx, int dy, int type,
                    int &num, int &emptyNum);
    int sumChessNum(int x, int y, int dx, int dy, int type);
    int lastRow, lastCol;

};

#endif // WUZIQIGAMEMODEL_H
