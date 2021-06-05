#pragma once
#include <vector>
#include "GroceryItem.h"
using std::vector;

class StoreItems
{
	vector<GroceryItem> allItems;
public:
	//StoreItems();
	//~StoreItems();
	bool AddStoreItem(GroceryItem* newItem);
	unsigned int GetTotalNumItems();
	void PrintAllItems();
	GroceryItem* FindItem(string itemName);
	bool DeleteItem(string itemName);
	//remove item function?
};

