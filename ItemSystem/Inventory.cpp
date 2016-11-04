#include "Inventory.h"



Inventory::Inventory(sf::Vector2i pos, sf::Vector2i size){
	_position = static_cast<sf::Vector2f>(pos);
	_width = size.x;
	_height = size.y;
	_separation = sf::Vector2i(4, 4);
	_cols = 4;
	_rows = 3;
	initSlots(_itemSlots, pos, sf::Vector2i(size.x/_cols - _separation.x + _separation.x/(_cols-1), size.y/_rows - _separation.y + _separation.y / (_rows - 1)), _separation, _cols, _rows);
	_debugColor = sf::Color::White;
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
	BoundingRect::debugDraw(window);
}