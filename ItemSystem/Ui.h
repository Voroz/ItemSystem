#pragma once
#include "ItemSlot.h"
#include "ItemManip.h"
#include "Inventory.h"
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
	MouseData(sf::RenderWindow &window, Inventory& inventory, std::vector<Item*>& items) :
		_window(window),
		_inventory(inventory),
		_items(items){

	}
	~MouseData() {

	}
	void update() {
		position = sf::Mouse::getPosition(_window);
		
		mouseOverSlot = nullptr;
		for (auto &slot : _inventory.slots()) {
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
	Inventory& _inventory;
	std::vector<Item*>& _items;
};

class Ui
{
public:
	Ui(sf::RenderWindow &window, Inventory& inventory, std::vector<Item*>& items);
	~Ui();
	void updateItemPos();
	void tick();

private:
	MoveItemData _moveItemData;
	MouseData _mouseData;
	sf::RenderWindow &_window;
	Inventory& _inventory;
	std::vector<Item*>& _items;
};

