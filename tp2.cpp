#include "my_Stack.h"
#include <fstream>
void PRICE_menu();
void file_work();
int main()
{
	setlocale(LC_ALL, "rus");
	int vibor;
	do
	{
		system("cls");
		cout << "Выберите задание \n1 - класс PRICE \n2 - поток данных из файла \n0 - выход" << endl;
		cin >> vibor;
		if (vibor == 1)
		{
			PRICE_menu();
		}
		else
		{
			if (vibor == 2)
			{
				file_work();
			}
			else
			{
				cout << "повторите ввод" << endl;
			}
		}
	} while (vibor != 0);
	return 0;
}

void PRICE_menu()
{
	PRICE* new_price;
	my_list price_array;
	string serch_name;
	int choise, index;
	do
	{
		system("cls");
		cout << "Выберите действие c элементами:" << endl;

		cout << "1 - Добавить" << endl;
		cout << "2 - Редактировать" << endl;
		cout << "3 - Удаление" << endl;
		cout << "4 - Сортировка по названию в алфавитном порядке" << endl;
		cout << "5 - поиск по названию товара" << endl;
		cout << "6 - Вывод на экран" << endl;
		cout << "0 - выход" << endl;
		cin >> choise;
		switch (choise)
		{
		case 1:
			cout << "Введите цену, название товара и название магазина" << endl;
			new_price = new PRICE;
			cin >> *new_price;
			price_array.push(new_price);
			break;
		case 2:
			price_array.get();
			cout << "Введите индекс товара для изменения" << endl;
			cin >> index;
			price_array[index - 1]->red();
			break;
		case 3:
			price_array.get();
			cout << "Введите индекс товара для удаления" << endl;
			cin >> index;
			price_array.del(index);
			break;
		case 4:
			price_array.alphabetical_order_sort();
			break;
		case 5:
			cout << "Введите название товара который вы ищете" << endl;
			cin.ignore(32767, '\n');
			getline(cin, serch_name);
			price_array.search_by_name(serch_name);
			break;
		case 6:
			price_array.get();
			break;
		case 0:
			break;
		default:
			cout << "Повторите ввод" << endl;
			break;
		}
		system("pause");
	} while (choise != 0);
}
void file_work()
{
	ifstream fin("file.txt", ios_base::in);
	char symbol = ' ', prewSim;
	int count = 0;
	int i = 0;
	my_Stack stck;
	cout << "Результат переворачивания предложения" << endl;
	if (fin.is_open())
	{
		cout << "\n";
		while (!fin.eof())
		{
			do
			{
				fin.get(symbol);

				stck.stack_push(symbol);
				count++;
				if (fin.eof() != 0)
				{
					break;
				}
			} while ((symbol != '.'));

			for (int i = 0; i < count; i++)
			{
				cout << stck.stack_pop();
			}
			count = 0;
		}
		fin.close();
	}
	cout << endl;
	system("pause");
}

