#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib> 
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <vector>
#include <string> 
#include <fstream>   
#include <algorithm> 
using namespace sf;
class Bullet
{
private:
	Texture *texture;
	Sprite sprite;
	
	Vector2f maxVelocity;


public:
	Bullet(Texture* texture, Vector2f position,
		Vector2f maxVelocity = Vector2f(0.f, -20.f));
	virtual~Bullet();

	inline FloatRect getGlobalBounds()const { return this->sprite.getGlobalBounds(); }
	inline const Vector2f& getPosition()const { return this->sprite.getPosition(); }

	void Movement();

	void Update();
	void Draw(RenderTarget &target);
};

