#pragma once
#include <string>
using std::string;

class GroceryItem
{
	string _itemName;
	string _itemCategory;
	string _storeSection;
	unsigned int _aisleNumber;
public:
	/* CONSTRUCTOR/DESTRUCTOR */
	GroceryItem(string itemName = "no name", string itemCategory = "no cat", string storeSection = "no section", unsigned int aisleNumber = 0);
	~GroceryItem();
	
	/* ACCESSORS */
	string GetItemName() const;
	string GetCategory() const;
	string GetStoreSection() const;
	unsigned int GetAisleNumber() const;

	/* MUTATORS */
	void SetItemName(string itemName);
	void SetItemCategory(string itemCategory);
	void SetStoreSection(string storeSection);
	void SetAisleNumber(unsigned int aisleNumber);

	/* FUNCTIONALITY */
	void PrintItem() const;
};

