#pragma once
#include "GAME_OBJECT.h"
#include "libOne.h"
class SCENE :
    public GAME_OBJECT
{
public:
    SCENE(class GAME* game);
    virtual ~SCENE();
    virtual void create();
    virtual void init();
    virtual void proc();
    virtual void update();
    virtual void draw();
    virtual void nextScene();


    virtual void word(const char* str, float x, float y, float textSize, COLOR color);
};

