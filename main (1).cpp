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
	cout<<"Задание 2. \n\n";

	cout<<"Форматирующие функции-члены класса ios: width() , precision() , fill()\n\n";
	cout<<"cout.width() по умолчанию: "<<cout.width()<<endl; //длина
	cout<<"cin.width() по умолчанию: "<<cin.width()<<endl;
	cout<<"cout.fill() по умолчанию: '"<<cout.fill()<<"'"<<endl; //заполнение
	cout<<"cin.fill() по умолчанию: '"<<cin.fill()<<"'"<<endl;
	cout<<"cout.precision() по умолчанию: "<<cout.precision()<<endl; //точность
	cout<<"cin.precision() по умолчанию: "<<cin.precision()<<endl<<endl;

	cout<<"Зададим \"-\" заполнителем, а минимальную ширину поля вывода - 10 и максимальную ширину поля ввода - 3"<<endl<<endl;
	cout.fill('+');cout.width(10);
	cin.fill('+');  cin.width(4);//4 - включая символ '\0'


	cout<<12345<<" "<<67890<<endl;
	cout<<12345678901234567890<<endl<<endl;

	char a[10], b[10], c[10];
	cout<<"a[10]: ";cin>>a;
	cout<<"a = "<<a<<endl;
	cin.fill('-');  cin.width(4);
	cout<<"b[10]: ";cin>>b;
	cout<<"b = "<<b<<endl;
	cout<<"c[10]: ";cin>>c;
	cout<<"c = "<<c<<endl<<endl;
	cout<<"Вывод: ширина поля форматируется только для ближайшего операнда, при вводе символ-заполнитель не имеет значения\n\n";


	cout<<"Зададим точность 10 для вывода и 3 для ввода чисел с плавющей точкой\n\n";
	cout.precision(10);
	cout<<12.3456789009871345<<endl;
	cout<<12.3456789009871345<<endl;
	cout<<12.34<<endl;
	double d1, d2;
	cin.precision(3);
	cout<<"d1: ";cin>>d1;
	cout<<"d1 = "<<d1<<endl;
	cout<<"d1: ";cin>>d2;
	cout<<"d2 = "<<d2<<endl;
	cout<<"Вывод: точность можно задать только для вывода, она распространяется до явной отмены\n\n";

	getch();
	return 0;
}
