#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include "Item.h"
#include "ItemSlot.h"
#include "Ui.h"
#include "ItemManip.h"


bool initSlots(std::array<ItemSlot, 12>& slots, sf::Vector2i topLeft, sf::Vector2i size, sf::Vector2i separation, int cols, int rows) {
	if (cols * rows < slots.size()) {
		return 0;
	}
	int currCol = 0;
	int currRow = 0;
	for (int i = 0; i < slots.size(); i++) {
		slots[i].setWidth(size.x);
		slots[i].setHeight(size.y);
		slots[i].setPos(topLeft.x + size.x * currCol + separation.x * currCol, topLeft.y + size.y * currRow + separation.y * currRow);
		currCol++;
		if (currCol % cols == 0) {
			currCol = 0;
			currRow++;
		}
		if (currCol * currRow > cols * rows) {
			break;
		}
	}
	return 1;
}


int main() {
	std::array<ItemSlot, 12> slots;
	std::array<Item, 5> items;

	initSlots(slots, sf::Vector2i(560, 400), sf::Vector2i(50, 50), sf::Vector2i(2, 2), 4, 3);

	slots[0].assignItem(items[0]);
	moveItem(slots[0], slots[1]);

	items[0].setWidth(50);
	items[0].setHeight(50);
	items[0].setPos(sf::Vector2f(200, 300));

	sf::RenderWindow window(sf::VideoMode(800, 600), "Item System");

	Ui ui(window, slots, items);

	// run the program as long as the window is open
	while (window.isOpen()){
		sf::Event event;
		while (window.pollEvent(event))
		{
			// "close requested" event: we close the window
			if (event.type == sf::Event::Closed)
				window.close();
		}

		ui.tick();

		window.clear();
		for (auto& slot : slots) {
			slot.debugDraw(window);
		}
		window.display();
	}

	return 0;
}