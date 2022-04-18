#include "Menu.h"
#include "Game.h" 
#include "Background.h" 
#include "Pause.h"  
#include "Exit.h"  
#include "Score.h"  


using namespace sf;
using namespace std;


int main()
{
    int selected_flag = 0;
    int gamePause = true;
    bool load = true;
    RenderWindow window(VideoMode(900, 700), "GAME");//Ekran
    Clock timer;
    //T³o
    Background background(window);

    //Gra
    Game game(&window);

    //Menu
    Menu menu(window.getSize().x, window.getSize().y, window);

    //Pause
    Pause pause(&window);

    //Wyjœcie
    Exit exit(window.getSize().x, window.getSize().y, window);

    //Tabela
    Score score(window.getSize().x, window.getSize().y, window);

    score.read_file();

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Up)
                {
                    menu.MoveUp();
                    game.MoveUp();
                    exit.MoveUp();
                }

                if (event.key.code == sf::Keyboard::Down)
                {
                    menu.MoveDown();
                    game.MoveDown();
                    exit.MoveDown();
                }
                if (event.key.code == sf::Keyboard::Escape)
                {
                    selected_flag = 5;
                }
                    if (selected_flag == 0)
                    {
                        if (event.key.code == sf::Keyboard::Enter && menu.GetPressedItem() == 0)
                        {
                            std::cout << "Uruchamiam gre" << std::endl;
                            selected_flag = 1;
                            
                        }

                        if (event.key.code == sf::Keyboard::Enter && menu.GetPressedItem() == 1)
                        {
                            std::cout << "Najlepsze wyniki" << std::endl;
                            selected_flag = 2;
                        }

                        if (event.key.code == sf::Keyboard::Enter && menu.GetPressedItem() == 2)
                        {
                            selected_flag = 3;
                            std::cout << "Koniec gry" << std::endl;
                            return 0;
                        }
                    }
                    if (selected_flag == 4)
                    {
                        if (event.key.code == sf::Keyboard::Enter && game.OverGetPressedItem() == 0 && load == false)
                        {
                            std::cout << "Uruchamiam gre jeszcze raz" << std::endl;
                            selected_flag = 1;
                            load = true;
                            game.Reset();
                        }

                        if (event.key.code == sf::Keyboard::Enter && game.OverGetPressedItem() == 1 && load == false)
                        {
                            std::cout << "Powrot do menu" << std::endl;
                            selected_flag = 0;
                            load = true;
                            game.Reset();
                        }
                    }
                    if (selected_flag == 5)
                    {
                        if (event.key.code == sf::Keyboard::Enter && exit.GetPressedItem() == 0)
                        {
                            std::cout << "Wyjœcie" << std::endl;
                            return 0;
                        }

                        if (event.key.code == sf::Keyboard::Enter && exit.GetPressedItem() == 1)
                        {
                            std::cout << "Powrót do gry" << std::endl;
                            selected_flag = 1;
                        }
                    }

                    if (event.key.code == sf::Keyboard::F1)
                    {
                        std::cout << "Pauza wciœniêta" << std::endl;
                        gamePause = false;
                    }
                  
            }
            if (event.type == sf::Event::KeyReleased)
            {
                if (event.key.code == sf::Keyboard::F1)
                {
                    std::cout << "Pauza puszczona" << std::endl;
                    gamePause = true;
                }
            }
        }
        window.clear();
        //T³o
        background.Draw(window);
        background.Moving();
      
        //Menu
        if (selected_flag == 0)
        {
            menu.draw(window);
        }
        

        //Gra
        if ((selected_flag == 1) || (selected_flag == 4))
        {

                if (gamePause == false)
                {
                    pause.draw(window);
                    pause.update();
                }
                else
                {
                    if (game.Alive() <= 0 && load == true)
                    {
                        score.update_file(game);
                        score.read_file();
                        load = false;
                        selected_flag = 4;
                    }
                    game.Draw();
                    game.Update();
                }
        }

    

        if (selected_flag == 5)
        {
            exit.draw(window);
        }
        
        if (selected_flag == 2)
        {
            score.draw(window);

            if (Keyboard::isKeyPressed(Keyboard::F2))
            {
                std::cout << "Powrot do menu" << std::endl;
                selected_flag = 0;
            }
        }

        window.display();
    }
        return 0;
    
}