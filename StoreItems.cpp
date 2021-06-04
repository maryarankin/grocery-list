#include "StoreItems.h"

StoreItems::StoreItems() {
	storeCapacity = 10;
	allItems = new GroceryItem[storeCapacity];
	totalItems = 0;
}

void StoreItems::AddStoreItem(const GroceryItem& newItem) {
	if (storeCapacity == totalItems) {
		unsigned int newSize = storeCapacity + 10;
		GroceryItem* tempArray = new GroceryItem[newSize];
		for (unsigned int i = 0; i < totalItems; i++) {
			tempArray[i] = allItems[i];
		}
		delete[] allItems;
		allItems = tempArray;
	}

	allItems[totalItems] = newItem;
	totalItems++;
}

void StoreItems::PrintAllItems() {
	for (int i = 0; i < totalItems; i++) {
		allItems[i].PrintItem();
	}
}
