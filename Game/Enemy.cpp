#include "Enemy.h"

Enemy::Enemy(Texture* texture, Vector2u windowBounds,
	Vector2f direction,
	Vector2f scale,
	int type,
	int hpMax, int damage)

{
	this->texture = texture;
	this->sprite.setTexture(*this->texture); 
	this->sprite.setScale(scale);
	this->windowBounds = windowBounds;
	
	this->direction = direction;
	this->sprite.setPosition((rand() % windowBounds.x) - this->sprite.getGlobalBounds().width, 
									   windowBounds.y = 0);

	this->type = type;

	this->hpMax = hpMax;
	this->hp = this->hpMax;

	this->damage = damage;
} 

Enemy::~Enemy()
{

}

void Enemy::takeDamage(int damage)
{
	this->hp -= damage;

	if (this->hp <= 0)
		this->hp = 0;

	this->sprite.move(0.f, -10.f);

}

void Enemy::Update()
{
	switch (this->type)
	{
	case 0:
		this->sprite.move(this->direction.x,
						  this->direction.y);

		break;

	default:

		break;
	}
}
	void Enemy::Draw(RenderTarget & target)
	{
		target.draw(this->sprite);
	}
