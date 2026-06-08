#include "SCENE.h"
#include "GAME.h"
#include "libOne.h"

SCENE::SCENE(class GAME* game):
	GAME_OBJECT(game){
}
SCENE::~SCENE(){}
void SCENE::create(){}
void SCENE::init(){}
void SCENE::proc(){
	update();
	draw();
	nextScene();
}
void SCENE::update(){}
void SCENE::draw(){}
void SCENE::nextScene(){}


void SCENE::word(const char* str, float x, float y, float size, COLOR color) {
	fill(color);
	textSize(size);
	text(str, x, y);
}
