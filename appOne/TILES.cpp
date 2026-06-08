#include "TILES.h"
#include "GAME.h"
#include "CONTAINER.h"

TILES::TILES(class GAME* game) :
	GAME_OBJECT(game) {}
TILES::~TILES(){}

void TILES::create(){
	Tile = game()->container()->tile();
	Tiles = new TILE[Tile.num * Tile.num];
}

void TILES::init(){
	Tile.tileLength = (height - Tile.distance * (Tile.num + 1)) / Tile.num;
	for (int i = 0; i < Tile.num; i++) {
		for (int j = 0; j < Tile.num; j++) {
			float px = width / 2 - height / 2 + Tile.distance + Tile.tileLength / 2 + (Tile.tileLength + Tile.distance) * j;
			float py = Tile.distance + Tile.tileLength / 2 + (Tile.tileLength + Tile.distance) * i;
			int idx = i * Tile.num + j;
			Tiles[idx].pos.x = px;
			Tiles[idx].pos.y = py;
		}
	}
}

void TILES::draw(){
	rectMode(CENTER);
	fill(Tile.baseColor);
	rect(width / 2, height / 2, height, height);
	for (int i = 0; i < Tile.num * Tile.num; i++) {
		fill(Tile.tileColor);
		rect(Tiles[i].pos.x, Tiles[i].pos.y, Tile.tileLength, Tile.tileLength);
		fill(255, 255, 255);
		/*textSize(30);
		text(i, Tiles[i].pos.x, Tiles[i].pos.y);*/
	}
}
