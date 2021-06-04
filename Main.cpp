#include <iostream>
#include "Main.h"
#include "StoreItems.h"
#include "GroceryItem.h"
using namespace std;

int main()
{
    cout << "Welcome to the Grocery List App!" << endl;
    cout << endl;

    StoreItems* storeItems = new StoreItems;

    unsigned int userInput = 0;

    userInput = PrintMenu();

    //error checking if 1-9 isn't entered
    //if (userInput < 1 || userInput > 9) { throw new Exception }
    //also ensure it's an int

    //note: get a whole line until newline in case item name has >1 word
    while (userInput != 10) {
        if (userInput == 1) {
            storeItems->PrintAllItems();
            cout << endl;
        }
        else if (userInput == 2) {
            string itemName;
            cout << "Please enter the item's name: ";
            cin >> itemName;

            string itemCategory;
            cout << "Please enter the category of the item: ";
            cin >> itemCategory;

            string storeSection;
            cout << "Please enter the section where the item is found: ";
            cin >> storeSection;

            unsigned int aisleNumber;
            cout << "Please enter the aisle number where the item is found, or 0 if no aisle: ";
            cin >> aisleNumber;

            GroceryItem* newItem = new GroceryItem(itemName, itemCategory, storeSection, aisleNumber);
            storeItems->AddStoreItem(*newItem);

            cout << endl;
            cout << "Successfully added the following item:" << endl;
            newItem->PrintItem();
            
            cout << endl;
        }
        else if (userInput == 6) {
            //what item would you like to add?
            //that item doesn't exist - would you like to create it?
        }

        userInput = PrintMenu();
    }

    //refs
    //big 3
    //const
    //array of all possible items, ability to print it

    delete storeItems;

    return 0;
}

unsigned int PrintMenu() {
    unsigned int userInput = 0;

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

    cin >> userInput;

    cout << endl;

    return userInput;
}

