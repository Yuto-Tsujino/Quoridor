#include "GAME_OVER.h"
#include "GAME.h"
#include "CONTAINER.h"
#include "libOne.h"

GAME_OVER::GAME_OVER(class GAME* game) :
	SCENE(game) {
}
GAME_OVER::~GAME_OVER() {}
void GAME_OVER::create() {
	GameOver = game()->container()->gameOver();
}
void GAME_OVER::draw() {
	clear(GameOver.backColor);
	game()->tiles()->draw();
	game()->player1()->draw();
	game()->player2()->draw();
	game()->walls()->draw();
	game()->turnManager()->draw();
	word(GameOver.str, GameOver.pos.x, GameOver.pos.y, GameOver.textSize, GameOver.textColor);
}

void GAME_OVER::nextScene() {
	if (isTrigger(KEY_Z)) {
		game()->changeScene(GAME::STAGE_ID);
	}
}