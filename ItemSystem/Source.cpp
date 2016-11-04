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
	for (auto& slot : slots) {
		slot.setWidth(size.x);
		slot.setHeight(size.y);
		slot.setPos(topLeft.x + size.x * currCol + separation.x * currCol, topLeft.y + size.y * currRow + separation.y * currRow);
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
	std::vector<Item*> items;
	Item item;
	items.push_back(&item);

	initSlots(slots, sf::Vector2i(560, 400), sf::Vector2i(50, 50), sf::Vector2i(4, 4), 4, 3);

	slots[0].assignItem(item);
	moveItem(&slots[0], &slots[1]);

	item.setWidth(50);
	item.setHeight(50);
	item.setPos(sf::Vector2f(200, 300));

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
		for (auto& item : items) {
			item->debugDraw(window);
		}
		window.display();
	}

	return 0;
}