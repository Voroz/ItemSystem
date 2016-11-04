#include "Ui.h"


Ui::Ui(sf::RenderWindow &window, std::array<ItemSlot, 12>& slots, std::array<Item, 5>& items) :
	_window(window),
	_itemSlots(slots),
	_items(items),
	_mouseData(window, slots, items){

}

Ui::~Ui(){

}

void Ui::tick() {
	_mouseData.update();
}