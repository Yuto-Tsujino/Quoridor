#include "GAME.h"
#include "libOne.h"
#include "CONTAINER.h"


GAME::GAME(){
    Container = new CONTAINER;
    Scenes[TITLE_ID] = new TITLE(this);
    Scenes[STAGE_ID] = new STAGE(this);
    Scenes[GAME_CLEAR_ID] = new GAME_CLEAR(this);
    Scenes[GAME_OVER_ID] = new GAME_OVER(this);
    CurSceneId = TITLE_ID;

    Tiles = new TILES(this);

    Walls = new WALLS(this);
    
    Player1 = new PLAYER1(this);
    Player2 = new PLAYER2(this);

    
    TurnManager = new TURN_MANAGER(this);
}
GAME::~GAME(){
    delete TurnManager;
    delete Player2;
    delete Player1;
    delete Walls;
    delete Tiles;
    for (int i = 0; i < NUM_SCENES; i++) {
        delete Scenes[i];
    }
    delete Container;
}

void GAME::run() {
    window(1920, 1080, full);
    hideCursor();
    Container->load();
    create();
    Scenes[CurSceneId]->init();
   
    initDeltaTime();
    while (notQuit) {
        setDeltaTime();
        Scenes[CurSceneId]->proc();
    }
}

void GAME::changeScene(SCENE_ID sceneId){
    CurSceneId = sceneId;
    Scenes[CurSceneId]->init();
}
void GAME::create(){
    for (int i = 0; i < NUM_SCENES; i++) {
        Scenes[i]->create();
    }
    Tiles->create();
    Walls->create();
    Player1->create();
    Player2->create();
}
