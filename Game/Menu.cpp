#include "Menu.h"
#include <iostream>

using namespace std;

Menu::Menu(float width, float height, RenderWindow& window)
{
	font.loadFromFile("Fonts/space age.ttf");
	//Nag³ówek
	tekst.setFont(font);
	tekst.setCharacterSize(70);
	tekst.setFillColor(Color::White);
	tekst.setString("SPACESHIP");
	tekst.setPosition(Vector2f((width / 2) - (tekst.getGlobalBounds().width / 2),tekst.getGlobalBounds().height / 2));
	//Menu
	menu[0].setFont(font);
	menu[0].setCharacterSize(50);
	menu[0].setStyle(Text::Bold | Text::Underlined);
	menu[0].setFillColor(Color::Red);
	menu[0].setString("New Game");
	menu[0].setPosition(Vector2f((width /2)-(menu[0].getGlobalBounds().width/2), height/ (MAX_NUMBER_OF_ITEMS + 2) * 1.5));

	menu[1].setFont(font);
	menu[1].setCharacterSize(50);
	menu[1].setStyle(Text::Bold | Text::Underlined);
	menu[1].setFillColor(Color::White);
	menu[1].setString("Score");
	menu[1].setPosition(Vector2f((width / 2) - (menu[1].getGlobalBounds().width / 2), height / (MAX_NUMBER_OF_ITEMS + 2) * 2.5));

	menu[2].setFont(font);
	menu[2].setCharacterSize(50);
	menu[2].setStyle(Text::Bold | Text::Underlined);
	menu[2].setFillColor(Color::White);
	menu[2].setString("Exit");
	menu[2].setPosition(Vector2f((width / 2) - (menu[2].getGlobalBounds().width / 2), height / (MAX_NUMBER_OF_ITEMS + 2) * 3.5));
}

Menu::~Menu()
{
}

void Menu::draw(RenderWindow& window)
{

	window.draw(tekst);
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
	{
		window.draw(menu[i]);
	}
}
void Menu::MoveUp()
{

	if (selectedItemIdex - 1 >= 0)
	{
		menu[selectedItemIdex].setFillColor(Color::White);
		selectedItemIdex--;
		menu[selectedItemIdex].setFillColor(Color::Red);
	}
}

void Menu::MoveDown()
{
	if (selectedItemIdex + 1 < MAX_NUMBER_OF_ITEMS)
	{
		menu[selectedItemIdex].setFillColor(Color::White);
		selectedItemIdex++;
		menu[selectedItemIdex].setFillColor(Color::Red);
	}
}




