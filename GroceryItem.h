#pragma once
#include <string>
using std::string;

class GroceryItem
{
	string _itemName;
	string _itemCategory;
	string _storeSection;
	unsigned int _aisleNumber;
public:
	GroceryItem(string itemName = "no name", string itemCategory = "no cat", string storeSection = "no section", unsigned int aisleNumber = 0);
	~GroceryItem();
	string GetItemName();
	string GetCategory();
	string GetStoreSection();
	unsigned int GetAisleNumber();
	void PrintItem();
};

