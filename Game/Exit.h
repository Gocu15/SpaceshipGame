#pragma once
#include "bullet.h"
#define MAX_NUMBER_OF_ITEMS 2
class Exit
{
	public:
		//menu
		Exit(float width, float height, RenderWindow & window);
		~Exit();

		void draw(RenderWindow & window);
		void MoveUp();
		void MoveDown();
		int GetPressedItem() { return selectedItemIdex; }
	private:
		//menu
		Text exit[MAX_NUMBER_OF_ITEMS];
		int selectedItemIdex = 0;
		Font font;
		Text tekst;

};

