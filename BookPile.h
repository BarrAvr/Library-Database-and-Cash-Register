/*
UML Diagram:
 __________________________________________________________________________________
| name:
|	BookPile
|__________________________________________________________________________________
|Member Variables:
| * ISBN : int
| * title : std::string
| * author : std::string
| * publisher : std::string
| * dateAdded[3] : int
| * wholesale_cost : double
| * retail_price : double
| - quantity : int
|__________________________________________________________________________________
|Member Functions:
| + BookPile() :
| + BookPile(nISBN : int, ntitle : std::string, nauthor : std::string, npublisher : std::string,
	month : int, day : int, year : int, nwhole_sale_cost : double, nretail_price : double, quantity : int) :
| + getISBN() : int
| + getTitle() : std::string
| + getAuthor() : std::string
| + getPublisher() : std::string
| + getDate() : int*
| + getWholeSaleCost() : double
| + getRetailPrice() : double
| + getQuantity() : int
| + setISBN(number : int) : void
| + setName(name : std::string) : void
| + setAuthor(title : std::string) : void
| + setPublisher(publisher : std::string) : void
| + setDate(month : int, day : int, year : int) : void
| + setWholeSaleCost(nCost : double) : void
| + setRetailPrice(nCost : double) : void
| + setQuantity(quantity : int) : void
| + operator+(right_int : int) : BookPile
| + operator++( : int) : BookPile
| + operator+() : BookPile
| + operator-(right_int : int) : BookPile
| + operator--( : int) : BookPile
| + operator--() : BookPile
| + friend operator<<(output : std::ostream&, toPrint: BookPile&) : std::ostream&
|__________________________________________________________________________________
*/

/*
ISBN:	This is the International Standard Book Number.
		It is a unique number assigned to each book by the publisher.

Title:	The title of the book.
Author:	The book’s author.
Publisher:	The company that publishes the book.
Date Added:	The date the book was added to the inventory.
Quantity-On-Hand:	The number of copies of the book in inventory.
Wholesale Cost:	The price paid by Serendipity for each copy of the book.
Retail Price:	The price Serendipity is charging for each copy of the book.
*/

#pragma once
#include "Book.h"

class Inventory;

class BookPile : public book {
	friend class Inventory;
private:
	int quantity;
public:

	BookPile();
	
	BookPile(int nISBN, std::string ntitle, std::string nauthor, std::string npublisher, int month, int day, int year, double nwhole_sale_cost, double nretail_price, int nquantity);

	
	int getQuantity();
	
	void setQuantity(int);
	BookPile operator+(int);
	BookPile operator++(int);
	BookPile operator++();
	BookPile operator-(int);
	BookPile operator--(int);
	BookPile operator--();
	friend std::ostream& operator<<(std::ostream& output, BookPile& toPrint);
	
};