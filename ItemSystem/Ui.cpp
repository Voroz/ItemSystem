#include "Ui.h"


Ui::Ui(sf::RenderWindow &window, Inventory& inventory, std::vector<Item*>& items) :
	_window(window),
	_inventory(inventory),
	_items(items),
	_mouseData(window, inventory, items){

}

Ui::~Ui(){

}

void Ui::updateItemPos() {
	for (auto &slot : _inventory.slots()) {
		if (slot.item() == nullptr) {
			continue;
		}
		slot.item()->setPos(slot.pos());
		int test = 0;
	}
}
void Ui::tick() {
	updateItemPos();
	_mouseData.update();

	// Move around items in inventory slots
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		if (_moveItemData.dragging == false) {
			_moveItemData.dragging = true;
			_moveItemData.from = _mouseData.mouseOverSlot;
		}
	}
	else if (_moveItemData.dragging == true){
		_moveItemData.dragging = false;
		_moveItemData.to = _mouseData.mouseOverSlot;
		moveItem(_moveItemData.from, _moveItemData.to);
	}
}