#pragma once
#include "GAME_OBJECT.h"
class TURN_MANAGER :
    public GAME_OBJECT
{
public:
    enum MODE {
        MOVE_PAWN,
        PLACE_WALL
    };

    enum PLAYER {
        PLAYER1_TURN,
        PLAYER2_TURN
    };
private:
    PLAYER currentPlayer = PLAYER1_TURN;
    MODE currentMode = MOVE_PAWN;
    int p1Walls = 10;
    int p2Walls = 10;
    int winner = 0;
public:
    TURN_MANAGER(class GAME* game);
    ~TURN_MANAGER();
    void init();
    void update();
    void changeTurn();
    void changeMode();
    int checkWinCondition();
    void draw();
    PLAYER player() const { return currentPlayer; }
    MODE mode() const { return currentMode; }

    int getWinner() const { return winner; }

    /*int remainingWalls(PLAYER p)const {
        return (p == PLAYER1_TURN ? p1Walls : p2Walls);
    }*/
};

