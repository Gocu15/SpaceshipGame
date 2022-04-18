#include "Score.h"

struct wynik
{
	int trudnoœæ;
	int punkty;

}; wynik tab[9];

Score::Score(float width, float height, RenderWindow& window)
{

	font.loadFromFile("Fonts/space age.ttf");
	font1.loadFromFile("Fonts/Dosis-Light.ttf");
	
	
	scoretext.setString("Score");
	scoretext.setFont(this->font);
	scoretext.setOutlineColor(Color::Green);
	scoretext.setOutlineThickness(2.f);
	scoretext.setCharacterSize(80);
	scoretext.setPosition(Vector2f((width / 2) - (scoretext.getGlobalBounds().width / 2), scoretext.getGlobalBounds().height / 2));
	scoretext.setStyle(Text::Bold);

	exit.setString("Press F2 to back to main menu");
	exit.setFont(this->font1);
	exit.setCharacterSize(30);
	exit.setPosition(Vector2f((width / 2) - (exit.getGlobalBounds().width / 2), (height / 2) + 250.f));


	shape.setSize(sf::Vector2f(800, 400));
	shape.setPosition(Vector2f((width / 2) - (shape.getGlobalBounds().width / 2), shape.getGlobalBounds().height / 3));
	shape.setFillColor(Color(10, 10, 10, 150));
	shape.setOutlineColor(Color(61, 255, 173, 150));
	shape.setOutlineThickness(20.f);

	this->Table.setFont(this->font);
	this->Table.setCharacterSize(40);
	this->Table.setPosition(Vector2f((width/ 2.3) - (shape.getGlobalBounds().width / 2.5), shape.getGlobalBounds().height / 3));
}


Score::~Score()
{

}

void Score::update_file(Game& game)
{
	tab[8].punkty = game.getscore();
	tab[8].trudnoœæ = game.getdifficulty();

	if (game.Alive() <= 0)
	{
		std::ofstream fwriteFile("Files/score.txt");
		if (fwriteFile.is_open())
		{
			for (int i = 0; i < 9; i++)
			{
				for (int j = 0; j < 8; j++)
				{
					if (tab[j].punkty < tab[j + 1].punkty)
					{
						std::swap(tab[j].trudnoœæ, tab[j + 1].trudnoœæ);
						std::swap(tab[j].punkty, tab[j + 1].punkty);
					}
				}
			}
			for (int k = 0; k < 8; k++)
			{
				fwriteFile << tab[k].punkty << std::endl;
				fwriteFile << tab[k].trudnoœæ << std::endl;
			}
		}
		fwriteFile.close();
	}
}
void Score::read_file()
{
	std::ifstream freadFile;
	freadFile.open("Files/score.txt");
	if (freadFile.is_open())
	{
		while (!freadFile.eof())
		{
			for (int k = 0; k < 8; k++)
			{
				freadFile >> tab[k].punkty;
				freadFile >> tab[k].trudnoœæ;
			}
		}
	}
	freadFile.close();

	Table.setString("Points:     ""Difficulty Level : \n"
		+ std::to_string(tab[0].punkty) + "                 " + std::to_string(tab[0].trudnoœæ) + "\n"
		+ std::to_string(tab[1].punkty) + "                 " + std::to_string(tab[1].trudnoœæ) + "\n"
		+ std::to_string(tab[2].punkty) + "                 " + std::to_string(tab[2].trudnoœæ) + "\n"
		+ std::to_string(tab[3].punkty) + "                 " + std::to_string(tab[3].trudnoœæ) + "\n"
		+ std::to_string(tab[4].punkty) + "                 " + std::to_string(tab[4].trudnoœæ) + "\n"
		+ std::to_string(tab[5].punkty) + "                 " + std::to_string(tab[5].trudnoœæ) + "\n"
		+ std::to_string(tab[6].punkty) + "                 " + std::to_string(tab[6].trudnoœæ) + "\n"
		+ std::to_string(tab[7].punkty) + "                 " + std::to_string(tab[7].trudnoœæ) + "\n");
}
void Score::draw(RenderWindow& window)
{
	window.draw(scoretext);
	window.draw(shape);
	window.draw(exit);
	window.draw(Table);
}