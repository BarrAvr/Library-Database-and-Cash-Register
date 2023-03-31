/*
UML Diagram:
 __________________________________________________________________________________
| name:
|	book
|__________________________________________________________________________________
|Member Variables:
| * ISBN : int
| * title : std::string
| * author : std::string
| * publisher : std::string
| * dateAdded[3] : int
| * wholesale_cost : double
| * retail_price : double
|__________________________________________________________________________________
|Member Functions:
| + book() :
| + book(nISBN : int, ntitle : std::string, nauthor : std::string, npublisher : std::string,
	month : int, day : int, year : int, nwhole_sale_cost : double, nretail_price : double) :
| + getISBN() : int
| + getTitle() : std::string
| + getAuthor() : std::string
| + getPublisher() : std::string
| + getDate() : int*
| + getWholeSaleCost() : double
| + getRetailPrice() : double
| + setISBN(number : int) : void
| + setName(name : std::string) : void
| + setAuthor(title : std::string) : void
| + setPublisher(publisher : std::string) : void
| + setDate(month : int, day : int, year : int) : void
| + setWholeSaleCost(nCost : double) : void
| + setRetailPrice(nCost : double) : void
| + friend operator<<(output : std::ostream&, toPrint: book&) : std::ostream&
|__________________________________________________________________________________
*/

/*
ISBN:	This is the International Standard Book Number.
		It is a unique number assigned to each book by the publisher.

Title:	The title of the book.
Author:	The book’s author.
Publisher:	The company that publishes the book.
Date Added:	The date the book was added to the inventory.
Wholesale Cost:	The price paid by Serendipity for each copy of the book.
Retail Price:	The price Serendipity is charging for each copy of the book.
*/

#pragma once

#include <iomanip>
#include <iostream>

class book {
protected:
	int ISBN;
	std::string title;
	std::string author;
	std::string publisher;
	int dateAdded[3]; //month day year
	double wholesale_cost;
	double retail_price;
public:
	book();
	book(int nISBN, std::string ntitle, std::string nauthor, std::string npublisher, int month, int day, int year, double nwhole_sale_cost, double nretail_price);

	
	int getISBN();
	std::string getTitle();
	std::string getAuthor();
	std::string getPublisher();
	int* getDate();
	double getWholeSaleCost();
	double getRetailPrice();

	void setISBN(int);
	void setTitle(std::string);
	void setAuthor(std::string);
	void setPublisher(std::string);
	void setDate(int month, int day,int year);
	void setWholeSaleCost(double);
	void setRetailPrice(double);
	friend std::ostream& operator<<(std::ostream& output, book& toPrint);
};
