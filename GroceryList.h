#pragma once
#include <string>
#include <vector>
#include "GroceryItem.h"
using std::string;
using std::vector;

class GroceryList {
	string _listName;
	vector<GroceryItem*> _listItems;
public:
	GroceryList(string listName);
	//~GroceryList();
	string GetListName();
	vector<GroceryItem*> GetListItems();
	void PrintGroceryList();
	void AddToList(GroceryItem* itemToAdd);
	void DeleteFromList(GroceryItem* itemToDelete);
};