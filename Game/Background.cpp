#include "Background.h"

Background::Background(RenderWindow& window)
{

	tekstura.loadFromFile("Sprites/tlo.png");
	tlo1.setTexture(tekstura);
	tlo2.setTexture(tekstura);

	TextureSize = tekstura.getSize();
	WindowSize = window.getSize();

	float ScaleX = (float)WindowSize.x / TextureSize.x;
	float ScaleY = (float)WindowSize.y / TextureSize.y;

	tlo1.setTexture(tekstura);
	tlo2.setTexture(tekstura);

	tlo1.setScale(ScaleX, ScaleY);
	tlo2.setScale(ScaleX, ScaleY);

	tlo2.setPosition(sf::Vector2f(0.0f, -600.f));
	tlo1.setPosition(sf::Vector2f(0.0f, 0.f));

}
Background::~Background()
{
}
void Background::Moving()
{
	if (zegar.getElapsedTime().asMilliseconds() > 30.0f) {
		tlo1.move(sf::Vector2f(0.0f, 2.0f));
		if (tlo1.getPosition().y < 600) {

			tlo2.move(sf::Vector2f(0.0f, 2.0f));

			if (tlo2.getPosition().y > 590)
			{
				tlo2.setPosition(sf::Vector2f(0.0f, -600.f));
			}
		}
		if (tlo1.getPosition().y > 590)
			tlo1.setPosition(sf::Vector2f(0.f, -600.f));

		zegar.restart();
	}
}

void Background::Draw(RenderWindow& window)
{
	window.draw(tlo1);
	window.draw(tlo2);
}