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
    vector<GroceryList*> allGroceryLists;

    unsigned int userInput = 0;

    userInput = PrintMainMenu();

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
            GroceryItem* foundItem = nullptr;

            string itemToFind;
            cout << "Please enter the name of the item you'd like to change: ";
            getline(cin, itemToFind);
            itemToFind = MakeLowercase(itemToFind);
            cout << endl;
            
            foundItem = storeItems->FindItem(itemToFind);
            if (foundItem == nullptr) {
                cout << "Could not find item" << endl;
                cout << endl;
            }
            else {
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
                        newItemName = MakeLowercase(newItemName);

                        foundItem->SetItemName(newItemName);
                    }
                    else if (itemChangeInput == 2) {
                        string newItemCat;
                        cout << "Please enter new item category: ";
                        getline(cin, newItemCat);
                        newItemCat = MakeLowercase(newItemCat);

                        foundItem->SetItemCategory(newItemCat);
                    }
                    else if (itemChangeInput == 3) {
                        string newStoreSection;
                        cout << "Please enter new store section: ";
                        getline(cin, newStoreSection);
                        newStoreSection = MakeLowercase(newStoreSection);

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
        }

        else if (userInput == 4) {
            string itemToDelete;
            cout << "Enter name of item to delete: ";
            getline(cin, itemToDelete);
            itemToDelete = MakeLowercase(itemToDelete);

            //delete item from any lists it is on first:
            for (unsigned int i = 0; i < allGroceryLists.size(); i++) {
                vector<GroceryItem*> listItems = allGroceryLists.at(i)->GetListItems();
                for (unsigned int j = 0; j < listItems.size(); j++) {
                    if (listItems.at(j)->GetItemName() == itemToDelete) {
                        allGroceryLists.at(i)->DeleteFromList(listItems.at(j));
                    }
                }
            }

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

        else if (userInput == 5) {
            if (allGroceryLists.size() == 0) {
                cout << "No grocery lists yet" << endl;
            }
            else {
                for (unsigned int i = 0; i < allGroceryLists.size(); i++) {
                    cout << (i + 1) << ". " << allGroceryLists.at(i)->GetListName() << endl;
                }
                cout << (allGroceryLists.size() + 1) << ". Cancel" << endl;
                cout << endl;
                cout << "Which list would you like to view? ";

                string stringListChoice;
                int listChoice;
                getline(cin, stringListChoice);
                listChoice = ConvertToInt(stringListChoice);

                bool validInput = ValidateInputRange(listChoice, 1, allGroceryLists.size() + 1);
                while (!validInput) {
                    cout << "Which list would you like to view? ";
                    getline(cin, stringListChoice);
                    listChoice = ConvertToInt(stringListChoice);
                    validInput = ValidateInputRange(listChoice, 1, allGroceryLists.size() + 1);
                }
                
                if (listChoice != allGroceryLists.size() + 1) {
                    unsigned int index = listChoice - 1;
                    cout << endl;
                    allGroceryLists.at(index)->PrintGroceryList();
                }
            }
            cout << endl;
        }

        else if (userInput == 6) {
            string newListName;
            cout << "Enter name of new list: ";
            getline(cin, newListName);
            newListName = MakeLowercase(newListName);
            cout << endl;

            GroceryList* newList = new GroceryList(newListName);
            allGroceryLists.push_back(newList);

            AddItemsToList(storeItems, newList);
        }

        else if (userInput == 7) {
            string listToFind;
            cout << "Which list would you like to copy? ";
            getline(cin, listToFind);
            listToFind = MakeLowercase(listToFind);
            cout << endl;

            GroceryList* foundList = nullptr;

            for (unsigned int i = 0; i < allGroceryLists.size(); i++) {
                if (allGroceryLists.at(i)->GetListName() == listToFind) {
                    foundList = allGroceryLists.at(i);
                }
            }

            if (foundList == nullptr) {
                cout << "Could not find list" << endl;
                cout << endl;
            }
            else {
                string newListName;
                cout << "Enter a name for the new list: ";
                getline(cin, newListName);
                newListName = MakeLowercase(newListName);
                cout << endl;

                GroceryList* newList = new GroceryList(newListName);

                vector<GroceryItem*> itemsToAdd = foundList->GetListItems();
                for (unsigned int i = 0; i < itemsToAdd.size(); i++) {
                    newList->GetListItems().push_back(itemsToAdd.at(i));
                }
                allGroceryLists.push_back(newList);

                cout << "Successfully created list" << endl;
                cout << endl;

                string addItems;
                cout << "Would you like to add more items to this list?" << endl;
                cout << "Press Y for yes or N for no: ";
                getline(cin, addItems);

                if (addItems == "Y" || addItems == "y") {
                    AddItemsToList(storeItems, foundList);
                }
            }
        }

        else if (userInput == 8) {
            string listToFind;
            cout << "Please enter the name of the list you'd like to change: ";
            getline(cin, listToFind);
            listToFind = MakeLowercase(listToFind);
            cout << endl;

            GroceryList* foundList = nullptr;

            for (unsigned int i = 0; i < allGroceryLists.size(); i++) {
                if (allGroceryLists.at(i)->GetListName() == listToFind) {
                    foundList = allGroceryLists.at(i);
                }
            }

            if (foundList == nullptr) {
                cout << "Could not find list" << endl;
                cout << endl;
            }
            else {
                cout << "What would you like to change?" << endl;
                unsigned int itemChangeInput = 0;
                itemChangeInput = PrintChangeListMenu();

                while (itemChangeInput != 3) {

                    if (itemChangeInput == 1) {
                        AddItemsToList(storeItems, foundList);
                    }

                    else if (itemChangeInput == 2) {
                        string itemToRemove;
                        cout << "Enter the name of item to remove: ";
                        getline(cin, itemToRemove);
                        itemToRemove = MakeLowercase(itemToRemove);

                        vector<GroceryItem*> listItems = foundList->GetListItems();

                        bool removed = false;

                        for (unsigned int i = 0; i < listItems.size(); i++) {
                            if (listItems.at(i)->GetItemName() == itemToRemove) {
                                foundList->DeleteFromList(listItems.at(i));
                                removed = true;
                                break;
                            }
                        }

                        if (removed) {
                            cout << itemToRemove << " removed" << endl;
                        }
                        else {
                            cout << "Item not found" << endl;
                        }
                    }

                    cout << endl;
                    cout << "Would you like to change anything else for this list?" << endl;
                    itemChangeInput = PrintChangeListMenu();
                }

                foundList->PrintGroceryList();
                cout << endl;
            }

            
        }

        else if (userInput == 9) {
            string listToDelete;
            cout << "Enter name of list to delete: ";
            getline(cin, listToDelete);
            listToDelete = MakeLowercase(listToDelete);
            cout << endl;

            bool deleted = false;

            for (unsigned int i = 0; i < allGroceryLists.size(); i++) {
                if (allGroceryLists.at(i)->GetListName() == listToDelete) {
                    delete allGroceryLists.at(i);
                    allGroceryLists.erase(allGroceryLists.begin() + i);
                    deleted = true;
                    break;
                }
            }

            if (deleted) {
                cout << "Successfully deleted " << listToDelete << endl;
            }
            else {
                cout << "Could not find " << listToDelete << endl;
            }
            cout << endl;
        }

        userInput = PrintMainMenu();
    }

    //deallocate memory:
    vector<GroceryItem*> allStoreItems = storeItems->GetAllStoreItems();
    for (unsigned int i = 0; i < allStoreItems.size(); i++) {
        delete allStoreItems.at(i);
    }

    delete storeItems;

    for (unsigned int i = 0; i < allGroceryLists.size(); i++) {
        delete allGroceryLists.at(i);
    }

    return 0;
}


/* PRINT FUNCTIONS */
unsigned int PrintMainMenu() {
    string stringUserInput;
    unsigned int userInput = 0;

    cout << "MAIN MENU" << endl;
    cout << "---------------" << endl;
    cout << "1. View all items" << endl;
    cout << "2. Add new item" << endl;
    cout << "3. Edit item details" << endl;
    cout << "4. Delete item" << endl;
    cout << "5. View a grocery list" << endl;
    cout << "6. Create new grocery list from scratch" << endl;
    cout << "7. Create new grocery list from existing list" << endl;
    cout << "8. Edit existing list" << endl;
    cout << "9. Delete grocery list" << endl;
    cout << "10. Quit" << endl;
    cout << endl;
    cout << "Please choose a menu option: ";

    getline(cin, stringUserInput);
    userInput = ConvertToInt(stringUserInput);

    bool validInput = ValidateInputRange(userInput, 1, 10);
    if (!validInput) {
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

    bool validInput = ValidateInputRange(itemChangeInput, 1, 5);
    if (!validInput) {
        itemChangeInput = PrintChangeItemMenu();
    }

    cout << endl;

    return itemChangeInput;
}

unsigned int PrintChangeListMenu() {
    string stringListChangeInput;
    unsigned int listChangeInput = 0;

    cout << "1. Add items" << endl;
    cout << "2. Remove an item" << endl;
    cout << "3. Cancel" << endl;
    cout << endl;
    cout << "Please choose an option: ";

    getline(cin, stringListChangeInput);
    listChangeInput = ConvertToInt(stringListChangeInput);

    bool validInput = ValidateInputRange(listChangeInput, 1, 3);
    if (!validInput) {
        listChangeInput = PrintChangeListMenu();
    }

    cout << endl;

    return listChangeInput;
}


/* INPUT FUNCTIONS */
bool ValidateInputRange(int userInput, int lowerRange, int upperRange) {
    if (userInput < lowerRange || userInput > upperRange) {
        cout << "Invalid input. Try again." << endl;
        cout << endl;
        return false;
    }
    return true;
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

string MakeLowercase(string userInput) {
    string lowercaseString = "";

    for (unsigned int i = 0; i < userInput.length(); i++) {
        char letter = userInput.at(i);
        char lowercase = tolower(letter);
        lowercaseString += lowercase;
    }

    return lowercaseString;
}


/* OTHER FUNCTIONALITY */
GroceryItem* GetItemInfo(string itemName) {
    string itemCategory;
    cout << "Please enter the category of the item: ";
    getline(cin, itemCategory);
    itemCategory = MakeLowercase(itemCategory);

    string storeSection;
    cout << "Please enter the section where the item is found: ";
    getline(cin, storeSection);
    storeSection = MakeLowercase(storeSection);

    string stringAisleNumber;
    unsigned int aisleNumber;
    cout << "Please enter the aisle number where the item is found, or 0 if no aisle: ";
    getline(cin, stringAisleNumber);
    aisleNumber = ConvertToInt(stringAisleNumber);

    GroceryItem* newItem = new GroceryItem(itemName, itemCategory, storeSection, aisleNumber);
    
    return newItem;
}

GroceryItem* CreateItem(StoreItems* storeItems) {
    string itemName;
    cout << "Please enter the item's name: ";
    getline(cin, itemName);
    itemName = MakeLowercase(itemName);

    GroceryItem* newItem = GetItemInfo(itemName);
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

    return newItem;
}

GroceryItem* CreateItem(StoreItems* storeItems, string itemName) {
    GroceryItem* newItem = GetItemInfo(itemName);
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

    return newItem;
}

void AddItemsToList(StoreItems* storeItems, GroceryList* list) {
    string itemToAdd;
    cout << "Press Q when done adding items" << endl;
    cout << "Add item to " << list->GetListName() << ": ";
    getline(cin, itemToAdd);
    itemToAdd = MakeLowercase(itemToAdd);

    while (itemToAdd != "q") {
        GroceryItem* foundItem = storeItems->FindItem(itemToAdd);
        if (foundItem == nullptr) {
            string createItem;
            cout << "This item doesn't exist yet. Would you like to create it?" << endl;
            cout << "Press Y for yes or N for no: ";
            getline(cin, createItem);
            if (createItem == "Y" || createItem == "y") {
                GroceryItem* newItem = CreateItem(storeItems, itemToAdd);
                list->AddItemToList(newItem);
                cout << "Added " << newItem->GetItemName() << " to list" << endl;
                cout << endl;
            }
            else {
                cout << "Item not created" << endl;
                cout << endl;
            }
        }
        else {
            list->AddItemToList(foundItem);
            cout << "Added " << foundItem->GetItemName() << " to list" << endl;
            cout << endl;
        }

        cout << "Press Q when done adding items" << endl;
        cout << "Add item to " << list->GetListName() << ": ";
        getline(cin, itemToAdd);
        itemToAdd = MakeLowercase(itemToAdd);
        cout << endl;
    }
}