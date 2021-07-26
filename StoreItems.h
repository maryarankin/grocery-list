#pragma once
#include <vector>
#include "GroceryItem.h"
using std::vector;

class StoreItems
{
	vector<GroceryItem*> _allItems;
public:
	/* ACCESSORS */
	unsigned int GetTotalNumItems();
	vector<GroceryItem*>& GetAllStoreItems();

	/* FUNCTIONALITY */
	void PrintAllItems();
	bool AddStoreItem(GroceryItem* newItem);
	GroceryItem* FindItem(string itemName);
	bool DeleteItem(string itemName);
};

