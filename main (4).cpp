#include <iostream>
#include <locale>
#include <cstdlib>
#include <cstring>
#include <string>
#include <conio.h>
#include <time.h>
#include <iomanip>
#include <typeinfo>
#include <fstream>

using namespace std;


void F2(){
	char c;

	cout << "Введите строку: ";
	cin.get(c); //считать следующий символ И поставить курсор после него
	cout << "\nc1 = " << c << endl;
	cin.get(c);
	cout << "\nc2 = " << c << endl;

	cin.putback(c); //сдвинуть курсор на символ назад И считать следующий символ
	cin.get(c);
	cout << "\nc2 = " << c << endl;

	cin.get(c);
	cout << "\nc3 = " << c << endl;
	c = cin.peek(); //считать следующий символ И оставить курсор до него
	cout << "\nc4 = " << c << endl;

	cin.get(c);
	cout << "\nc4 = " << c << endl;
	cin.ignore(); //пропустить считывание символа И поставить курсор после него
	cin.get(c);
	cout << "\nc6 = " << c << endl;
}


int main(){
	setlocale(LC_ALL, "RUS");
	srand(time(NULL));

	cout<<"Задание 5.\n\nЧасть 1\n";
	char str[255];
	cout << "Введите строку не более 10 символов: ";
	cin >> setw(10+1) >> str; //ограничение ввода на 10 символов
    cout <<"Получена строка: "<<str << endl; // вывод 10 символов
	while (cin.get()!='\n'); //очистка потока, cin.clear() не поиогает


	cout<<"\n\nЧасть 2\n";
	F2();


	getch();

	delete str;
	return 0;
}
