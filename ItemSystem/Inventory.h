#pragma once
#include "ItemManip.h"

class Inventory
{
public:
	Inventory();
	~Inventory();

	std::array<ItemSlot, 12>& slots();
	void debugDraw(sf::RenderWindow& window);

private:
	std::array<ItemSlot, 12> _itemSlots;
};

