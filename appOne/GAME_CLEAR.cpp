#include "GAME_CLEAR.h"
#include "GAME.h"
#include "CONTAINER.h"
#include "libOne.h"

GAME_CLEAR::GAME_CLEAR(class GAME* game) :
	SCENE(game) {
}
GAME_CLEAR::~GAME_CLEAR() {}
void GAME_CLEAR::create() {
	GameClear = game()->container()->gameClear();
}
void GAME_CLEAR::draw() {
	clear(GameClear.backColor);
	game()->tiles()->draw();
	game()->player1()->draw();
	game()->player2()->draw();
	game()->walls()->draw();
	game()->turnManager()->draw();
	word(GameClear.str, GameClear.pos.x, GameClear.pos.y, GameClear.textSize, GameClear.textColor);
}

void GAME_CLEAR::nextScene() {
	if (isTrigger(KEY_Z)) {
		game()->changeScene(GAME::STAGE_ID);
	}
}