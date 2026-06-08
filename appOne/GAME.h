#pragma once
class GAME
{
	// コンテナ
private:
	class CONTAINER* Container;
public:
	class CONTAINER* container() { return Container; }
public:
	enum SCENE_ID {
		TITLE_ID,
		STAGE_ID,
		GAME_CLEAR_ID,
		GAME_OVER_ID,
		NUM_SCENES,
	};
private:
	class SCENE* Scenes[NUM_SCENES];
	SCENE_ID CurSceneId;
// キャラクター
private:
	class TILES* Tiles;
	class WALLS* Walls;
	class PLAYER1* Player1;
	class PLAYER2* Player2;
public:
	class TILES* tiles() { return Tiles; }
	class WALLS* walls() { return Walls; }
	class PLAYER1* player1() { return Player1; }
	class PLAYER2* player2() { return Player2; }
// ターン管理
private:
	class TURN_MANAGER* TurnManager;
public:
	class TURN_MANAGER* turnManager() { return TurnManager; }
public:
	GAME();
	~GAME();
	void run();
	void changeScene(SCENE_ID sceneId);
	void create();
};

