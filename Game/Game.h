#pragma once

#include"Player.h"
#include"Enemy.h"
#define MAX_NUMBER_OF_ITEMS1 2


class Game
{
private:
	RenderWindow* window;
	Vector2f position;
	int score;
	int highscore;
	int punkty;

	//Text
	Font font, font1;
	Text followPLayerText;
	Text enemyText;
	Text GameOver;
	Text Pause;
	Text Score;
	//Player
	std::vector<Player> player;
	int playerAlive;
	//Enemies
	std::vector<Enemy> enemies;
	std::vector<Enemy> enemiesSaved;
	float enemySpawnTimer;
	float enemySpawnTimerMax;

	//Textures
	Texture playerTexture;
	Texture bulletTexture;
	Texture enemyTexture;

	//Game over menu
	int OverselectedItemIdex = 0;
	Text Over[MAX_NUMBER_OF_ITEMS1];

	//Difficult
	float difficultyTimer;
	int difficulty = 1;
	int scoretemp = 5;

public:
	Game(RenderWindow* window);
	virtual ~Game();

	//Accesors
	inline RenderWindow& getWindow() { return *this->window; }

	//Functions
	void InitUI();
	void UpdateUIPlayer(int index);
	void UpdateUIEnemy(int index);
	void Update();
	void Reset();
	void Draw();

	//Game over menu
	void MoveUp();
	void MoveDown();
	int OverGetPressedItem() { return OverselectedItemIdex; }
	int Alive() { return playerAlive; }
	int getscore() { return score; }
	int getdifficulty() { return difficulty; }
};