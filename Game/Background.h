#pragma once
#include "bullet.h"

using namespace sf;

class Background
{
	Texture tekstura;
	Clock zegar;
	Sprite tlo1, tlo2;
	Vector2u TextureSize, WindowSize;
	RenderWindow* window;

public:
	Background(RenderWindow& window);
	virtual ~Background();

	void Moving();
	void Draw(RenderWindow& window);
};

