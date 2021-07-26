#pragma once
#include <string>
#include "StoreItems.h"
using std::string;

/* PRINT FUNCTIONS */
unsigned int PrintMainMenu();
unsigned int PrintChangeItemMenu();
unsigned int PrintChangeListMenu();

/* INPUT FUNCTIONS */
unsigned int ConvertToInt(string stringInt);
string MakeLowercase(string userInput);

/* OTHER FUNCTIONALITY */
bool ValidateInputRange(int userInput, int lowerRange, int upperRange);
GroceryItem* GetItemInfo(string itemName);
GroceryItem* CreateItem(StoreItems* storeItems);
GroceryItem* CreateItem(StoreItems* storeItems, string itemName);
