#pragma once
#include "PRICE.h"

	class elem
	{
	public:
		elem* pointer;
		PRICE* element;
	};

	class my_list
	{
	public:
		my_list();
		my_list(PRICE *newElem);
		~my_list();
		PRICE pop();
		PRICE* operator[] (const int ind);
		void del(int ind);
		void get();
		void push(PRICE* a);
		int get_size();
		void alphabetical_order_sort();
		int search_by_name(string serch_name);

	private:
		elem* head;
		int size;
	};