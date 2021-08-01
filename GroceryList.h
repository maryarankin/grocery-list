#pragma once
#include <string>
#include <vector>
#include "GroceryItem.h"
#include "StoreItems.h"
using std::string;
using std::vector;

class GroceryList {
	string _listName;
	vector<GroceryItem*> _listItems;
public:
	/* CONSTRUCTOR */
	GroceryList(string listName);

	/* ACCESSORS */
	string GetListName() const;
	vector<GroceryItem*>& GetListItems();

	/* FUNCTIONALITY */
	void PrintGroceryList() const;
	void AddItemToList(GroceryItem* itemToAdd);
	void DeleteFromList(GroceryItem* itemToDelete);
};