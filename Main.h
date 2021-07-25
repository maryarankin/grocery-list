#pragma once
#include <string>
#include "StoreItems.h"
using std::string;

unsigned int PrintMainMenu();
unsigned int PrintChangeItemMenu();
unsigned int ConvertToInt(string stringInt);
GroceryItem* CreateItem(StoreItems* storeItems);
GroceryItem* CreateItem(StoreItems* storeItems, string itemName);
unsigned int PrintChangeListMenu();