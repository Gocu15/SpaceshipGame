#include "Game.h"



Game::Game(RenderWindow* window)
{
	this->window = window;
	this->window->setFramerateLimit(60);
	//Fonts
	this->font.loadFromFile("Fonts/Dosis-Light.ttf");
	this->font1.loadFromFile("Fonts/space age.ttf");

	//Texture
	this->playerTexture.loadFromFile("Sprites/ship.png");
	this->bulletTexture.loadFromFile("Sprites/laser.png");
	this->enemyTexture.loadFromFile("Sprites/enemy.png");

	//Player
	this->player.push_back(Player(&playerTexture, &bulletTexture, Vector2f(position.x = 410, position.y = 550 )));
	this->playerAlive = this->player.size();

	Enemy e1(
	&enemyTexture, this->window->getSize(),
		Vector2f(0.f, 5.f),
		Vector2f(0.1f, 0.1f),
		0, rand() % 3 + 1, 1);
		this->enemiesSaved.push_back(Enemy(e1));
		this->enemySpawnTimerMax = 30.f;
		this->enemySpawnTimer = this->enemySpawnTimerMax;



	this->InitUI();
}

Game::~Game()
{
}

void Game::InitUI()
{ 
	for (size_t i = 0; i < player.size(); i++)
	{
		//Follow Text Init
		this->followPLayerText.setFont(font);
		this->followPLayerText.setCharacterSize(15);
		this->followPLayerText.setFillColor(Color::Red);
		this->followPLayerText.setString(std::to_string(i));
		this->followPLayerText.setStyle(Text::Bold);
	}
	//Enemy text
	this->enemyText.setFont(this->font);
	this->enemyText.setCharacterSize(14);
	this->enemyText.setFillColor(Color::White);
	this->enemyText.setStyle(Text::Bold);

	this->GameOver.setFont(this->font1);
	this->GameOver.setOutlineColor(Color::Red);
	this->GameOver.setOutlineThickness(2.f);
	this->GameOver.setCharacterSize(50);
	this->GameOver.setPosition(this->window->getSize().x - 700, this->window->getSize().y - 650);
	this->GameOver.setStyle(Text::Bold);

	//Game over menu
	Over[0].setFont(font1);
	Over[0].setCharacterSize(50);
	Over[0].setStyle(Text::Bold | Text::Underlined);
	Over[0].setFillColor(Color::Red);
	Over[0].setString("New Game");
	Over[0].setPosition(Vector2f((this->window->getSize().x / 2) - (Over[0].getGlobalBounds().width / 2), this->window->getSize().y / (MAX_NUMBER_OF_ITEMS1 + 2) * 2));

	Over[1].setFont(font1);
	Over[1].setCharacterSize(50);
	Over[1].setStyle(Text::Bold | Text::Underlined);
	Over[1].setFillColor(Color::White);
	Over[1].setString("Return to menu");
	Over[1].setPosition(Vector2f((this->window->getSize().x / 2) - (Over[1].getGlobalBounds().width / 2), this->window->getSize().y / (MAX_NUMBER_OF_ITEMS1 + 2) * 3));

	
	this->Score.setFont(this->font);
	this->Score.setString("Score: 0");
	this->Score.setCharacterSize(30);
	this->Score.setPosition(10.f,10.f);


}

void Game::UpdateUIPlayer(int index)
{
	this->followPLayerText.setPosition(this->player[index].getPosition().x + 25, this->player[index].getPosition().y + 100.f);
	this->followPLayerText.setString(this->player[index].getHPAsString());
}
void Game::UpdateUIEnemy(int index)
{
	this->enemyText.setPosition(this->enemies[index].getPosition().x + 20, this->enemies[index].getPosition().y - 20);

	this->enemyText.setString(
		std::to_string(
			this->enemies[index].getHP())
		+ "/" +
		std::to_string(this->enemies[index].getHPMax()));
}
void Game::MoveUp()
{ 

		if (OverselectedItemIdex - 1 >= 0)
		{
			Over[OverselectedItemIdex].setFillColor(Color::White);
			OverselectedItemIdex--;
			Over[OverselectedItemIdex].setFillColor(Color::Red);
		}
}

void Game::MoveDown()
{
		if (OverselectedItemIdex + 1 < MAX_NUMBER_OF_ITEMS1)
		{
			Over[OverselectedItemIdex].setFillColor(Color::White);
			OverselectedItemIdex++;
			Over[OverselectedItemIdex].setFillColor(Color::Red);
		}
}

void Game::Update()
{
		//Game start
		if (this->playerAlive > 0)
		{
			//difficult timer
			if (this->enemySpawnTimer < this->enemySpawnTimerMax)
				this->enemySpawnTimer++;


			if (this->score >= scoretemp)
			{
				this->difficulty++;
				scoretemp += 5;
				enemySpawnTimerMax--;

				if (enemySpawnTimerMax == 10)
					enemySpawnTimerMax = 10;
			}



			//Spawn Enemies
			if (this->enemySpawnTimer >= this->enemySpawnTimerMax)
			{
				this->enemies.push_back(Enemy(
					&enemyTexture, this->window->getSize(),
					Vector2f(0.f, 5.f),
					Vector2f(0.1f, 0.1f),
					0, rand() % 3 + 1, 1));
				this->enemySpawnTimer = 0;//Resetuje czas
			}
			for (size_t i = 0; i < player.size(); i++)
			{

				//Update player
				this->player[i].Update(this->window->getSize());



				//Bulets
				for (size_t k = 0; k < this->player[i].getBullets().size(); k++)
				{
					this->player[i].getBullets()[k].Update();

					for (size_t j = 0; j < this->enemies.size(); j++)
					{
						//Zderzenie przeciwnika z pociskiem
						if (this->player[i].getBullets()[k].getGlobalBounds().intersects(this->enemies[j].getGlobalBounds()))
						{
							this->player[i].getBullets().erase(this->player[i].getBullets().begin() + k);

							//Spadanie ¿ycia przeciwników
							if (this->enemies[j].getHP() > 0)
							{
								this->enemies[j].takeDamage(this->player[i].getDamage());
							}
							if (this->enemies[j].getHP() <= 0)
							{
								//Zdobywanie punktów
								int score = this->enemies[j].getHPMax();
								this->player[i].gainScore(score);

								this->enemies.erase(this->enemies.begin() + j);
							}
							return;

						}
					}
					//Granice pocisków
					if (this->player[i].getBullets()[k].getPosition().y < 0)
					{
						this->player[i].getBullets().erase(this->player[i].getBullets().begin() + k);
						return;
					}
				}
				//Update wyników
				this->score = 0;
				this->score += player[i].getScore();
				this->Score.setString(std::string("Score: " + std::to_string(this->score) + "\nDifficulty: " + std::to_string(this->difficulty)));
			}

			//Update Enemy
			for (size_t i = 0; i < this->enemies.size(); i++)
			{
				this->enemies[i].Update();

				for (size_t k = 0; k < this->player.size(); k++)
				{
					if (this->player[k].getGlobalBounds().intersects(this->enemies[i].getGlobalBounds()))
					{
						this->player[k].takeDamage(this->enemies[i].getDamage());



						//znikanie gracza po œmieci
						if (!this->player[k].isAlive())
						{
							this->playerAlive--;
						}

						this->enemies.erase(this->enemies.begin() + i);
						return;
					}

				}

				//Granice przeciwnika
				if (this->enemies[i].getPosition().y > this->window->getSize().y - this->enemies[i].getGlobalBounds().height)
				{
					this->enemies.erase(this->enemies.begin() + i);
					return;
				}
			}
		}

		if (this->playerAlive <= 0)
		{
			//Highscore

			std::ifstream readFile;
			readFile.open("Files/highscore.txt");

			if (readFile.is_open())
			{
				while (!readFile.eof())
				{
					readFile >> this->highscore;
				}
			}
			readFile.close();

			std::ofstream writeFile("Files/highscore.txt");
				if (writeFile.is_open())
				{
					if (this->score > this->highscore)
					{
						this->highscore = this->score;
					}
					writeFile << highscore;
				}
				writeFile.close();

				this->GameOver.setString(std::string(
					"Game Over\n\n"
					"Score: " + std::to_string(this->score) + "\n" +
					"Highscore: " + std::to_string(this->highscore)));	
		}
	}

void Game::Reset()
{
	for (size_t i = 0; i < this->player.size(); i++)
	{
		this->player[i].Reset();
	}
	this->playerAlive = this->player.size();
	this->score = 0;
	this->enemySpawnTimerMax = 31.f;
	this->enemies.clear();
	this->difficulty = 0;
	this->playerAlive > 0;
	this->scoretemp = 0;
}

void Game::Draw()
{
		for (size_t i = 0; i < this->enemies.size(); i++)
		{
			this->enemies[i].Draw(*this->window);
			this->UpdateUIEnemy(i);
			this->window->draw(this->enemyText);
		}

		for (size_t i = 0; i < this->player.size(); i++)
		{
			if (this->player[i].isAlive())
			{
				this->player[i].Draw(*this->window);
				this->UpdateUIPlayer(i);
				this->window->draw(this->followPLayerText);

			}
		}

		//Game Over
		if (this->playerAlive <= 0)
		{
			this->window->draw(this->GameOver);
			for (int j = 0; j < MAX_NUMBER_OF_ITEMS1; j++)
			{
				this->window->draw(Over[j]);
			}
		}

		//Score
		this->window->draw(this->Score);
}