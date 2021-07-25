#include <vector>
#include "StoreItems.h"

bool StoreItems::AddStoreItem(GroceryItem* newItem) {  //note: had to remove const from params b/c couldn't get newItem's name otherwise - fix this
	bool added = true;

	for (int i = 0; i < _allItems.size(); i++) {
		if (_allItems.at(i)->GetItemName() == newItem->GetItemName()) {
			added = false;
			break;
		}
	}

	if (added) {
		_allItems.push_back(newItem);
	}
	else {
		delete newItem;
	}
	
	return added;
}

unsigned int StoreItems::GetTotalNumItems() {
	return _allItems.size();
}

void StoreItems::PrintAllItems() {
	for (int i = 0; i < _allItems.size(); i++) {
		_allItems.at(i)->PrintItem();
	}
}

GroceryItem* StoreItems::FindItem(string itemName) {
	GroceryItem* foundItem = nullptr;

	for (int i = 0; i < _allItems.size(); i++) {
		if (_allItems.at(i)->GetItemName() == itemName) {
			foundItem = _allItems.at(i);
			break;
		}
	}

	return foundItem;
}

bool StoreItems::DeleteItem(string itemName) {
	bool deleted = false;

	for (int i = 0; i < _allItems.size(); i++) {
		if (_allItems.at(i)->GetItemName() == itemName) {
			delete _allItems.at(i);
			_allItems.erase(_allItems.begin()+i);
			deleted = true;
			break;
		}
	}

	return deleted;
}