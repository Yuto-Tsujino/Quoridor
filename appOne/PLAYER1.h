#pragma once
#include "GAME_OBJECT.h"
#include "libOne.h"
class PLAYER1 :
    public GAME_OBJECT
{
public:
    struct DATA{
        COLOR color;
        VECTOR2 pos;
        int idx;
        int curIdx;
        float radius;
        bool hasMoved;
    };
private:
    DATA Player1;
public:
    PLAYER1(class GAME* game);
    ~PLAYER1();
    void create();
    void init();
    void startTurn();
    void update();
        void move();
        int calcNextIdx(int p1, int p2, int dx, int dy, int allowReturnIdx);
    void draw();
    int curIdx() { return Player1.idx; }
    bool hasMoved() { return Player1.hasMoved; }
};

