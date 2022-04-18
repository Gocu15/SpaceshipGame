#include "Pause.h"

Pause::Pause(RenderWindow* window)
{
	this->window = window;
	this->background.setSize(Vector2f(
		static_cast<float>(this->window->getSize().x),
		static_cast<float>(this->window->getSize().y)));
	background.setFillColor(Color(20, 20, 20, 150));

	font.loadFromFile("Fonts/Dosis-Light.ttf");

	texture.loadFromFile("Sprites/instrukcja.png");
	sprite.setTexture(texture);
	sprite.setPosition(this->window->getSize().x - 860, this->window->getSize().y - 550);
}
Pause:: ~Pause()
{

}

void Pause::update() 
{
	pause.setFont(this->font);
	pause.setFillColor(Color::Red);
	pause.setString("Pause");
	pause.setCharacterSize(70);
	pause.setPosition(this->window->getSize().x - 550, this->window->getSize().y - 650);
	pause.setStyle(Text::Bold);
	
}
void Pause::draw(RenderWindow& window)
{
	window.draw(background);
	window.draw(pause);
	window.draw(sprite);
}