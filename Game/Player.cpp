#include "Player.h"
using namespace std;

enum CONTROLS {UP = 0, DOWN, LEFT , RIGHT, SHOOT};

Player::Player(Texture *texture, Texture *bulletTexture, Vector2f position,
	int UP, 
	int DOWN , 
	int LEFT, 
	int RIGHT, 
	int SHOOT) :hp(10), hpMax(10), damage(1), score(0)
{
	this->position = position;
	this->texture = texture;
	this->bulletTexture = bulletTexture;
	this->sprite.setTexture(*this->texture);
	this->sprite.setScale(0.14f, 0.14f);
	this->sprite.setPosition(position);

	this->shootTimerMax = 25;
	this->shootTimer = this->shootTimerMax;
	this->damageTimerMax = 10;
	this->damageTimer = this->damageTimerMax;

	this->controls[CONTROLS::UP] = UP;
	this->controls[CONTROLS::DOWN] = DOWN;
	this->controls[CONTROLS::LEFT] = LEFT;
	this->controls[CONTROLS::RIGHT] = RIGHT;
	this->controls[CONTROLS::SHOOT] = SHOOT;
	
	
	this->maxVelocity = 25.f;
	this->acceleration = 0.8f;
	this->stabilizer = 0.4f;
}
Player::~Player()
{
}

void Player::Movement(Vector2u windowBounds)
{
	//Up
	if (Keyboard::isKeyPressed(Keyboard::Key(this->controls[CONTROLS::UP])))
	{
		this->direction.y = -1.f;
		if (this->currentVelocity.y > -this->maxVelocity && direction.y < 0)
		{
			this->currentVelocity.y += direction.y * acceleration;
		}
	}
	//Down
	if (Keyboard::isKeyPressed(Keyboard::Key(this->controls[CONTROLS::DOWN])))
	{
		this->direction.y = 1.f;
		if (this->currentVelocity.y < this->maxVelocity && direction.y > 0)
		{
			this->currentVelocity.y += direction.y * acceleration;
		}
	}
	//Left
	if (Keyboard::isKeyPressed(Keyboard::Key(this->controls[CONTROLS::LEFT])))
	{
		this->direction.x = -1.f;
		if (this->currentVelocity.x > -this->maxVelocity && direction.x < 0)
		{
			this->currentVelocity.x += direction.x * acceleration;
		}
	}
	//Right
	if (Keyboard::isKeyPressed(Keyboard::Key(this->controls[CONTROLS::RIGHT])))
	{
		this->direction.x = 1.f;
		if (this->currentVelocity.x < this->maxVelocity && direction.x > 0)
		{
			this->currentVelocity.x += direction.x * acceleration;
		}
	}
	//Stabilization
	if (this->currentVelocity.x > 0)
	{
		this->currentVelocity.x -= this->stabilizer;

		if (this->currentVelocity.x < 0)
			this->currentVelocity.x = 0;
	}
	else if (this->currentVelocity.x < 0)
	{
		this->currentVelocity.x += this->stabilizer;

		if (this->currentVelocity.x > 0)
			this->currentVelocity.x = 0;
	}

	if (this->currentVelocity.y > 0)
	{
		this->currentVelocity.y -= this->stabilizer;

		if (this->currentVelocity.y < 0)
			this->currentVelocity.y = 0;
	}
	else if (this->currentVelocity.y < 0)
	{
		this->currentVelocity.y += this->stabilizer;

		if (this->currentVelocity.y > 0)
			this->currentVelocity.y = 0;
	}

	//Smooth move
	this->sprite.move(this->currentVelocity);


	//Window collision
	if (this->getPosition().x <= 0.f)
	{
		this->sprite.setPosition(0.f, this->sprite.getPosition().y);
		this->currentVelocity.x = 0.f;
	}
	if (this->getPosition().y <= 0.f)
	{
		this->sprite.setPosition(this->sprite.getPosition().x, 0.f);
		this->currentVelocity.y = 0.f;
	}
	if (this->getPosition().x + this->getGlobalBounds().width >= windowBounds.x)
	{
		this->sprite.setPosition(windowBounds.x - this->getGlobalBounds().width, this->sprite.getPosition().y);
		this->currentVelocity.x = 0.f;
	}
	if (this->getPosition().y + this->getGlobalBounds().height >= windowBounds.y)
	{
		this->sprite.setPosition(this->sprite.getPosition().x, windowBounds.y - this->getGlobalBounds().height);
		this->currentVelocity.y = 0.f;
	}

}

void Player::Combat()
{
	if (Keyboard::isKeyPressed(Keyboard::Key(this->controls[CONTROLS::SHOOT])) && this->shootTimer >= this->shootTimerMax)
	{
		this->bullets.push_back(Bullet(bulletTexture, this->bulletcenter));

		this->shootTimer = 0;//Reset
	}
}

void Player::Reset()
{
	this->hpMax = 10;
	this->hp = this->hpMax;
	this->sprite.setPosition(position);
	this->bullets.clear();
	this->currentVelocity.x = 0;
	this->currentVelocity.y = 0;
	this->shootTimer = this->shootTimerMax;
	this->damageTimer = this->damageTimerMax;
	this->score = 0;
	
}

void Player::Update(Vector2u windowBounds)
{
	//Update timers
	if (this->shootTimer < this->shootTimerMax)
		this->shootTimer++;

	if (this->damageTimer < this->damageTimerMax)
		this->damageTimerMax++;

	// Bullet Position

	this->bulletcenter.x = this->sprite.getPosition().x + this->sprite.getGlobalBounds().width / 2;
	this->bulletcenter.y = this->sprite.getPosition().y + this->sprite.getGlobalBounds().height / 2;

	this->Movement(windowBounds);
	this->Combat();
} 
void Player::Draw(RenderTarget &target)
{
	for (size_t i = 0; i < this->bullets.size(); i++)
	{
		this->bullets[i].Draw(target);
	}

	target.draw(this->sprite);
}


