#include "PLAYER2.h"
#include "GAME.h"
#include "CONTAINER.h"
#include "TILES.h"

PLAYER2::PLAYER2(class GAME* game) :
	GAME_OBJECT(game) {}
PLAYER2::~PLAYER2() {}
void PLAYER2::create() {
	Player2 = game()->container()->player2();
}
void PLAYER2::init() {
	Player2.idx = game()->container()->player2().idx;
	Player2.pos = game()->tiles()->pos(Player2.idx);
}
void PLAYER2::startTurn() {
	Player2.curIdx = Player2.idx;
	Player2.hasMoved = false;
}
void PLAYER2::update() {
	move();
}

void PLAYER2::move() {
	int player1CurIdx = game()->player1()->curIdx();
	if (isTrigger(KEY_RIGHT)) {
		if (Player2.idx % 9 < 8) {
			int nextIdx = Player2.idx + 1;
			if (game()->walls()->isPathBlocked(Player2.idx, nextIdx) == false) {
				if (!Player2.hasMoved) {
					if (player1CurIdx - Player2.idx == 1) {
						Player2.idx += 2;
					}
					else { Player2.idx += 1; }
				}
				else if (Player2.hasMoved) {
					if (Player2.curIdx - Player2.idx == 1) {
						Player2.idx += 1;
					}
					if (Player2.curIdx - Player2.idx == 2) {
						Player2.idx += 2;
					}
				}
			}
		}
	}
	else if (isTrigger(KEY_LEFT)) {
		if (Player2.idx % 9 > 0) {
			int nextIdx = Player2.idx - 1;
			if (game()->walls()->isPathBlocked(Player2.idx, nextIdx) == false) {
				if (!Player2.hasMoved) {
					if (Player2.idx - player1CurIdx == 1) {
						Player2.idx -= 2;
					}
					else { Player2.idx -= 1; }
				}
				else if (Player2.hasMoved) {
					if (Player2.idx - Player2.curIdx == 1) {
						Player2.idx -= 1;
					}
					if (Player2.idx - Player2.curIdx == 2) {
						Player2.idx -= 2;
					}
				}
			}
		}
	}
	else if (isTrigger(KEY_UP)) {
		if (Player2.idx >= 9) {
			int nextIdx = Player2.idx - 9;
			if (game()->walls()->isPathBlocked(Player2.idx, nextIdx) == false) {
				if (!Player2.hasMoved) {
					if (Player2.idx - player1CurIdx == 9) {
						if (player1CurIdx > 9) {
							Player2.idx -= 18;
						}
						else { Player2.idx; }
					}
					else { Player2.idx -= 9; }
				}
				else if (Player2.hasMoved) {
					if (Player2.idx - Player2.curIdx == 9) {
						Player2.idx -= 9;
					}
					if (Player2.idx - Player2.curIdx == 18) {
						Player2.idx -= 18;
					}
				}
			}
		}
	}
	else if (isTrigger(KEY_DOWN)) {
		if (Player2.idx <= 71) {
			int nextIdx = Player2.idx + 9;
			if (game()->walls()->isPathBlocked(Player2.idx, nextIdx) == false) {
				if (!Player2.hasMoved) {
					if (player1CurIdx - Player2.idx == 9) {
						if (player1CurIdx <= 71) {
							Player2.idx += 18;
						}
						else { Player2.idx; }
					}
					else { Player2.idx += 9; }
				}
				else if (Player2.hasMoved) {
					if (Player2.curIdx - Player2.idx == 9) {
						Player2.idx += 9;
					}
					if (Player2.curIdx - Player2.idx == 18) {
						Player2.idx += 18;
					}
				}
			}
		}
	}
	Player2.pos = game()->tiles()->pos(Player2.idx);
	Player2.hasMoved = ( Player2.idx != Player2.curIdx );
}
void PLAYER2::draw() {
	fill(Player2.color);
	circle(Player2.pos.x, Player2.pos.y, Player2.radius);
}