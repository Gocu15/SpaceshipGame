#pragma once
#include"Bullet.h"
#include"Game.h"


class Score
{
private:

	Text scoretext, exit, Table;
	Font font, font1;
	RectangleShape shape;
public:

	Score(float width, float height, RenderWindow &window);
	virtual ~Score();

	void update_file(Game& game);
	void read_file();
	void draw(RenderWindow& window);

};

