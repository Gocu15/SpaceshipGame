#include "Bullet.h"

Bullet::Bullet(Texture* texture, Vector2f position,
	Vector2f maxVelocity)
{
	this->texture = texture;
	this->sprite.setTexture(*this->texture);
	this->maxVelocity = maxVelocity;
	this->sprite.setPosition(
		Vector2f(position.x - this->sprite.getGlobalBounds().width/2,
				 position.y - this->sprite.getGlobalBounds().height / 2));
}
 
Bullet::~Bullet()
{
}

void Bullet::Movement()
{
	this->sprite.move(this->maxVelocity.x,this->maxVelocity.y);
}

void Bullet::Update()
{
	this->Movement();
}
void Bullet::Draw(RenderTarget& target)
{
	target.draw(this->sprite);
}
