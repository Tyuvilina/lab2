#pragma once
#include <iostream>
#include <new>
#include <string>
using namespace std;
class PRICE
{
	string name_of_product;
	string name_of_shop;
	int product_price;
public:
	PRICE();
	PRICE(const PRICE& a);
	PRICE(string newStart, string newFinish, int newRout);
	~PRICE();
	PRICE& operator= (const PRICE &Route);
	void get();
	void set();
	void red();
	string get_name_prod();
	friend std::ostream& operator<< (std::ostream &out, const PRICE &Route);
	friend std::istream& operator>> (std::istream &in, PRICE &Route);
	
};

