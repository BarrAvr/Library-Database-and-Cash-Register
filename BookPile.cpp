#define _CRT_SECURE_NO_WARNINGS
#include "BookPile.h"
#include <iostream>

BookPile::BookPile() {
	ISBN = 0;
	title = "";
	author = "";
	publisher = "";
	dateAdded[0] = 0;
	dateAdded[1] = 0;
	dateAdded[2] = 0;
	wholesale_cost = 0;
	retail_price = 0;
	quantity = 0;
}

BookPile::BookPile(int nISBN, std::string ntitle, std::string nauthor, std::string npublisher, int month, int day, int year, double nwhole_sale_cost, double nretail_price, int nquantity) {
	ISBN = nISBN;
	title = ntitle;
	author = nauthor;
	publisher = npublisher;
	dateAdded[0] = month;
	dateAdded[1] = day;
	dateAdded[2] = year;
	wholesale_cost = nwhole_sale_cost;
	retail_price = nretail_price;
	quantity = nquantity;
}

int BookPile::getQuantity() {
	return quantity;
}

void BookPile::setQuantity(int q) {
	quantity = q;
}

/*****************************************************************************/
//
// Function: BookPile BookPile::operator+(int right_int)
//
// Parameters: int right_int - integer amount to add to the quantity
// (Inputs)    
//
// Outputs:    none
//
// Returns:    Bookpile with quantity increased by right_int
//
// Description: This function overloads the "+" operator with an int. When 
// used it increases the quantity of the BookPile by the int to the right of
// the "+" operator;
/*****************************************************************************/
BookPile BookPile::operator+(int right_int) {
	quantity += right_int;
	return BookPile(this->ISBN, this->title, this->author, this->publisher, this->dateAdded[0],this->dateAdded[1], this->dateAdded[2], this->wholesale_cost, this->retail_price, this->quantity);
}

/*****************************************************************************/
//
// Function: BookPile BookPile::operator+(int right_int)
//
// Parameters: none
// (Inputs)    
//
// Outputs:    none
//
// Returns:    Bookpile with quantity incremented by 1
//
// Description: This function overloads the "++" aka post-increment operator. 
// When used it increments the quantity of the BookPile by 1;
/*****************************************************************************/
BookPile BookPile::operator++(int) {
	quantity++;
	BookPile temp(this->ISBN, this->title, this->author, this->publisher, this->dateAdded[0], this->dateAdded[1], this->dateAdded[2], this->wholesale_cost, this->retail_price, this->quantity);
	return temp;
}

/*****************************************************************************/
//
// Function: BookPile BookPile::operator+(int right_int)
//
// Parameters: none
// (Inputs)    
//
// Outputs:    none
//
// Returns:    Bookpile with quantity incremented by 1
//
// Description: This function overloads the "++" aka pre-increment operator. 
// When used it increments the quantity of the BookPile by 1;
/*****************************************************************************/
BookPile BookPile::operator++() {
	quantity++;
	return BookPile(this->ISBN, this->title, this->author, this->publisher, this->dateAdded[0], this->dateAdded[1], this->dateAdded[2], this->wholesale_cost, this->retail_price, this->quantity);
}

/*****************************************************************************/
//
// Function: BookPile BookPile::operator-(int right_int)
//
// Parameters: int right_int - integer amount to remove from the quantity
// (Inputs)    
//
// Outputs:    none
//
// Returns:    Bookpile with quantity decreased by right_int
//
// Description: This function overloads the "-" operator with an int. When 
// used it decreases the quantity of the BookPile by the int to the right of
// the "-" operator;
/*****************************************************************************/
BookPile BookPile::operator-(int right_int) {
	(quantity - right_int >= 0) ? quantity -= right_int : quantity = 0;
	return BookPile(this->ISBN, this->title, this->author, this->publisher, this->dateAdded[0], this->dateAdded[1], this->dateAdded[2], this->wholesale_cost, this->retail_price, this->quantity);
}

/*****************************************************************************/
//
// Function: BookPile BookPile::operator--(int)
//
// Parameters: none
// (Inputs)    
//
// Outputs:    none
//
// Returns:    Bookpile with quantity decremented by 1
//
// Description: This function overloads the "++" aka post-decrement operator. 
// When used it decrements the quantity of the BookPile by 1;
/*****************************************************************************/
BookPile BookPile::operator--(int) {
	(quantity - 1 >= 0) ? quantity-- : quantity = 0;
	BookPile temp(this->ISBN, this->title, this->author, this->publisher, this->dateAdded[0], this->dateAdded[1], this->dateAdded[2], this->wholesale_cost, this->retail_price, this->quantity);
	return temp;
}

/*****************************************************************************/
//
// Function: BookPile BookPile::operator--()
//
// Parameters: none
// (Inputs)    
//
// Outputs:    none
//
// Returns:    Bookpile with quantity decremented by 1
//
// Description: This function overloads the "++" aka pre-decrement operator. 
// When used it decrements the quantity of the BookPile by 1;
/*****************************************************************************/
BookPile BookPile::operator--() {
	(quantity - 1 >= 0) ? quantity-- : quantity = 0;
	return BookPile(this->ISBN, this->title, this->author, this->publisher, this->dateAdded[0], this->dateAdded[1], this->dateAdded[2], this->wholesale_cost, this->retail_price, this->quantity);
}

/*****************************************************************************/
//
// Function: std::ostream& operator<<(std::ostream& output, BookPile& toPrint)
//
// Parameters: none
// (Inputs)    
//
// Outputs: some of the BookPile's members variables printed in the format: 
//          ISBN: title (retail_price) X quantity
//
// Returns: output
//
// Description: This function overloads the "<<". When used it prints
// some of the BookPile's information into the chosen output.
/*****************************************************************************/
std::ostream& operator<<(std::ostream& output, BookPile& toPrint) {
	output << toPrint.getISBN() << ": " << toPrint.getTitle() << " ($" << toPrint.getRetailPrice() << ") X ";
	if (toPrint.getQuantity() > 0) {
		output << toPrint.getQuantity() << "qty left";
	}
	else {
		output << "sold out";
	}
	return output;
}
