#include "PLAYER1.h"
#include "GAME.h"
#include "CONTAINER.h"
#include "TILES.h"
#include "PLAYER2.h"

PLAYER1::PLAYER1(class GAME* game):
	GAME_OBJECT(game){}
PLAYER1::~PLAYER1(){}
void PLAYER1::create(){
	Player1 = game()->container()->player1();
}
void PLAYER1::init(){
	Player1.idx = game()->container()->player1().idx;
	Player1.pos = game()->tiles()->pos(Player1.idx);
}
void PLAYER1::update(){
	move();
}
void PLAYER1::startTurn() {
	Player1.curIdx = Player1.idx;
	Player1.hasMoved = false;
}
//void PLAYER1::move(){
//	int player2CurIdx = game()->player2()->curIdx();
//	if (isTrigger(KEY_RIGHT)) {
//		if (Player1.idx % 9 < 8) {
//			int nextIdx = Player1.idx + 1;
//			if (game()->walls()->isPathBlocked(Player1.idx, nextIdx) == false) {
//				if (!Player1.hasMoved) {
//					if (player2CurIdx - Player1.idx == 1) {
//						Player1.idx += 2;
//					}
//					else { Player1.idx += 1; }
//				}
//				else if (Player1.hasMoved) {
//					if (Player1.curIdx - Player1.idx == 1) {
//						Player1.idx += 1;
//					}
//					if (Player1.curIdx - Player1.idx == 2) {
//						Player1.idx += 2;
//					}
//				}
//			}
//		}
//	}
//	else if (isTrigger(KEY_LEFT)) {
//		if (Player1.idx % 9 > 0) {
//			int nextIdx = Player1.idx - 1;
//			if (game()->walls()->isPathBlocked(Player1.idx, nextIdx) == false) {
//				if (!Player1.hasMoved) {
//					if (Player1.idx - player2CurIdx == 1) {
//						Player1.idx -= 2;
//					}
//					else { Player1.idx -= 1; }
//				}
//				else if (Player1.hasMoved) {
//					if (Player1.idx - Player1.curIdx == 1) {
//						Player1.idx -= 1;
//					}
//					if (Player1.idx - Player1.curIdx == 2) {
//						Player1.idx -= 2;
//					}
//				}
//			}
//		}
//	}
//	else if (isTrigger(KEY_UP)) {
//		if (Player1.idx >= 9) {
//			int nextIdx = Player1.idx - 9;
//			if (game()->walls()->isPathBlocked(Player1.idx, nextIdx) == false) {
//				if (!Player1.hasMoved) {
//					if (Player1.idx - player2CurIdx == 9) {
//						if (player2CurIdx > 9) {
//							Player1.idx -= 18;
//						}
//						else { Player1.idx; }
//					}
//					else { Player1.idx -= 9; }
//				}
//				else if (Player1.hasMoved) {
//					if (Player1.idx - Player1.curIdx == 9) {
//						Player1.idx -= 9;
//					}
//					if (Player1.idx - Player1.curIdx == 18) {
//						Player1.idx -= 18;
//					}
//				}
//			}
//		}
//	}
//	else if (isTrigger(KEY_DOWN)) {
//		if (Player1.idx <= 71) {
//			int nextIdx = Player1.idx + 9;
//			if (game()->walls()->isPathBlocked(Player1.idx, nextIdx) == false) {
//				if (!Player1.hasMoved) {
//					if (player2CurIdx - Player1.idx == 9) {
//						if (player2CurIdx <= 71) {
//							Player1.idx += 18;
//						}
//						else { Player1.idx; }
//					}
//					else { Player1.idx += 9; }
//				}
//				else if (Player1.hasMoved) {
//					if (Player1.curIdx - Player1.idx == 9) {
//						Player1.idx += 9;
//					}
//					if (Player1.curIdx - Player1.idx == 18) {
//						Player1.idx += 18;
//					}
//				}
//			}
//		}
//	}
//
//	Player1.pos = game()->tiles()->pos(Player1.idx);
//	Player1.hasMoved = (Player1.idx != Player1.curIdx);
//}

int PLAYER1::calcNextIdx(int p1, int p2, int dx, int dy, int allowReturnIdx) {
	int next = p1 + dx + dy * 9;

	if (next < 0 || next >= 81) return p1;

	if (game()->walls()->isPathBlocked(p1, next)) {
		return p1;
	}

	if (next == p2) {
		int jump = p2 + dx + dy * 9;

		if (jump >= 0 && jump < 81 &&
			!game()->walls()->isPathBlocked(p2, jump)) {
			return jump;
		}

		int left_dx = -dy;
		int left_dy = dx;
		int left = p2 + left_dx + left_dy * 9;
		if (left >= 0 && left < 81 &&
			!game()->walls()->isPathBlocked(p2, left)) {
			return left;
		}

		int right_dx = dy;
		int right_dy = -dx;
		int right = p2 + right_dx + right_dy * 9;
		if (right >= 0 && right < 81 &&
			!game()->walls()->isPathBlocked(p2, right)) {
			return right;
		}

		/*if (allowReturnIdx == p1) return allowReturnIdx;
		else return p1;

		if (allowReturnIdx != -1 && next != allowReturnIdx) {
			int dxBack = (allowReturnIdx % 9) - (p1 % 9);
			int dyBack = (allowReturnIdx / 9) - (p1 / 9);
			int backIdx = p1 + dxBack + dyBack * 9;

			if (!game()->walls()->isPathBlocked(p1, backIdx)) return backIdx;
			return p1;
		}*/
		return p1;
	}

	return next;
}

void PLAYER1::move() {
	int p1 = Player1.idx;
	int p2 = game()->player2()->curIdx();
	int target = p1;

	int dx = 0, dy = 0;
	if (isTrigger(KEY_RIGHT)) dx = 1;
	else if (isTrigger(KEY_LEFT))dx = -1;
	else if (isTrigger(KEY_UP))dy = -1;
	else if (isTrigger(KEY_DOWN))dy = 1;

	if (!Player1.hasMoved) {
		// 未移動：自由に1手（ジャンプ含む）
		if (isTrigger(KEY_RIGHT)) target = calcNextIdx(p1, p2, 1, 0, -1);
		if (isTrigger(KEY_LEFT))  target = calcNextIdx(p1, p2, -1, 0, -1);
		if (isTrigger(KEY_UP))    target = calcNextIdx(p1, p2, 0, -1, -1);
		if (isTrigger(KEY_DOWN))  target = calcNextIdx(p1, p2, 0, 1, -1);
	}
	else {
		// 移動後：ターン開始位置に戻るのみ許可
		if (isTrigger(KEY_RIGHT) || isTrigger(KEY_LEFT) ||
			isTrigger(KEY_UP) || isTrigger(KEY_DOWN)) {

			if (Player1.curIdx == calcNextIdx(p1, p2, 0, 0, Player1.curIdx)) {
				target = Player1.curIdx;
			}
		}
	}

	Player1.idx = target;
	Player1.pos = game()->tiles()->pos(Player1.idx);
	Player1.hasMoved = (Player1.idx != Player1.curIdx);
}


void PLAYER1::draw(){
	fill(Player1.color);
	circle(Player1.pos.x, Player1.pos.y, Player1.radius);
}