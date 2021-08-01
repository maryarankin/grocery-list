#pragma once
#include <vector>
#include "GroceryItem.h"
using std::vector;

class StoreItems
{
	vector<GroceryItem*> _allItems;
public:
	/* ACCESSORS */
	unsigned int GetTotalNumItems() const;
	vector<GroceryItem*>& GetAllStoreItems();

	/* FUNCTIONALITY */
	void PrintAllItems() const;
	bool AddStoreItem(GroceryItem* newItem);
	GroceryItem* FindItem(string itemName) const;
	bool DeleteItem(string itemName);
};