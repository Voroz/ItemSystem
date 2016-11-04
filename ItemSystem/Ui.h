#pragma once
#include "ItemSlot.h"
#include "ItemManip.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <array>

struct MoveItemData {
	ItemSlot* from = nullptr;
	ItemSlot* to = nullptr;
};

class MouseData {
public:
	MouseData(std::array<ItemSlot, 10>& slots, std::array<Item, 5> items) :
		_itemSlots(slots),
		_items(items){

	}
	~MouseData() {

	}
	void update() {
		position = sf::Mouse::getPosition();
		for (auto &slot : _itemSlots) {
			if (slot.contains(static_cast<sf::Vector2f>(position))) {
				mouseOverSlot = &slot;
				break;
			}
		}
		for (auto &item : _items) {
			if (item.contains(static_cast<sf::Vector2f>(position))) {
				mouseOverItem = &item;
				break;
			}
		}
	}
	sf::Vector2i position = sf::Mouse::getPosition();
	ItemSlot* mouseOverSlot = nullptr;
	Item* mouseOverItem = nullptr;

private:
	std::array<ItemSlot, 10>& _itemSlots;
	std::array<Item, 5> _items;
};

class Ui
{
public:
	Ui(std::array<ItemSlot, 10>& slots, std::array<Item, 5> items);
	~Ui();
	void tick();

private:
	MoveItemData _moveItemData;
	MouseData _mouseData;
	std::array<ItemSlot, 10>& _itemSlots;
	std::array<Item, 5> _items;
};

