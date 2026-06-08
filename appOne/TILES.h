#pragma once
#include "GAME_OBJECT.h"
#include "libOne.h"

class TILES :
    public GAME_OBJECT
{
public:
    struct DATA {
        COLOR tileColor;
        COLOR baseColor;
        float tileLength;
        float distance;
        int num;
    };
private:
    // 共通データ
    DATA Tile;
    struct TILE {
        VECTOR2 pos;
    };
    TILE* Tiles;
public:
    TILES(class GAME* game);
    ~TILES();
    void create();
    void init();
    void draw();
    VECTOR2 pos(int i) { return Tiles[i].pos; }
    int num() { return Tile.num; }
    float distance() { return Tile.distance; }
    float tileLength() { return Tile.tileLength; }
};

