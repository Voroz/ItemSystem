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
	bool dragging = false;
};

class MouseData {
public:
	MouseData(sf::RenderWindow &window, std::array<ItemSlot, 12>& slots, std::vector<Item*>& items) :
		_window(window),
		_itemSlots(slots),
		_items(items){

	}
	~MouseData() {

	}
	void update() {
		position = sf::Mouse::getPosition(_window);
		
		mouseOverSlot = nullptr;
		for (auto &slot : _itemSlots) {
			if (slot.contains(static_cast<sf::Vector2f>(position))) {
				mouseOverSlot = &slot;
				break;
			}
		}

		mouseOverItem = nullptr;
		for (auto &item : _items) {
			if (item->contains(static_cast<sf::Vector2f>(position))) {
				mouseOverItem = item;
				break;
			}
		}
	}
	sf::Vector2i position;
	ItemSlot* mouseOverSlot = nullptr;
	Item* mouseOverItem = nullptr;

private:
	sf::RenderWindow &_window;
	std::array<ItemSlot, 12>& _itemSlots;
	std::vector<Item*>& _items;
};

class Ui
{
public:
	Ui(sf::RenderWindow &window, std::array<ItemSlot, 12>& slots, std::vector<Item*>& items);
	~Ui();
	void updateItemPos();
	void tick();

private:
	MoveItemData _moveItemData;
	MouseData _mouseData;
	sf::RenderWindow &_window;
	std::array<ItemSlot, 12>& _itemSlots;
	std::vector<Item*>& _items;
};

