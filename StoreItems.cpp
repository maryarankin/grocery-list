#include <vector>
#include "StoreItems.h"

bool StoreItems::AddStoreItem(GroceryItem* newItem) {  //note: had to remove const from params b/c couldn't get newItem's name otherwise - fix this
	bool added = true;

	for (int i = 0; i < allItems.size(); i++) {
		if (allItems.at(i).GetItemName() == newItem->GetItemName()) {
			added = false;
			break;
		}
	}

	if (added) {
		allItems.push_back(*newItem);
	}
	else {
		delete newItem;
	}
	
	return added;
}

unsigned int StoreItems::GetTotalNumItems() {
	return allItems.size();
}

void StoreItems::PrintAllItems() {
	for (int i = 0; i < allItems.size(); i++) {
		allItems.at(i).PrintItem();
	}
}

GroceryItem* StoreItems::FindItem(string itemName) {
	GroceryItem* foundItem = nullptr;

	for (int i = 0; i < allItems.size(); i++) {
		if (allItems.at(i).GetItemName() == itemName) {
			foundItem = &allItems.at(i);
			break;
		}
	}

	return foundItem;
}

bool StoreItems::DeleteItem(string itemName) {
	bool deleted = false;

	for (int i = 0; i < allItems.size(); i++) {
		if (allItems.at(i).GetItemName() == itemName) {
			allItems.erase(allItems.begin()+i);
			deleted = true;
			break;
		}
	}

	return deleted;
}