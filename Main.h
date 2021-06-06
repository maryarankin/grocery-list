#pragma once
#include <string>
#include "StoreItems.h"
using std::string;

unsigned int PrintMainMenu();
unsigned int PrintChangeItemMenu();
unsigned int ConvertToInt(string stringInt);
void CreateItem(StoreItems* storeItems);