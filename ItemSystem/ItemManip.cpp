#include "ItemManip.h"

// Swaps 2 slots items

bool swapItem(ItemSlot* slot1, ItemSlot* slot2) {
	if (slot1 == nullptr || slot2 == nullptr) {
		return 0;
	}
	if (slot1 == slot2) {
		return 0;
	}
	Item* temp = slot1->item();
	slot1->assignItem(*slot2->item());
	slot2->assignItem(*temp);
	return 1;
}

// Moves item from one slot to another, swapping the slots contents.
// This function is used for moving an item with the mouse, and will do
// more error checks.

bool moveItem(ItemSlot* from, ItemSlot* to) {
	if (from == nullptr || to == nullptr) {
		return 0;
	}
	if (from->item() == nullptr) {
		return 0;
	}
	return swapItem(from, to);
}