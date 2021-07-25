#pragma once
#include <vector>
#include "GroceryItem.h"
using std::vector;

class StoreItems
{
	vector<GroceryItem*> _allItems;
public:
	//~StoreItems();
	bool AddStoreItem(GroceryItem* newItem);
	unsigned int GetTotalNumItems();
	void PrintAllItems();
	GroceryItem* FindItem(string itemName);
	bool DeleteItem(string itemName);
};

