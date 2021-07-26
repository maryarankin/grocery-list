#include <iostream>
#include "GroceryList.h"
using std::cout;
using std::endl;

GroceryList::GroceryList(string listName) {
	_listName = listName;
}

string GroceryList::GetListName() {
	return _listName;
}

vector<GroceryItem*>& GroceryList::GetListItems() {
	return _listItems;
}

void GroceryList::PrintGroceryList() {
	if (_listItems.size() == 0) {
		cout << "No items in list" << endl;
	}
	for (int i = 0; i < _listItems.size(); i++) {
		_listItems.at(i)->PrintItem();
	}
}

void GroceryList::AddToList(GroceryItem* itemToAdd) {
	_listItems.push_back(itemToAdd);
}

void GroceryList::DeleteFromList(GroceryItem* itemToDelete) {
	for (int i = 0; i < _listItems.size(); i++) {
		if (_listItems.at(i)->GetItemName() == itemToDelete->GetItemName()) {
			_listItems.erase(_listItems.begin() + i);
			break;
		}
	}
}