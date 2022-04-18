#include "bullet.h"
#define MAX_NUMBER_OF_ITEMS 3

using namespace sf;

class Menu
{
public:
	//menu
	Menu(float width, float height, RenderWindow &window);
	~Menu();

	void draw(RenderWindow& window);
	void MoveUp();
	void MoveDown();
	int GetPressedItem() { return selectedItemIdex; }
private:
	//menu
	int selectedItemIdex = 0;
	Font font;
	Text menu[MAX_NUMBER_OF_ITEMS];
	Text tekst;

};



