#pragma once
#include "GroceryItem.h"

class StoreItems
{
	GroceryItem* allItems;
	unsigned int storeCapacity;
	unsigned int totalItems;
public:
	StoreItems();
	//~StoreItems();
	void AddStoreItem(const GroceryItem& newItem);
	void PrintAllItems();
	//remove item function?
};

