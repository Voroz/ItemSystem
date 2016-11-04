#pragma once
#include "ItemSlot.h"

// Swaps 2 slots items

bool swapItem(ItemSlot& slot1, ItemSlot& slot2);

// Moves item from one slot to another, swapping the slots contents.
// This function is used for moving an item with the mouse, and will do
// more error checks.

bool moveItem(ItemSlot& from, ItemSlot& to);