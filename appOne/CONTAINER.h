#pragma once
#include "TITLE.h"
#include "STAGE.h"
#include "GAME_CLEAR.h"
#include "GAME_OVER.h"
#include "TILES.h"
#include "WALLS.h"
#include "PLAYER1.h"
#include "PLAYER2.h"
#include "TURN_MANAGER.h"

class CONTAINER
{
	struct DATA {
		// Scenes
		TITLE::DATA title;
		STAGE::DATA stage;
		GAME_CLEAR::DATA gameClear;
		GAME_OVER::DATA gameOver;

		// Character
		TILES::DATA tile;

		WALLS::DATA walls;

		PLAYER1::DATA player1;
		PLAYER2::DATA player2;

	};

	DATA Data;
public:
	void load();
	void setData();
	void loadGraphic();
	const TITLE::DATA& title() { return Data.title; }
	const STAGE::DATA& stage() { return Data.stage; }
	const GAME_CLEAR::DATA& gameClear() { return Data.gameClear; }
	const GAME_OVER::DATA& gameOver() { return Data.gameOver; }
	const TILES::DATA& tile() { return Data.tile; }
	const WALLS::DATA& walls() { return Data.walls; }
	const PLAYER1::DATA& player1() { return Data.player1; }
	const PLAYER2::DATA& player2() { return Data.player2; }
};

