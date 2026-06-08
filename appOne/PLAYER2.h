#pragma once
#include "GAME_OBJECT.h"
#include "libOne.h"
class PLAYER2 :
    public GAME_OBJECT
{
public:
    struct DATA {
        COLOR color;
        VECTOR2 pos;
        int curIdx;
        int idx;
        float radius;
        bool hasMoved;
    };
private:
    DATA Player2;
public:
    PLAYER2(class GAME* game);
    ~PLAYER2();
    void create();
    void init();
    void startTurn();
    void update();
    void move();
    void draw();
    int curIdx() { return Player2.idx; }
    bool hasMoved() { return Player2.hasMoved; }
};

