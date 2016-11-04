#include "Ui.h"


Ui::Ui(sf::RenderWindow &window, std::array<ItemSlot, 12>& slots, std::vector<Item*>& items) :
	_window(window),
	_itemSlots(slots),
	_items(items),
	_mouseData(window, slots, items){

}

Ui::~Ui(){

}

void Ui::updateItemPos() {
	for (auto &slot : _itemSlots) {
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
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		if (_moveItemData.dragging == false) {
			_moveItemData.dragging = true;
			_moveItemData.from = _mouseData.mouseOverSlot;
		}
	}
	else if (_moveItemData.dragging == true){
		_moveItemData.dragging = false;
		_moveItemData.to = _mouseData.mouseOverSlot;
		moveItem(*_moveItemData.from, *_moveItemData.to);
	}
}