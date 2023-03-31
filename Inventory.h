#pragma once
#include "Book.h"
#include "BookPile.h"

class Inventory { 
private:
	const int numOfBooks = 25;
	BookPile books[25];

public:
	Inventory();
	void printInventory();
	/*Prints the Array of books in the format discussed in the google docs*/
	void readFile();
	BookPile getBook(int bookNumber);
	void setBook(int bookNumber, BookPile book);
	/*Reads the input text from the file and stores it in the array of books*/
	void writeFile();
	/*Takes the information from the books array and stores it to a text file*/
	void sortBooks();
	/*Sorts the books in alphabetical order by book title*/
	int searchBooks(BookPile);
	/*Search for a specific isbn of a book in inventory and returns the index of the book*/
	int searchBookByISBN(int);
	/*Search for a specific isbn of a book and returns the index of the book*/
	//add book and remove book methods
	void removeBook(BookPile);
	void addBook(BookPile);

	void printInventoryReport();
	void inventoryWholesale(std::string name = "Inventory: Whole Sale");
	void inventoryRetail(std::string name = "Inventory: Retail");
	void inventoryQuantity(std::string name = "Inventory: Quantity");
	void inventoryAge(std::string name = "Inventory: Age Since Added");
	void sortByWholeSaleCost();
	void sortByQuantity();
	void sortByAge();
};