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
	cout<<"������� 2. \n\n";

	cout<<"������������� �������-����� ������ ios: width() , precision() , fill()\n\n";
	cout<<"cout.width() �� ���������: "<<cout.width()<<endl; //�����
	cout<<"cin.width() �� ���������: "<<cin.width()<<endl;
	cout<<"cout.fill() �� ���������: '"<<cout.fill()<<"'"<<endl; //����������
	cout<<"cin.fill() �� ���������: '"<<cin.fill()<<"'"<<endl;
	cout<<"cout.precision() �� ���������: "<<cout.precision()<<endl; //��������
	cout<<"cin.precision() �� ���������: "<<cin.precision()<<endl<<endl;

	cout<<"������� \"-\" ������������, � ����������� ������ ���� ������ - 10 � ������������ ������ ���� ����� - 3"<<endl<<endl;
	cout.fill('+');cout.width(10);
	cin.fill('+');  cin.width(4);//4 - ������� ������ '\0'


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
	cout<<"�����: ������ ���� ������������� ������ ��� ���������� ��������, ��� ����� ������-����������� �� ����� ��������\n\n";


	cout<<"������� �������� 10 ��� ������ � 3 ��� ����� ����� � �������� ������\n\n";
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
	cout<<"�����: �������� ����� ������ ������ ��� ������, ��� ���������������� �� ����� ������\n\n";

	getch();
	return 0;
}
