#define _CRT_SECURE_NO_WARNINGS
#include "Inventory.h"
#include <iostream>
#include <fstream>
#include <string>

Inventory::Inventory() {
	
}
void Inventory::printInventory() {
	for (int i = 0; i < numOfBooks; i++) {
		std::cout << books[i] << std::endl;
	}
}


void Inventory::readFile()
{
	int i = 0;
	double d;
	int n;
	std::ifstream file;
	std::string line;
	file.open("books.txt");
	if (file.is_open())
	{
		while (!file.eof())
		{
			file >> n;
			books[i].setISBN(n);
			//std::cout << n << std::endl;
			file.ignore(111, ' ');
			getline(file, line, ',');
			books[i].setTitle(line);
			//std::cout << line << std::endl;
			file.ignore(111, ' ');
			getline(file, line, ',');
			books[i].setAuthor(line);
			//std::cout << line << std::endl;
			file.ignore(111, ' ');
			getline(file, line, ',');
			books[i].setPublisher(line);
			//std::cout << line << std::endl;
			file.ignore(111, ' ');
			//gets month
			file >> n;
			*(books[i].getDate())=n;
			//std::cout << n << ".";
			file.ignore(111, '.');
			//gets day
			file >> n;
			*(books[i].getDate()+1) = n;
			//std::cout << n <<".";
			file.ignore(111, '.');
			//gets year
			file >> n;
			*(books[i].getDate() + 2) = n;
			file.ignore(111, ',');
			//std::cout << n << std::endl;
			//std::cout << line << std::endl;
			file >> d;
			books[i].setWholeSaleCost(d);
			file >> d;
			books[i].setRetailPrice(d);
			file >> n;
			books[i].setQuantity(n);
			i++;
		}
	}
	else
	{
		std::cout << "File Not found!" <<std::endl;
	}
	file.close();
}

BookPile Inventory::getBook(int bookNumber)
{
	return books[bookNumber];
}

void Inventory::setBook(int bookNumber,BookPile book)
{
	 books[bookNumber]=book;
}

void Inventory::addBook(BookPile b) {
	bool inInventory = false;
	bool noSpace = true;
	for (int i = 0; i < numOfBooks; i++) {
		if (books[i].getISBN() == b.getISBN()) {
			books[i].setQuantity(books[i].getQuantity() + 1);
			inInventory = true;
		}
	}
	if (!inInventory) {
		for (int i = 0; i < numOfBooks; i++) {
			if (books[i].getISBN() == 0) {
				books[i] = b;
				noSpace = false;
			}
		}
	}
	if (noSpace) {
		std::cout << "No more space in Inventory!" << std::endl;
	}
}



void Inventory::writeFile() {
	std::ofstream file;
	file.open("output.txt");
	for (int i = 0; i < numOfBooks; i++) {
		file << books[i].getTitle() << std::endl << books[i].getAuthor() << std::endl << books[i].getWholeSaleCost() << std::endl << books[i].getISBN() << std::endl << books[i].getQuantity() << std::endl << std::endl;
	}
	file.close();

}
void Inventory::sortBooks() {
	BookPile temp;
	for (int j = 0; j < numOfBooks; j++) {
		for (int i = 1; i < numOfBooks; i++) {
			if (books[i].getTitle() > books[i - 1].getTitle()) {
				temp = books[i];
				books[i] = books[i - 1];
				books[i - 1] = temp;
			}
		}
	}
	
}
int Inventory::searchBooks(BookPile b) {
	for (int i = 0; i < numOfBooks; i++) {
		if (books[i].getISBN() == b.getISBN()) {
			return i;		//book found
		}
	}
	return -1;		//no book found
}

int Inventory::searchBookByISBN(int isbn) {
	for (int i = 0; i < numOfBooks; i++) {
		if (books[i].getISBN() == isbn) {
			return i;		//book found
		}
	}
	return -1;		//no book found
}

void Inventory::removeBook(BookPile b) {
	bool inInventory = false;
	for (int i = 0; i < numOfBooks; i++) {
		if (books[i].getISBN() == b.getISBN()) {
			if (books[i].getQuantity() != 0) {
				books[i].setQuantity(books[i].getQuantity() - 1);
				inInventory = true;
			}
			else {
				BookPile b;
				books[i] = b;
			}
		}
	}
}

