#include "CONTAINER.h"

void CONTAINER::load() {
	setData();
	loadGraphic();
}
void CONTAINER::setData() {
	// タイトルクラス
	Data.title.backColor = COLOR(0, 20, 0);
	Data.title.textColor = COLOR(0, 255, 0);
	Data.title.textSize = 400;
	Data.title.pos.x = 0;
	Data.title.pos.y = 700;
	strcpy_s(Data.title.str, "Quoridor");

	// ステージクラス
	Data.stage.backColor = COLOR(random(0, 255), random(0, 255), random(0, 255));
	Data.stage.textColor = COLOR(0, 255, 0);
	Data.stage.textSize = 400;
	Data.stage.pos.x = 0;
	Data.stage.pos.y = 700;
	strcpy_s(Data.stage.str, "STAGE");

	// ゲームクリア
	Data.gameClear.backColor = COLOR(200, 200, 10);
	Data.gameClear.textColor = COLOR(255, 0, 0);
	Data.gameClear.textSize = 250;
	Data.gameClear.pos.x = 0;
	Data.gameClear.pos.y = 700;
	strcpy_s(Data.gameClear.str, "PLAYER1 WIN!");

	// ゲームオーバー
	Data.gameOver.backColor = COLOR(200, 200, 10);
	Data.gameOver.textColor = COLOR(255, 255, 255);
	Data.gameOver.textSize = 250;
	Data.gameOver.pos.x = 0;
	Data.gameOver.pos.y = 700;
	strcpy_s(Data.gameOver.str, "PLAYER2 WIN!");

//キャラクター
	// タイル
	Data.tile.tileColor = COLOR(134, 74, 43);
	Data.tile.baseColor = COLOR(58, 32, 18);
	Data.tile.num = 9;
	Data.tile.tileLength = (height - Data.tile.distance) / Data.tile.num;
	Data.tile.distance = 15;

	// 壁
	Data.walls.curColor = COLOR(255, 255, 0);
	Data.walls.normalColor = COLOR(128, 128, 0);
	Data.walls.curNum = 0;
	Data.walls.totalNum = 20;

	// 1P
	Data.player1.color = COLOR(255, 0, 0);
	Data.player1.idx = 36;
	Data.player1.curIdx = Data.player1.idx;
	Data.player1.radius = 70;

	// 2P
	Data.player2.color = COLOR(255, 255, 255);
	Data.player2.idx = 44;
	Data.player2.curIdx = Data.player2.idx;
	Data.player2.radius = 70;
}

void CONTAINER::loadGraphic() {
}