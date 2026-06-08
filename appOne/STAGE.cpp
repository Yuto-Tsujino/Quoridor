#include "STAGE.h"
#include "GAME.h"
#include "CONTAINER.h"
#include "libOne.h"
#include "TILES.h"
#include "PLAYER1.h"
#include "PLAYER2.h"
#include "TURN_MANAGER.h"

STAGE::STAGE(class GAME* game) :
	SCENE(game) {
}
STAGE::~STAGE() {}
void STAGE::create() {
	Stage = game()->container()->stage();
}
void STAGE::init() {
	game()->tiles()->init();
	game()->player1()->init();
	game()->player2()->init();
	game()->walls()->init();
	game()->turnManager()->init();
	Stage.backColor = COLOR(random(0, 200), random(0, 200), random(0, 200));
}
void STAGE::update(){
	//game()->player1()->update();
	//game()->player2()->update();
	
	game()->turnManager()->update();
}
void STAGE::draw() {
	clear(Stage.backColor);
	game()->tiles()->draw();
	game()->player1()->draw();
	game()->player2()->draw();
	game()->walls()->draw();
	game()->turnManager()->draw();
}
void STAGE::nextScene() {
	int winner = game()->turnManager()->getWinner();
	if (winner != 0) {
		if (winner == 1) {
			game()->changeScene(GAME::GAME_CLEAR_ID);
		}
		else if (winner == 2) {
			game()->changeScene(GAME::GAME_OVER_ID);
		}
	}
}