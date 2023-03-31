//#define_CRT_SECURE_NO_WARNINGS
#pragma once
#include "Book.h"
#include "Inventory.h"
#include "ReportModule.h"
#include <iostream>
#include <string>
#include <iomanip>
#include "BookPile.h"

using namespace std;



int main()
{
	char screen = 'C';
	const int shelfSize = 25;
	Inventory BookStore;
	
	BookPile inventory[shelfSize];
	BookPile book();
	
	BookPile book1(666,"Necronomicon", "HP lovecraft", "cathulu", "date", 1, 5, 1);
	BookPile book2(1031,"Book 1", "Ananymus","publisher", "future", 12.21, 4, 1);
	BookPile Empty(0000, "N/A", "N/A", "N/A", "N/A", 0, 0, 0);

	
	BookStore.readFile();
	inventory[0] = book1;
	inventory[1] = book2;
	BookStore.printInventory();
	//fills placeholder book shelf
	for (int i = 2; i < shelfSize; i++)
	{
		if (i < shelfSize - 4)
		{
			BookPile book3(i, "Book no name", "nothing", "Neverland", "never", 22.21, 3, 1);
			inventory[i] = book3;
		}
		else
		{
			inventory[i] = Empty;
		}
	}
	
	
	switch (3)
	{
	case 1:
		break;
	case 2:
		break;
	case 3:
		reportMode(screen,inventory,shelfSize);
		
		break;
	}
	
	return 0;
}