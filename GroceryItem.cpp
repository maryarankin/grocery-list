#include <iostream>
#include "GroceryItem.h"
using namespace std;

/* CONSTRUCTOR/DESTRUCTOR */
GroceryItem::GroceryItem(string itemName, string itemCategory, string storeSection, unsigned int aisleNumber) {
		_itemName = itemName;
		_itemCategory = itemCategory;
		_storeSection = storeSection;
		_aisleNumber = aisleNumber;
	}

GroceryItem::~GroceryItem() {
	cout << _itemName << " deleted" << endl;
}


/* ACCESSORS */
string GroceryItem::GetItemName() const {
	return _itemName;
}

string GroceryItem::GetCategory() const {
	return _itemCategory;
}

string GroceryItem::GetStoreSection() const {
	return _storeSection;
}

unsigned int GroceryItem::GetAisleNumber() const {
	return _aisleNumber;
}


/* MUTATORS */
void GroceryItem::SetItemName(string itemName) {
	_itemName = itemName;
}

void GroceryItem::SetItemCategory(string itemCategory) {
	_itemCategory = itemCategory;
}

void GroceryItem::SetStoreSection(string storeSection) {
	_storeSection = storeSection;
}

void GroceryItem::SetAisleNumber(unsigned int aisleNumber) {
	_aisleNumber = aisleNumber;
}


/* FUNCTIONALITY */
void GroceryItem::PrintItem() const {
	cout << "item: " << _itemName << ", category: " << _itemCategory << ", section: " << _storeSection << ", aisle: " << _aisleNumber << endl;
}