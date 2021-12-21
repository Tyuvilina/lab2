#pragma once
#include "my_list.h"
class Stak_elem
{
public:
	Stak_elem* pointer;
	char element;
};
class my_Stack
{
public:
	my_Stack();
	~my_Stack();
	void stack_push(char a);
	char stack_pop();
	int get_size() { return stack_size; };
private:
	Stak_elem* stack_head;
	int stack_size;
};
