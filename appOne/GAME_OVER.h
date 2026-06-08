#pragma once
#include "SCENE.h"
#include "libOne.h"

class GAME_OVER :
    public SCENE
{
public:
    struct DATA {
        COLOR backColor;
        COLOR textColor;
        float textSize;
        VECTOR2 pos;
        char str[16];
        char str2[32];
    };
private:
    DATA GameOver;
public:
    GAME_OVER(class GAME* game);
    ~GAME_OVER();
    void create();
    void draw();
    void nextScene();
};

