#include "my_Stack.h"
my_Stack::my_Stack()
{
	stack_head = new Stak_elem;
	stack_size = 0;
}

my_Stack::~my_Stack()
{
	Stak_elem* bufHead = stack_head;

	for (int i = 0; i < stack_size - 2; i++)
	{
		stack_head = stack_head->pointer;
		delete bufHead;
		bufHead = stack_head;
	}
	delete stack_head;
	cout << "диструктор Keeper " << endl;
}
void my_Stack::stack_push(char a)
{
	Stak_elem* newHead;
	newHead = new Stak_elem;
	newHead->element = a;
	if (stack_size == 0)
	{
		newHead->pointer = 0;
	}
	else
	{
		newHead->pointer = stack_head;
	}
	stack_head = newHead;
	stack_size++;
};
char my_Stack::stack_pop()
{
	try
	{
		Stak_elem *bufHead = stack_head;
		if (stack_size == 0)
		{
			throw "Нет элементов";
		}
		char a(stack_head->element);
		if (stack_head->pointer != 0)
		{
			stack_head = stack_head->pointer;
			stack_size--;
			delete(bufHead);
		}
		else
		{
			stack_size--;
		}
		return a;
	}
	catch (const char* exc)
	{
		cout << exc << endl;
	}
};