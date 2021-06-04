#include <iostream>
#include "GroceryItem.h"
using namespace std;

int main()
{
    GroceryItem* milk = new GroceryItem("milk", "dairy", "dairy", 1);
    milk->PrintItem();
    delete milk;

    //refs
    //big 3
    //const
    //array of all possible items, ability to print it

    return 0;
}

