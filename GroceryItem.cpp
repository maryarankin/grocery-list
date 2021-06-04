#include <iostream>
#include "GroceryItem.h"
using namespace std;

GroceryItem::GroceryItem(string itemName, string itemCategory, string storeSection, unsigned int aisleNumber) {
		_itemName = itemName;
		_itemCategory = itemCategory;
		_storeSection = storeSection;
		_aisleNumber = aisleNumber;

	}
GroceryItem::~GroceryItem() {
	cout << _itemName << " deleted" << endl;
}
string GroceryItem::GetItemName() {
	return _itemName;
}
string GroceryItem::GetCategory() {
	return _itemCategory;
}
string GroceryItem::GetStoreSection() {
	return _storeSection;
}
unsigned int GroceryItem::GetAisleNumber() {
	return _aisleNumber;
}
void GroceryItem::PrintItem() {
	cout << "item: " << _itemName << ", category: " << _itemCategory << ", section: " << _storeSection << ", aisle: " << _aisleNumber << endl;
}