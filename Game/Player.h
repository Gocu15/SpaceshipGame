#pragma once

#include"Bullet.h"

class Player
{
private:
	Texture *texture;

	int shootTimer;
	int shootTimerMax;
	int damageTimer;
	int damageTimerMax;

	Vector2f position;

	Sprite sprite;
	RectangleShape hitBox;

	Texture  *bulletTexture;
	std::vector<Bullet> bullets;
	Vector2f bulletcenter;

	int controls[5];
	Vector2f currentVelocity;
	float maxVelocity;
	float acceleration;
	Vector2f direction;
	float stabilizer;

	int hp;
	int hpMax;

	int damage;

	int score;

public:
	Player(Texture *texture, Texture *bulletTexture, Vector2f position,
	int UP = 22, int DOWN = 18, int LEFT = 0, int RIGHT = 3, int SHOOT = 57);
	virtual ~Player();

	inline std::vector<Bullet>& getBullets() { return this->bullets; }
	inline const Vector2f getPosition()const { return this->sprite.getPosition(); }
	inline const String getHPAsString()const { return std::to_string(this->hp) + "/" + std::to_string(this->hpMax); }
	inline const int getDamage()const { return this->damage; }
	inline FloatRect getGlobalBounds()const { return this->sprite.getGlobalBounds(); }
	inline const int& getHP()const { return this->hp; }
	inline const int& getHPMax()const { return this->hpMax; }
	inline void takeDamage(int damage) { this->hp -=damage; }
	inline bool isAlive()const { return this->hp > 0; }

	inline void gainScore(int score) { this->score += score; }
	inline const int getScore()const { return this->score; }
	
	void Combat();

	void Reset();
	void Update(Vector2u windowBounds);
	void Draw(RenderTarget& target);
	void Movement(Vector2u windowBounds);
};

