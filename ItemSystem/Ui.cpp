#include "Ui.h"


Ui::Ui(std::array<ItemSlot, 10>& slots, std::array<Item, 5> items) :
	_itemSlots(slots),
	_items(items),
	_mouseData(slots, items){

}

Ui::~Ui(){

}

void Ui::tick() {
	_mouseData.update();
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		std::cout << "left" << std::endl;
	}
}