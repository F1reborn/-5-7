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



int main(){
	setlocale(LC_ALL, "RUS");
	srand(time(NULL));
	cout<<"Задание 3. \n\n";
	cout<<"Флаги форматирования для выполнения операций ввода-вывода\n\n";

	cout<<"Флаг boolalpha(для ввода и вывода):\n";
	bool a=false;
	cout<<"a = "<<a<<endl;
	cout.setf(ios::boolalpha);
	cout<<"a = "<<a<<endl;
	cout.unsetf(ios::boolalpha);
	cin.setf(ios::boolalpha);
	cout<<"Введите true или false: a = ";
	cin>>a;
	cin.unsetf(ios::boolalpha);
	cout<<"a = "<<a<<"\n\n";


	cout<<"Флаги(для вывода) right и oct для числа 12:\n";
	cout.unsetf(ios::dec);
	cout.setf(ios::right|ios::oct);
	cout.width(15); cout.fill('?');
	cout<<12<<"\n\n";  cout.fill(' ');
	cout.setf(ios::dec);
	cout.unsetf(ios::right|ios::oct);

	cout<<"Флаги(для вывода) showbase, uppercase, left и hex для числа 12:\n";
	cout.unsetf(ios::dec);
	cout.setf(ios::showbase|ios::uppercase|ios::left|ios::hex);
	cout.width(15); cout.fill('-');
	cout<<12<<"\n\n";  cout.fill(' ');
	cout.unsetf(ios::showbase|ios::uppercase|ios::left|ios::hex);

	cout<<"Флаги(для вывода) scientific и dec для числа 12345.6789:\n";
	cout.setf(ios::scientific|ios::dec);
	cout<<12345.6789<<"\n\n";
	cout.unsetf(ios::scientific|ios::dec);

	cout<<"Флаги(для вывода) fixed и dec для числа 12345.6789:\n";
	cout.precision(4);
	cout.setf(ios::fixed|ios::dec);
	cout<<12345.6789<<"\n\n";

	cout<<"Флаги(для вывода) showpos и internal(заполнение символом 0) для числа 12345.6789:\n";
	cout.setf(ios::showpos|ios::internal);cout.fill('0');
	cout.width(15);cout<<12345.6789<<"\n\n";cout.fill(' ');
	cout.unsetf(ios::showpos|ios::internal);

	cout<<"Флаг(для вывода) showpoint:\n";
	float f = 12345.6789;
	cout<<"cout.precision(0);\n";
	cout.precision(0);
	cout<<"f = "<<f<<"\n";
	cout.setf(ios::showpoint);
	cout<<"cout.setf(ios::showpoint);\n";
	cout<<"f = "<<f<<"\n\n";
	cout.unsetf(ios::showpoint);


	cout<<"Флаг(для ввода) skipws(установлен по умолчанию):\n";
	cin.setf(ios::skipws);
	int i;
	cout<<"Введите число с пробелами перед ним: ";
	cin>>i;
	cout<<"i = "<<i<<"\n\n";

	cout<<"Флаг unitbuf задаст вывод без буферизации. \n";

	getch();
	return 0;
}
