
#pragma once
#include <string>
#include "Book.h"
#include "Inventory.h"
#include "BookPile.h"



void modeDisplay(char screen);

void reportComandList();
//prints report mode on screen
void reportMode(char& mode, Inventory* list, const int shelfSize);

//prints mode on screen
void modeDisplay(char mode);

//prints out inventory
//void printInventory(Inventory* list, const int shelfSize, std::string listName, int itemsPerline, int width);

//void ListBy(Inventory* inventory, const int shelfSize);