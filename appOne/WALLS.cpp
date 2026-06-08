#include "WALLS.h"
#include "GAME.h"
#include "CONTAINER.h"
#include "TILES.h"
#include "TURN_MANAGER.h"

WALLS::WALLS(class GAME* game) :
	GAME_OBJECT(game) {}

WALLS::~WALLS(){}

void WALLS::create() {
	Wall = game()->container()->walls();
	Walls = new WALL[Wall.totalNum];
}

void WALLS::init() {
	Wall.curNum = game()->container()->walls().curNum;
	for (int i = 0; i < Wall.totalNum; i++) {
		Walls[i].idx = 0;
		Walls[i].angle = 0;
		Walls[i].pos = wallPos(Walls[i].idx);
	}
}
void WALLS::update(){
	move();
}
void WALLS::move() {
	int idx = Walls[Wall.curNum].idx;
	int row = idx / 8;
	int col = idx % 8;

	// → 右移動
	if (isTrigger(KEY_RIGHT)) {
		if (col < 7) col++;
	}
	// ← 左移動
	if (isTrigger(KEY_LEFT)) {
		if (col > 0) col--;
	}
	// ↑ 上移動
	if (isTrigger(KEY_UP)) {
		if (row > 0) row--;
	}
	// ↓ 下移動
	if (isTrigger(KEY_DOWN)) {
		if (row < 7) row++;
	}
	if (isTrigger(KEY_M)) {
		Walls[Wall.curNum].angle += 1;
	}
	Walls[Wall.curNum].idx = row * 8 + col;
	Walls[Wall.curNum].pos = wallPos(Walls[Wall.curNum].idx);
}
bool WALLS::canPlaceWall(int idx, int angle) {
	int row = idx / 8;
	int col = idx % 8;
	
	for (int i = 0; i < Wall.curNum; i++) {
		if (!Walls[i].isPlaced) continue;

		int otherRow = Walls[i].idx / 8;
		int otherCol = Walls[i].idx % 8;

		if (Walls[i].idx == idx) { return false; }

		if(angle % 2 == 1 && Walls[i].angle % 2 == 1) {
			if (row == otherRow && abs(col - otherCol) == 1) {
				return false;
			}
		}
		if (angle % 2 == 0 && Walls[i].angle % 2 == 0) {
			if (col == otherCol && abs(row - otherRow) == 1) {
				return false;
			}
		}
	}
	return true;
}
bool WALLS::placeWall(int playerId) {
	if (Wall.curNum >= Wall.totalNum) { return false; }
	if (!canPlaceWall(Walls[Wall.curNum].idx, Walls[Wall.curNum].angle)) {
		return false;
	}

	Walls[Wall.curNum].isPlaced = true;
	Walls[Wall.curNum].owner = playerId;

	Wall.curNum++;
	return true;
}
bool WALLS::isPathBlocked(int startTileIdx, int endTileIdx) {
	for (int i = 0; i < Wall.curNum; i++) {
		if (!Walls[i].isPlaced)continue;
		int wall_idx = Walls[i].idx;
		int r_wall = wall_idx / 8;
		int c_wall = wall_idx % 8;

		bool isHorizontal = (Walls[i].angle % 2 == 0);

		if (isHorizontal) {
			// 水平壁
			int tileA_top = r_wall * 9 + c_wall;
			int tileA_right = tileA_top + 1;
			int tileB_top = tileA_top + 9;
			int tileB_right = tileB_top + 1;

			// 上段のタイル間
			if ((startTileIdx == tileA_top && endTileIdx == tileA_right) ||
				(startTileIdx == tileA_right && endTileIdx == tileA_top)) {
				return true;
			}
			// 下段のタイル間
			if ((startTileIdx == tileB_top && endTileIdx == tileB_right) ||
				(startTileIdx == tileB_right && endTileIdx == tileB_top)) {
				return true;
			}
		}
		else {
			// 垂直壁
			int tileA_left = r_wall * 9 + c_wall;
			int tileA_bottom = tileA_left + 9;
			int tileB_left = tileA_left + 1;
			int tileB_bottom = tileB_left + 9;

			// 左列のタイル間
			if ((startTileIdx == tileA_left && endTileIdx == tileA_bottom) ||
				(startTileIdx == tileA_bottom && endTileIdx == tileA_left)) {
				return true;
			}
			// 右列のタイル間
			if ((startTileIdx == tileB_left && endTileIdx == tileB_bottom) ||
				(startTileIdx == tileB_bottom && endTileIdx == tileB_left)) {
				return true;
			}
		}
	}
	return false;
}
VECTOR2 WALLS::wallPos(int idx) {
	int r = idx / 8;
	int c = idx % 8;
	VECTOR2 pos = (game()->tiles()->pos(r * 9 + c) +
		       game()->tiles()->pos(r * 9 + c + 1) +
			   game()->tiles()->pos((r + 1) * 9 + c) +
			   game()->tiles()->pos((r + 1) * 9 + c + 1)) / 4;
	
	return pos;
}
void WALLS::draw() {
	rectMode(CENTER);
	float w = game()->tiles()->distance();
	float h = game()->tiles()->tileLength() * 2 + game()->tiles()->distance();
	float pi = 3.141592f;
	for(int i = 0; i < Wall.curNum; i++){
		if (Walls[i].isPlaced == false) { continue; }
		fill(Wall.normalColor);
		rect(Walls[i].pos.x, Walls[i].pos.y, w, h, Walls[i].angle * pi / 2);
	}
	if (game()->turnManager()->mode() == TURN_MANAGER::PLACE_WALL && Wall.curNum < Wall.totalNum) {
		fill(Wall.curColor);
		rect(Walls[Wall.curNum].pos.x, Walls[Wall.curNum].pos.y, w, h, Walls[Wall.curNum].angle * pi / 2);
	}
}