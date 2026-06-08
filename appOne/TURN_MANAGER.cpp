#include "TURN_MANAGER.h"
#include "GAME.h"
#include "libOne.h"
#include "PLAYER1.h"
#include "PLAYER2.h"
#include "WALLS.h"

TURN_MANAGER::TURN_MANAGER(class GAME* game) :
	GAME_OBJECT(game) {}
TURN_MANAGER::~TURN_MANAGER(){}

void TURN_MANAGER::init(){
	currentPlayer = PLAYER1_TURN;
	currentMode = MOVE_PAWN;
	p1Walls = 10;
	p2Walls = 10;
	winner = 0;

	game()->player1()->startTurn();
	game()->player2()->startTurn();

}

void TURN_MANAGER::update(){
	changeMode();
	if (currentPlayer == PLAYER1_TURN) {
		if (currentMode == MOVE_PAWN) {
			if (isTrigger(KEY_ENTER)) {
				if (game()->player1()->hasMoved()) {
					changeTurn();
				}
			}
			else{
				game()->player1()->move();
			}
		}
		else if (currentMode == PLACE_WALL && p1Walls > 0) {
			if (isTrigger(KEY_ENTER)) {
				if (game()->walls()->placeWall(1)) {
					p1Walls--;
					changeTurn();
				}
			}
			else { game()->walls()->move(); }
		}
	}
	else if (currentPlayer == PLAYER2_TURN) {
		if (currentMode == MOVE_PAWN) {
			if (isTrigger(KEY_ENTER)) {
				if(game()->player2()->hasMoved())
				changeTurn();
			}
			else {
				game()->player2()->move();
			}
		}
		else if (currentMode == PLACE_WALL && p2Walls >0) {
			if (isTrigger(KEY_ENTER)) {
				if (game()->walls()->placeWall(2)) {
					p2Walls--;
					changeTurn();
				}
			}
			else { game()->walls()->move(); }
		}
	}

	checkWinCondition();
}
void TURN_MANAGER::changeTurn(){
	if (currentPlayer == PLAYER1_TURN) {
		currentPlayer = PLAYER2_TURN;
		game()->player2()->startTurn();
	}
	else if(currentPlayer == PLAYER2_TURN){
		currentPlayer = PLAYER1_TURN;
		game()->player1()->startTurn();
	}
	
	currentMode = MOVE_PAWN;
}

void TURN_MANAGER::changeMode() {
	if (currentPlayer == PLAYER1_TURN && game()->player1()->hasMoved()) return;
	if (currentPlayer == PLAYER2_TURN && game()->player2()->hasMoved()) return;
	if (isTrigger(KEY_SPACE)) {
		int& curNum = game()->walls()->curNum();
		if (currentMode == MOVE_PAWN) {
			currentMode = PLACE_WALL;
		}
		else {
			currentMode = MOVE_PAWN;
		}
	}
}

int TURN_MANAGER::checkWinCondition() {
	if (game()->player1()->curIdx() % 9 == 8) {
		winner = 1;
	}
	else if(game()->player2()->curIdx() % 9 == 0){
		winner = 2;
	}
	return winner;
}

void TURN_MANAGER::draw() {
	textSize(80);
	const char* playerText;
	int wallNum;
	float textPos = 20;
	if (currentPlayer == PLAYER1_TURN) { 
		fill(255, 0, 0);
		playerText = "Player1";
		wallNum = p1Walls;
		textPos = 20;
	}
	else { 
		fill(255);
		playerText = "Player2"; 
		wallNum = p2Walls;
		textPos = width - 400;
	}
	text(playerText, textPos, 80);
	const char* modeText;
	if (mode() == MOVE_PAWN) { modeText = "MOVE"; }
	else {
		fill(255, 255, 0);
		modeText = "PLACE WALL"; 
		text(wallNum, textPos, 240);
	}
	text(modeText, textPos, 160);
}