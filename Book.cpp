#define _CRT_SECURE_NO_WARNINGS
#include "Book.h"

book::book() {
	ISBN = 0;
	author = "";
	publisher = "";
	dateAdded[0] = 0;
	dateAdded[1] = 0;
	dateAdded[2] = 0;
	wholesale_cost = 0;
	retail_price = 0;
}

book::book(int nISBN, std::string ntitle, std::string nauthor, std::string npublisher, int month, int day, int year, double nwhole_sale_cost, double nretail_price) {
	ISBN = nISBN;
	title = ntitle;
	author = nauthor;
	publisher = npublisher;
	dateAdded[0] = month;
	dateAdded[1] = day;
	dateAdded[2] = year;
	wholesale_cost = nwhole_sale_cost;
	retail_price = nretail_price;
}


int book::getISBN() {
	return ISBN;
}
std::string book::getTitle() {
	return title;
}
std::string book::getAuthor() {
	return author;
}
std::string book::getPublisher() {
	return publisher;
}
int* book::getDate() {
	return dateAdded;
}
double book::getWholeSaleCost() {
	return wholesale_cost;
}
double book::getRetailPrice() {
	return retail_price;
}

void book::setISBN(int nISBN) {
	ISBN = nISBN;
}
void book::setTitle(std::string ntitle) {
	title = ntitle;
}
void book::setAuthor(std::string nAuthor) {
	author = nAuthor;
}
void book::setPublisher(std::string nPublisher) {
	publisher = nPublisher;
}
void book::setDate(int month, int day, int year) {
	dateAdded[0]= month;
	dateAdded[1] = day;
	dateAdded[2] = year;

}
void book::setWholeSaleCost(double nCost) {
	wholesale_cost = nCost;
}
void book::setRetailPrice(double nCost) {
	retail_price = nCost;
}
/*****************************************************************************/
//
// Function: std::ostream& operator<<(std::ostream& output, BookPile& toPrint)
//
// Parameters: none
// (Inputs)    
//
// Outputs: some of the book's members variables printed in the format: 
//          ISBN: title
//
// Returns: output
//
// Description: This function overloads the "<<". When used it prints
// some of the book's information into the chosen output.
/*****************************************************************************/
std::ostream& operator<<(std::ostream& output, book& toPrint) {
	output << std::right << std::setfill('0') << std::setw(4) << toPrint.getISBN() << std::left << "\t" << toPrint.getTitle() << std::setfill(' ');
	return output;
}

