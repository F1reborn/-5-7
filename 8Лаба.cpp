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
	cout<<"Задание 1. \nЧасть 1. \n\n";

	cout<<"10 - "<<oct<<10<<", 100 - "<<100<<endl;
	cout<<"1000 - "<<1000<<dec<<", 10000 - "<<10000<<endl;
	cout<<"Вывод: oct - до явной отмены\n\n";

	cout<<"10 - "<<hex<<10<<", 100 - "<<100<<endl;
	cout<<"1000 - "<<1000<<dec<<", 10000 - "<<10000<<endl;
	cout<<"Вывод: hex - до явной отмены\n\n";

	cout<<"10 - "<<dec<<10<<", 100 - "<<100<<endl;
	cout<<"1000 - "<<1000<<endl;
	cout<<"Вывод: dec - до явной отмены\n\n";

	cout<<setfill('0')<<setw(10)<<11<<" "<<12<<" "<<setw(10)<<13<<endl;
	cout<<setw(10)<<14<<setfill(' ')<<15<<endl;
	cout<<"Вывод: setfill() - до явной отмены, setw() - на ближайший операнд\n\n";

	cout<<setprecision(4)<<12.3456789<<" "<<12.3456789<<endl;
	cout<<12.3456789<<setprecision(6)<<" "<<12.3456789<<endl;
	cout<<"Вывод: setprecision() - до явной отмены\n\n";

	cout<<"Часть 2. \n\n";
	cout<<"setprecision() определяет число значащих цифр, происходит округление результата\n\n";

	cout<<"Часть 3. \n\n";
	float a = 12.345678;
	cout<<setw(12)<<scientific<<a<<" - научная запись числа"<<endl;
	cout<<setw(12)<<fixed<<a<<" - обычная запись числа"<<endl;
	cout<<setw(12)<<setfill('-')<<left<<a<<" - вырвнивание влево"<<endl;
	cout<<setw(12)<<right<<a<<" - вырвнивание вправо"<<endl<<setfill(' ');

	getch();
	return 0;
}
