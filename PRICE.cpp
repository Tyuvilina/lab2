#include "PRICE.h"
PRICE::PRICE()
{
	cout << "����������� PRICE" << endl;
}
PRICE::PRICE(const PRICE& a)
{
	name_of_product = a.name_of_product;
	name_of_shop = a.name_of_shop;
	product_price = a.product_price;
	cout << "����������� PRICE" << endl;
}
PRICE::PRICE(string newStart, string newFinish, int newRout)
{
	name_of_product = newStart;
	name_of_shop = newFinish;
	product_price = newRout;
	cout << "����������� PRICE" << endl;
}
PRICE::~PRICE()
{
	cout << "���������� PRICE" << endl;
}
void PRICE::get()
{
	cout << "�������� ������ : " << name_of_product << endl;
	cout << "�������� �������� : " << name_of_shop << endl;
	cout << "-------------------------------------------------"<< endl;
	cout << "|���� ������ :" << product_price << "\t\t\t\t|"<<endl;
	cout << "-------------------------------------------------" << endl;
	
	
}
void PRICE::set()
{
	cout << "���� ������ : " << endl;
	cin >> product_price;
	cin.ignore(32767, '\n');
	cout << "������� �������� ������ : " << endl;
	getline(cin, name_of_product);
	cout << "������� �������� �������� : " << endl;
	getline(cin, name_of_shop);
}

void PRICE::red()
{
	char vibor;
	cout << "�������� ��� ��������" << endl << "1 - �������� ������ " << endl << "2 - �������� ��������" << endl << "3 - ���� ������" << endl;
	cin >> vibor;
	cin.ignore(32767, '\n');
	if (vibor == '1')
	{
		cout << "������� �������� ������ : " << endl;
		getline(cin, name_of_product);
	}
	else
	{
		if (vibor == '2')
		{
			
			cout << "������� �������� �������� : " << endl;
			getline(cin, name_of_shop);
		}
		else
		{
			if (vibor == '3')
			{
				
				cout << "������� ���� ������ : " << endl;
				cin >> product_price;
				cin.ignore(32767, '\n');
			}
			else
			{
				cout << "�������� ����" << endl;
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

	out << "�������� ������ : " << PRICE.name_of_product << endl;
	out << "�������� �������� : " << PRICE.name_of_shop << endl;
	out << "-------------------------------------------------" << endl;
	out << "|���� ������ :" << PRICE.product_price << "\t\t\t\t|" << endl;
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
