#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include "Item.h"
#include "ItemSlot.h"
#include "Ui.h"
#include "ItemManip.h"

void swap(void* sw1, void* sw2) {
	void* temp = sw1;
	sw1 = sw2;
	sw2 = temp;
}


int main() {
	std::array<ItemSlot, 10> slots;
	std::array<Item, 5> items;
	Ui ui(slots, items);

	slots[0].assignItem(items[0]);
	moveItem(slots[0], slots[1]);

	while (1) {
		ui.tick();
	}

	return 0;
}