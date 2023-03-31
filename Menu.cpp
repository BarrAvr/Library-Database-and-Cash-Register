#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include "Book.h"
#include "Inventory.h"
#include "ReportModule.h"
#include <iostream>
#include <string>
#include <iomanip>
#include "BookPile.h"

#include <iostream>
#include <string>


using namespace std;

void cashierMode(char& mode, Inventory&);
void inventoryMode(bool& run, char& mode, Inventory&);
void queryReport(bool& run, char& mode, Inventory* BookStore, int shelfSize, char& screen);
bool user_navigator(char& screen, int& userComand, int numberOfuserOptions);

int main() 
{
	char screen = 'E'; // main menu
	const int shelfSize = 25;
	Inventory BookStore;

	//BookPile inventory[shelfSize];

	//reads files from "books.txt"
	BookStore.readFile();


	// final project start
	bool run;
	bool operating = true;
	while (screen != 'D')
	{
		int input;
		string mode;
		if (screen == 'E')
		{
			system("CLS");
			cout << "Enter Letter to change modes\n"
				<< "[A]: Cashier Mode\n"
				<< "[B]: Inventory Mode\n"
				<< "[C]: Query Report\n"
				<< "[D]: Exit System\n";
		}

		user_navigator(screen, input, 0);

		if (screen == 'A') {
			//"CASHIER MODE";
			input = 1;
		}
		else if (screen == 'B') {
			//"INVENTORY MODE";
			input = 2;
		}
		else if (screen == 'C') {
			//"QUERY REPORT";
			input = 3;
		}
		else if (screen == 'D') {
			cout << "Exiting..." << endl;
			input = 4;
		}
		else {
			cout << "ERROR" << endl;
		}



		switch (input) 
		{
		case 1:
			cashierMode(screen, BookStore);
			break;
		case 2:
			inventoryMode(run, screen, BookStore);
			break;
		case 3:
			queryReport(run, screen, &BookStore, shelfSize, screen);
			break;
		case 4:
			{
			operating = false;
			break;
			}
		default:
			cout << "Invalid input, please try again." << endl;
			break;
		}
	}
	return 0;
}


void cashierMode(char& mode, Inventory& BookStore)
{
	//BookPile cart[25];
	Inventory cart;
	bool run = true;
	while (run)
	{
		//displays to user what mode the program currently is in
		modeDisplay(mode);
		//printInventory();
		//printCart();
		//printTotals();


		int in;

		BookStore.printInventory();

		cout << "Enter number to select action: \n"
			<< "[1]: Add book to cart\n"
			<< "[2]: Remove book from cart\n"
			<< "[3]: Check out\n"
			<< "[4]: Return to Main Menu (empty cart)" << endl;
		cin >> in;

		switch (in) {
		case 1:
		{
			int isbn = 0;
			int quantity;
			cout << "Please enter the ISBN# of the book you would like to add: " << endl;
			cin >> isbn;
			while (isbn <= 0 || isbn > 9999) {
				cout << "Please enter a positive four digit number for the ISBN#: " << endl;
				cin >> isbn;
			}

			cout << "Please enter the number of copies of this book you would like to add to your cart: " << endl;
			cin >> quantity;
			while (quantity <= 0) {
				cout << "Please enter a quantity greater than 0: " << endl;
				cin >> quantity;
			}
			
			//add the given amount of the given book to cart
			cart.addBook(BookStore.getBook(isbn)); //check if copy constructor works correctly
			if (quantity <= BookStore.getBook(isbn).getQuantity()) {
				cart.getBook(isbn).setQuantity(quantity);
			}
			else {
				cout << "We didn't have that many of that book left, so " << BookStore.getBook(isbn).getQuantity() << " where put in the cart" << endl; //ran out of books message
			}
			BookStore.removeBook(cart.getBook(isbn));

			break;
		}
		case 2:
		{
			int isbn = 0;
			int quantity;
			cout << "Please enter the ISBN# of the book you would like to remove: " << endl;
			cin >> isbn;
			while (isbn <= 0 || isbn > 9999) {
				cout << "Please enter a positive four digit number for the ISBN#: " << endl;
				cin >> isbn;
			}

			cout << "Please enter the number of copies of this book you would like to remove from your cart: " << endl;
			cin >> quantity;
			while (quantity <= 0) {
				cout << "Please enter a quantity greater than 0: " << endl;
				cin >> quantity;
			}

			//add the given amount of the given book to cart
			BookStore.addBook(cart.getBook(isbn));
			if (quantity <= cart.getBook(isbn).getQuantity()) {
				BookStore.getBook(isbn).setQuantity(quantity);
			}
			else {
				cout << "We didn't have that many of that book left in cart, so " << cart.getBook(isbn).getQuantity() << " where removed from the cart" << endl; //ran out of books message
			}
			cart.removeBook(BookStore.getBook(isbn));
			break;

			//delete the given amount of the given book in cart
		}
		case 3:
		{
			//printReciept
			string temp;
			cart.printInventory();
			cout << "Enter anything to go back to menu: ";
			system("pause");
			run = false;
			break;
		}
		case 4:
		{
			//put everything from cart back into bookstore, and tell user
			string temp;
			cout << "Enter anything to go back to menu: ";
			system("pause");
			mode = 'E';
			run = false;
			break;
		}
		system("CLS");

		}

	}

}

//we need to check for error cases and need to finish the selection code
void inventoryMode(bool& run, char& mode, Inventory& BookStore)
{
	run = true;
	while (run) {
		modeDisplay(mode);
		//printInventory();
		//printSelectedBook();

		BookStore.printInventory();
		cout << endl;

		int in;
		cout << "Commands:\n"
			<< "[1]: Select a new book:\n"
			<< "[2]: Add new book:\n"
			<< "[3]: Delete existing book:\n"
			<< "[4]: Edit Existing book:\n"
			<< "[5]: Return to Main Menu: " << endl;
		cin >> in;

		//select mode
		switch (in) {
		case 1:
			int isbn;
			cout << "Please enter the ISBN# of the book you would like to select: " << endl;
			cin >> isbn;
			//select book
			break;

		case 2:
		{
			int isbn;
			int month, day, year;
			string title;
			string author;
			string publisher;
			string dateAdded;

			int quantityOnHand;

			double retailPrice;
			double wholeSaleCost;

			cout << "Please enter the information when prompted: " << endl;
			cout << "ISBN#: " << endl;
			cin >> isbn;
			while (isbn <= 0 || isbn > 9999) {
				cout << "Please enter a positive four digit number for the ISBN#: " << endl;
				cin >> isbn;
			}
			cout << "Title: " << endl;
			cin >> title;
			cout << "Author: " << endl;
			cin >> author;
			cout << "Publisher: " << endl;
			cin >> publisher;
			cout << "Quantity-On-Hand: " << endl;
			cin >> quantityOnHand;
			cout << "Retail Price: " << endl;
			cin >> retailPrice;
			while (retailPrice <= 0) {
				cout << "Please enter a positive number for the retail price: " << endl;
				cin >> retailPrice;
			}
			cout << "Wholesale Cost: " << endl;
			cin >> wholeSaleCost;
			while (wholeSaleCost <= 0) {
				cout << "Please enter a positive number for the whole sale cost: " << endl;
				cin >> wholeSaleCost;
			}
			cout << "Date Added: " << endl;
			cout << "Month (number 1 - 12): " << endl;
			cin >> month;
			while (month > 12 || month < 1) {
				cout << "Enter a number from 1 to 12 for the month: ";
				cin >> month;
			}
			cout << "Day: " << endl;
			cin >> day;
			cout << "Year: " << endl;
			cin >> year;

			BookPile temp(isbn, title, author, publisher, month, day, year, retailPrice, wholeSaleCost, quantityOnHand);
			BookStore.addBook(temp);
			break;
		}
		case 3:
		{
			int isbn;
			cout << "Please enter the ISBN# of the book you would like to delete: " << endl;
			cin >> isbn;
			while (isbn <= 0 || isbn > 9999) {
				cout << "Please enter a positive four digit number for the ISBN#: " << endl;
				cin >> isbn;
			}
			if (BookStore.searchBookByISBN(isbn) == -1) {
				cout << "Sorry, book was not found in inventory" << endl;
			}
			else {
				cout << isbn << ": " << BookStore.getBook(isbn).getTitle() << " was deleted from the inventory" << endl;
				BookStore.removeBook(BookStore.getBook(isbn));
			}
			break;
		}
		case 4:
		{
			int isbnTemp;
			int month, day, year;
			cout << "Please enter the ISBN# of the book you would like to edit: " << endl;
			cin >> isbnTemp;
			while (isbnTemp <= 0 || isbn > 9999) {
				cout << "Please enter a positive four digit number for the ISBN#: " << endl;
				cin >> isbnTemp;
			}

			int isbn;
			string title;
			string author;
			string publisher;
			string dateAdded;

			int quantityOnHand;

			double retailPrice;
			double wholeSaleCost;

			cout << "Please enter the information when prompted: " << endl;
			cout << "ISBN#: " << endl;
			cin >> isbn;
			while (isbn <= 0 || isbn > 9999) {
				cout << "Please enter a positive four digit number for the ISBN#: " << endl;
				cin >> isbn;
			}
			while (BookStore.searchBookByISBN(isbn) == -1) {
				cout << "Sorry, book was not found in inventory." << endl;
				cout << "Enter a new ISBN#: " << endl;
				cin >> isbn;
				while (isbn <= 0 || isbn > 9999) {
					cout << "Please enter a positive four digit number for the ISBN#: " << endl;
					cin >> isbn;
				}
			}
			cout << "New Title: " << endl;
			cin >> title;
			cout << "New Author: " << endl;
			cin >> author;
			cout << "New Publisher: " << endl;
			cin >> publisher;
			cout << "New Quantity-On-Hand: " << endl;
			cin >> quantityOnHand;
			cout << "New Retail Price: " << endl;
			cin >> retailPrice;
			while (retailPrice <= 0) {
				cout << "Please enter a positive number for the retail price: " << endl;
				cin >> retailPrice;
			}
			cout << "New Wholesale Cost: " << endl;
			cin >> wholeSaleCost;
			while (wholeSaleCost <= 0) {
				cout << "Please enter a positive number for the whole sale cost: " << endl;
				cin >> wholeSaleCost;
			}
			cout << "New Date Added: " << endl;
			cout << "New Month (number 1 - 12): " << endl;
			cin >> month;
			while (month > 12 || month < 1) {
				cout << "Enter a number from 1 to 12 for the month: ";
				cin >> month;
			}
			cout << "New Day: " << endl;
			cin >> day;
			cout << "New Year: " << endl;
			cin >> year;

			BookStore.getBook(isbn) = BookPile(isbn, title, author, publisher, month, day, year, retailPrice, wholeSaleCost, quantityOnHand);
			break;
		}
		case 5:
		{
			run = false;
			mode = 'E';
			break;
		}
		system("CLS");
		}
	}
}

//Report mode
void queryReport(bool& run, char& mode,Inventory* BookStore, int shelfSize, char& screen)
{
	{
		//while on screen 'C' loopps through report comands
		while (screen=='C') {
			int userComand = 0;
			//reportMode(screen, BookStore, shelfSize);
			system("CLS");
			modeDisplay(screen);
			reportComandList();
			user_navigator(screen, userComand, 7);
			/*
			cin >> input;
			system("pause");

			system("CLS");
			
			BookStore->printInventory();
			system("pause");
			*/




			/*
						cout << "Commands:\n"
				<< "[1]: Inventory List: A list of information on all books in the inventory.\n"
				<< "[2]: Inventory Wholesale  Value List:\n"
				<< "[3]: Inventory  Retail  Value:\n"
				<< "[4]: List by Quantity\n"
				<< "[5]: List by Cost\n"
				<< "[6]: List  by  Age\n"
				<< "[7]: Return to Main Menu: " << endl;
				*/

			
			switch (userComand) {
			case 1:
			{
				//print inventory list
				system("CLS");
				BookStore->printInventoryReport();
				system("pause");
				break;
			}
			case 2:
			{
				//print inventory wholesale value list
				system("CLS");
				BookStore->inventoryWholesale();
				system("pause");
				break;
			}
			case 3:
			{
				//print invetory retail value list
				system("CLS");
				BookStore->inventoryRetail();
				system("pause");
				break;
			}
			case 4:
			{
				//print list by quantity
				system("CLS");
				BookStore->sortByQuantity();
				system("pause");
				break;
			}
			case 5:
			{
				//print list by cost
				system("CLS");
				BookStore->sortByWholeSaleCost();
				system("pause");
				break;
			}
			case 6:
			{
				//print list by age
				system("CLS");
				BookStore->sortByAge();
				system("pause");
				break;
			}
			case 7:
			{
				screen = 'E';
				break;
			}
			}
			
		}
	}
}
bool user_navigator(char& screen, int& userComand,int numberOfuserOptions)
{
	char temp = '\0';
	bool validInput = false;
	std::cout << "\t" << "-----------------------------------" << "Input" << "-----------------------------------" << std::endl;
	cout << "Reminder: letters move between modes, numbers select options in mode. " << std::endl
		<< "Valid comands: A to D";
		if (numberOfuserOptions != 0)
		{
			std::cout << ", numbers 1 to " << numberOfuserOptions;
		}
		std::cout << std::endl<< "Please enter comand: ";
	cin >> temp;
	if (temp == 'A' || temp == 'a')
	{
		screen = 'A';
		validInput = true;
	}
	
	if (temp == 'B' || temp == 'b')
	{
		screen = 'B';
		validInput = true;
	}

	if (temp == 'C' || temp == 'c')
	{
		screen = 'C';
		validInput = true;
	}

	if (temp == 'D' || temp == 'd')
	{
		screen = 'D';
		validInput = true;
	}

	if ((temp - '0') <= numberOfuserOptions&& (temp - '0') >0)
	{
		userComand = temp-'0';
		validInput = true;
	}

	if (validInput == false)
	{
		cout << "Error Invalid input: " << std::endl;;
		system("pause");
	}
	//for debug
	cout << "User comand: " << userComand << "  Screen: " << screen <<std::endl;
	
	return validInput;
}