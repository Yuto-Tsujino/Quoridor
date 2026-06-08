#include "TITLE.h"
#include "GAME.h"
#include "CONTAINER.h"
#include "libOne.h"

TITLE::TITLE(class GAME* game):
	SCENE(game){
}
TITLE::~TITLE(){}
void TITLE::create(){
	Title = game()->container()->title();
}
void TITLE::draw(){
	clear(Title.backColor);
	fill(Title.textColor);
	textSize(Title.textSize);
	text(Title.str, Title.pos.x, Title.pos.y);
}
void TITLE::nextScene(){
	if (isTrigger(KEY_SPACE)) {
		game()->changeScene(GAME::STAGE_ID);
	}
}