#include <iostream>
#include "Main.h"
#include "StoreItems.h"
#include "GroceryList.h"
#include "GroceryItem.h"
using namespace std;

int main()
{
    cout << "Welcome to the Grocery List App!" << endl;
    cout << endl;

    StoreItems* storeItems = new StoreItems;
    vector<GroceryList> allGroceryLists;

    unsigned int userInput = 0;

    userInput = PrintMainMenu();

    //error checking if 1-9 isn't entered
    //if (userInput < 1 || userInput > 9) { throw new Exception }

    while (userInput != 10) {

        if (userInput == 1) {
            unsigned int numItems = storeItems->GetTotalNumItems();
            if (numItems == 0) {
                cout << "No items yet" << endl;
            }
            else {
                storeItems->PrintAllItems();
            }
            cout << endl;
        }

        else if (userInput == 2) {
            CreateItem(storeItems);
        }

        else if (userInput == 3) {
            string itemToFind;
            //MAKE THE INPUT LOWERCASE
            cout << "Please enter the name of the item you'd like to change: ";
            getline(cin, itemToFind);

            cout << endl;
            GroceryItem* foundItem = storeItems->FindItem(itemToFind);
            cout << "Found item: " << foundItem->GetItemName() << endl;
            cout << endl;

            cout << "What would you like to change?" << endl;
            unsigned int itemChangeInput = 0;
            itemChangeInput = PrintChangeItemMenu();

            while (itemChangeInput != 5) {

                if (itemChangeInput == 1) {
                    string newItemName;
                    cout << "Please enter new item name: ";
                    getline(cin, newItemName);

                    foundItem->SetItemName(newItemName);
                }
                else if (itemChangeInput == 2) {
                    string newItemCat;
                    cout << "Please enter new item category: ";
                    getline(cin, newItemCat);

                    foundItem->SetItemCategory(newItemCat);
                }
                else if (itemChangeInput == 3) {
                    string newStoreSection;
                    cout << "Please enter new store section: ";
                    getline(cin, newStoreSection);

                    foundItem->SetStoreSection(newStoreSection);
                }
                else if (itemChangeInput == 4) {
                    string stringNewAisleNum;
                    unsigned int newAisleNum;
                    cout << "Please enter new aisle number: ";
                    getline(cin, stringNewAisleNum);
                    newAisleNum = ConvertToInt(stringNewAisleNum);

                    foundItem->SetAisleNumber(newAisleNum);
                }

                cout << endl;
                cout << "Would you like to change any other aspects of this item?" << endl;
                itemChangeInput = PrintChangeItemMenu();
            }

            foundItem->PrintItem();
            cout << endl;
        }

        else if (userInput == 4) {
            string itemToDelete;
            cout << "Enter name of item to delete: "; //OR, COULD PRINT LIST OF ITEMS TO DELETE WITH # NEXT TO THEM
            getline(cin, itemToDelete);

            bool deleted = storeItems->DeleteItem(itemToDelete);
            cout << endl;

            if (deleted) {
                cout << "Successfully deleted " << itemToDelete << endl;
            }
            else {
                cout << "Could not find " << itemToDelete << endl;
            }
            cout << endl;
        }

        else if (userInput == 6) {
            string newListName;
            cout << "Enter name of new list: ";
            getline(cin, newListName);
            cout << endl;

            GroceryList* newList = new GroceryList(newListName);
            allGroceryLists.push_back(*newList);

            string itemToAdd = "X";

            cout << "Press Q when done adding items" << endl;
            cout << "Add first item to " << newListName << ": ";
            getline(cin, itemToAdd);

            while (itemToAdd != "Q") {
                GroceryItem* foundItem = storeItems->FindItem(itemToAdd);
                if (foundItem == nullptr) {
                    string createItem;
                    cout << "This item doesn't exist yet. Would you like to create it?" << endl;
                    cout << "Press Y for yes or N for no: ";
                    getline(cin, createItem);
                    if (createItem == "Y") {
                        CreateItem(storeItems);
                    }
                    else {
                        cout << "Item not created" << endl;
                        cout << endl;
                    }
                }
                else {
                    newList->AddToList(*foundItem);
                    cout << "Added " << foundItem->GetItemName() << " to list" << endl;
                    cout << endl;
                }

                cout << "Press Q when done adding items" << endl;
                cout << "Add item to " << newListName << ": ";
                getline(cin, itemToAdd);
            }
            

            //what item would you like to add?
            //that item doesn't exist - would you like to create it?
        }

        userInput = PrintMainMenu();
    }

    //refs
    //big 3
    //const

    delete storeItems;

    return 0;
}

unsigned int PrintMainMenu() {
    string stringUserInput;
    unsigned int userInput = 0;

    //NOTE: ADD OPTION FOR SEARCHING ITEMS BY CATEGORY
    cout << "MAIN MENU" << endl;
    cout << "---------------" << endl;
    cout << "1. View all items" << endl;
    cout << "2. Add new item" << endl;
    cout << "3. Edit item details" << endl;
    cout << "4. Delete item" << endl;
    cout << "5. View all grocery lists" << endl;
    cout << "6. Create new grocery list from scratch" << endl;
    cout << "7. Create new grocery list from existing list" << endl;
    cout << "8. Edit existing list" << endl;
    cout << "9. Delete grocery list" << endl;
    cout << "10. Quit" << endl;
    cout << endl;
    cout << "Please choose a menu option: ";

    getline(cin, stringUserInput);
    userInput = ConvertToInt(stringUserInput);

    if (userInput < 1 || userInput > 10) {
        cout << "Invalid input. Try again." << endl;
        cout << endl;
        userInput = PrintMainMenu();
    }

    cout << endl;

    return userInput;
}

unsigned int PrintChangeItemMenu() {
    string stringItemChangeInput;
    unsigned int itemChangeInput = 0;

    cout << "1. Item name" << endl;
    cout << "2. Item category" << endl;
    cout << "3. Store section" << endl;
    cout << "4. Aisle number" << endl;
    cout << "5. Cancel" << endl;
    cout << endl;
    cout << "Please choose an option: ";

    getline(cin, stringItemChangeInput);
    itemChangeInput = ConvertToInt(stringItemChangeInput);

    cout << endl;

    return itemChangeInput;
}

unsigned int ConvertToInt(string stringInt) {
    unsigned int convertedInt;

    try {
        convertedInt = stoi(stringInt);
    }
    catch (...) {
        cout << endl;
        cout << "Must enter a number" << endl;
        cout << "Try again: ";
        getline(cin, stringInt);
        convertedInt = ConvertToInt(stringInt);
    }

    return convertedInt;
}

void CreateItem(StoreItems* storeItems) {
    string itemName;
    cout << "Please enter the item's name: ";
    getline(cin, itemName);

    string itemCategory;
    cout << "Please enter the category of the item: ";
    getline(cin, itemCategory);

    string storeSection;
    cout << "Please enter the section where the item is found: ";
    getline(cin, storeSection);

    string stringAisleNumber;
    unsigned int aisleNumber;
    cout << "Please enter the aisle number where the item is found, or 0 if no aisle: ";
    getline(cin, stringAisleNumber);
    aisleNumber = ConvertToInt(stringAisleNumber);

    GroceryItem* newItem = new GroceryItem(itemName, itemCategory, storeSection, aisleNumber);
    bool added = storeItems->AddStoreItem(newItem);

    cout << endl;

    if (added) {
        cout << "Successfully added the following item:" << endl;
        newItem->PrintItem();
    }
    else {
        cout << "Item already exists" << endl;
    }

    cout << endl;
}
