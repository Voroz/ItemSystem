#pragma once
#include "ItemManip.h"

class Inventory : public BoundingRect
{
public:
	Inventory(sf::Vector2i pos, sf::Vector2i size);
	~Inventory();

	std::array<ItemSlot, 12>& slots();
	void debugDraw(sf::RenderWindow& window);

private:
	std::array<ItemSlot, 12> _itemSlots;
	sf::Vector2i _separation;
	int _cols;
	int _rows;
};

