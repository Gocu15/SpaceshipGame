#pragma once
#include "bullet.h"
class Pause
{
private:
	RectangleShape background;
	Text pause;
	Font font;
	Texture texture;
	Sprite sprite;
	RenderWindow* window;
public:
	Pause(RenderWindow* window);
	virtual ~Pause();

	void update();
	void draw(RenderWindow& window);

};

