#pragma once
#include "GAME_OBJECT.h"
#include "libOne.h"

class WALLS :
    public GAME_OBJECT
{public:
    struct DATA{
        COLOR curColor;
        COLOR normalColor;
        int curNum;
        int totalNum;
    };
private:
    DATA Wall;
    struct WALL {
        VECTOR2 pos;
        int idx;
        int angle;
        bool isPlaced = false;
        int owner = 0;
    };
    WALL* Walls;
public:
    WALLS(class GAME* game);
    ~WALLS();
    void create();
    void init();
    void update();
    void move();
    bool canPlaceWall(int idx, int angle);
    bool placeWall(int playerId);
    bool isPathBlocked(int startTileIdx, int endTileIdx);
    VECTOR2 wallPos(int idx);
    void draw();
    int& curNum() { return Wall.curNum; }
    void setCurNum(int n) { Wall.curNum = n; }
};

