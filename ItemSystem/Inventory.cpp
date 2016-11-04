#include "Inventory.h"



Inventory::Inventory(){
	initSlots(_itemSlots, sf::Vector2i(560, 400), sf::Vector2i(50, 50), sf::Vector2i(4, 4), 4, 3);
}

Inventory::~Inventory(){

}

std::array<ItemSlot, 12>& Inventory::slots() {
	return _itemSlots;
}

void Inventory::debugDraw(sf::RenderWindow& window) {
	for (auto& slot : _itemSlots) {
		slot.debugDraw(window);
	}
}