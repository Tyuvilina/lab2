#include "my_list.h"
my_list::my_list()
{
	head = new elem;
	head->pointer = 0;
	size = 0;
	cout << "конструктор Keper " << endl;
};
my_list::my_list(PRICE *newElem)
{
	head = new elem;
	head->element = newElem;
	head->pointer = 0;
	size = 1;
};
my_list::~my_list()
{
	elem* bufHead = head;

	for (int i = 0; i < size - 2; i++)
	{
		head = head->pointer;
		delete bufHead->element;
		delete bufHead;
		bufHead = head;
	}
	delete head;
	cout << "диструктор Keeper " << endl;
}
PRICE my_list::pop()
{
	try
	{
		elem *bufHead = head;
		if (size == 0)
		{
			throw "Нет элементов";
		}
		PRICE a(*(head->element));
		if (head->pointer != 0)
		{
			delete(bufHead->element);
			head = head->pointer;
			size--;
			delete(bufHead);
		}
		else
		{
			delete(head->element);
			size--;
		}
		return a;
	}
	catch (const char* exc)
	{
		cout << exc << endl;
	}
};

PRICE* my_list::operator[] (const int ind)
{
	try
	{

		if ((ind >= size) || (ind < 0))
		{
			throw "неверный индекс";
		}
		elem* buf = head;
		for (int i = 0; i < size - ind - 1; i++)
		{
			buf = buf->pointer;
		}
		return (buf->element);
	}
	catch (const char* exc)
	{
		cout << exc << endl;
	}
}
void my_list::del(int ind)
{
	elem* buf = head, *buf2 = head;
	if (size == 0)
	{
		cout << "нет элементов" << endl;
	}
	else
	{
		if (ind == 0)
		{
			cout << "нет элемента" << endl;
		}
		else
		{
			if (ind == size)
			{
				pop();
			}
			else
			{
				for (int i = 1; i < size - ind; i++)
				{
					buf = buf->pointer;
				}
				buf2 = buf->pointer;
				if (ind == 1)
				{
					delete(buf2->element);
					delete(buf2);
					buf->pointer = 0;
					size--;
				}
				else
				{
					if (ind < size || ind > 0)
					{
						buf2 = buf2->pointer;
						delete(buf->pointer->element);
						delete(buf->pointer);
						buf->pointer = buf2;
						size--;
					}
					else
					{
						cout << " Нет такого элемента" << endl;
					}
				}
			}
		}

	}
}
void my_list::get()
{
	cout << "Количество товаров " << size << endl;
	cout << "Товары : " << endl;
	for (int i = 0; i < size; i++)
	{
		cout << "товар номер " << i + 1 << endl;
		cout << "_________________________________________________" << endl;
		(*this)[i]->get();
		cout << "_________________________________________________" << endl;
	}
	cout << endl;
}
void my_list::push(PRICE *a)
{
	elem* newHead;
	newHead = new elem;
	newHead->element = a;
	if (size == 0)
	{
		newHead->pointer = 0;
	}
	else
	{
		newHead->pointer = head;
	}
	head = newHead;
	size++;
};
void my_list::alphabetical_order_sort()
{
	PRICE buf;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			if ((*this)[j]->get_name_prod() > (*this)[j + 1]->get_name_prod())
			{
				buf = *(*this)[j];
				*(*this)[j] = *(*this)[j + 1];
				*(*this)[j + 1] = buf;
			}
		}
	}
}
int my_list::search_by_name(string serch_name)
{
	for (int i = 0; i < size; i++)
	{
		if ((*this)[i]->get_name_prod() == serch_name)
		{
			cout << "Искомый номер " << endl << *(*this)[i] << endl;
			return i;
		}
	}
	cout << "Искомый номер не был найден "<<endl;
	return -1;
}
int my_list::get_size()
{
	return size;
}
