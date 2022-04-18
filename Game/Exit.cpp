#include "Exit.h"

Exit::Exit(float width, float height, RenderWindow& window)
{
	font.loadFromFile("Fonts/space age.ttf");

	tekst.setFont(font);
	tekst.setCharacterSize(70);
	tekst.setFillColor(Color::White);
	tekst.setString("Are You Sure???");
	tekst.setPosition(Vector2f((width / 2) - (tekst.getGlobalBounds().width / 2), tekst.getGlobalBounds().height / 2));


	exit[0].setFont(font);
	exit[0].setCharacterSize(50);
	exit[0].setStyle(Text::Bold | Text::Underlined);
	exit[0].setFillColor(Color::Red);
	exit[0].setString("YES");
	exit[0].setPosition(Vector2f((window.getSize().x / 2) - (exit[0].getGlobalBounds().width / 2), window.getSize().y / (MAX_NUMBER_OF_ITEMS + 2) * 1.5));

	exit[1].setFont(font);
	exit[1].setCharacterSize(50);
	exit[1].setStyle(Text::Bold | Text::Underlined);
	exit[1].setFillColor(Color::White);
	exit[1].setString("NO");
	exit[1].setPosition(Vector2f((window.getSize().x / 2) - (exit[1].getGlobalBounds().width / 2), window.getSize().y / (MAX_NUMBER_OF_ITEMS + 2) * 2.5));

}
Exit::~Exit()
{
}


void Exit::MoveUp()
{
	if (Keyboard::isKeyPressed(Keyboard::Up))
	{
		if (selectedItemIdex - 1 >= 0)
		{
			exit[selectedItemIdex].setFillColor(Color::White);
			selectedItemIdex--;
			exit[selectedItemIdex].setFillColor(Color::Red);
		}
	}
}

void Exit::MoveDown()
{
	if (Keyboard::isKeyPressed(Keyboard::Down))
	{
		if (selectedItemIdex + 1 < MAX_NUMBER_OF_ITEMS)
		{
			exit[selectedItemIdex].setFillColor(Color::White);
			selectedItemIdex++;
			exit[selectedItemIdex].setFillColor(Color::Red);
		}
	}
}

void Exit::draw(RenderWindow& window)
{
	window.draw(tekst);
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
	{
		window.draw(exit[i]);
	}
}