#pragma once
#include"Bullet.h"

class Enemy
{
private:
	Texture* texture;
	Sprite sprite;
	Vector2u windowBounds;
	Vector2f direction;

	
	int type;
	int hp;
	int hpMax;
	int damage;


public:
	Enemy(Texture* texture, Vector2u windowBounds,
	    Vector2f direction,
		Vector2f scale,
		int type,
		int hpMax, int damage);

	virtual ~Enemy();

	//Akcessors
	inline const int getDamage()const { return this->damage; }
	inline const int getHP()const { return this->hp; }
	inline const int getHPMax()const { return this->hpMax; }
	inline const int isDead()const { return this->hp <= 0; }
	inline FloatRect getGlobalBounds()const { return this->sprite.getGlobalBounds(); }
	inline Vector2f getPosition() const { return this->sprite.getPosition(); }
	
	//Functions
	void takeDamage(int damage);
	void Update();
	void Draw(RenderTarget& target);
};
