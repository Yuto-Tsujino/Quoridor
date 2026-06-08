#pragma once
#include "SCENE.h"
#include "libOne.h"

class GAME_CLEAR :
    public SCENE
{
public:
    struct DATA {
        COLOR backColor;
        COLOR textColor;
        float textSize;
        VECTOR2 pos;
        char str[16];
    };
private:
    DATA GameClear;
public:
    GAME_CLEAR(class GAME* game);
    ~GAME_CLEAR();
    void create();
    void draw();
    void nextScene();
};

