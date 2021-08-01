#include <vector>
#include "StoreItems.h"

/* ACCESSORS */
unsigned int StoreItems::GetTotalNumItems() const {
	return _allItems.size();
}

vector<GroceryItem*>& StoreItems::GetAllStoreItems() {
	return _allItems;
}


/* FUNCTIONALITY */
void StoreItems::PrintAllItems() const {
	for (int i = 0; i < _allItems.size(); i++) {
		_allItems.at(i)->PrintItem();
	}
}

bool StoreItems::AddStoreItem(GroceryItem* newItem) {
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

GroceryItem* StoreItems::FindItem(string itemName) const {
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