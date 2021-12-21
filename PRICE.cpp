#include "PRICE.h"
PRICE::PRICE()
{
	cout << "Конструктор PRICE" << endl;
}
PRICE::PRICE(const PRICE& a)
{
	name_of_product = a.name_of_product;
	name_of_shop = a.name_of_shop;
	product_price = a.product_price;
	cout << "Конструктор PRICE" << endl;
}
PRICE::PRICE(string newStart, string newFinish, int newRout)
{
	name_of_product = newStart;
	name_of_shop = newFinish;
	product_price = newRout;
	cout << "Конструктор PRICE" << endl;
}
PRICE::~PRICE()
{
	cout << "Диструктор PRICE" << endl;
}
void PRICE::get()
{
	cout << "Название товара : " << name_of_product << endl;
	cout << "Название магазина : " << name_of_shop << endl;
	cout << "-------------------------------------------------"<< endl;
	cout << "|Цена товара :" << product_price << "\t\t\t\t|"<<endl;
	cout << "-------------------------------------------------" << endl;
	
	
}
void PRICE::set()
{
	cout << "Цену товара : " << endl;
	cin >> product_price;
	cin.ignore(32767, '\n');
	cout << "Введите название товара : " << endl;
	getline(cin, name_of_product);
	cout << "Введите название магазина : " << endl;
	getline(cin, name_of_shop);
}

void PRICE::red()
{
	char vibor;
	cout << "Выберите что поменять" << endl << "1 - Название товара " << endl << "2 - Название магазина" << endl << "3 - Цена товара" << endl;
	cin >> vibor;
	cin.ignore(32767, '\n');
	if (vibor == '1')
	{
		cout << "Введите название товара : " << endl;
		getline(cin, name_of_product);
	}
	else
	{
		if (vibor == '2')
		{
			
			cout << "Введите название магазина : " << endl;
			getline(cin, name_of_shop);
		}
		else
		{
			if (vibor == '3')
			{
				
				cout << "Введите цену товара : " << endl;
				cin >> product_price;
				cin.ignore(32767, '\n');
			}
			else
			{
				cout << "Неверный ввод" << endl;
			}
		}
	}
}

string PRICE::get_name_prod()
{
	return name_of_product;
}
std::ostream& operator<< (std::ostream &out, const PRICE &PRICE)
{

	out << "Название товара : " << PRICE.name_of_product << endl;
	out << "Название магазина : " << PRICE.name_of_shop << endl;
	out << "-------------------------------------------------" << endl;
	out << "|Цена товара :" << PRICE.product_price << "\t\t\t\t|" << endl;
	out << "-------------------------------------------------" << endl;
	return out;
}
std::istream& operator>> (std::istream &in, PRICE &PRICE)
{
	in >> PRICE.product_price;
	in.ignore(32767, '\n');
	getline(in, PRICE.name_of_product);
	getline(in, PRICE.name_of_shop);
	return in;
}

PRICE& PRICE::operator= (const PRICE &Route)
{
	name_of_product = Route.name_of_product;
	name_of_shop = Route.name_of_shop;
	product_price = Route.product_price;
	return *this;
}
