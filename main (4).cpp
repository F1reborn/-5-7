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

	cout << "������� ������: ";
	cin.get(c); //������� ��������� ������ � ��������� ������ ����� ����
	cout << "\nc1 = " << c << endl;
	cin.get(c);
	cout << "\nc2 = " << c << endl;

	cin.putback(c); //�������� ������ �� ������ ����� � ������� ��������� ������
	cin.get(c);
	cout << "\nc2 = " << c << endl;

	cin.get(c);
	cout << "\nc3 = " << c << endl;
	c = cin.peek(); //������� ��������� ������ � �������� ������ �� ����
	cout << "\nc4 = " << c << endl;

	cin.get(c);
	cout << "\nc4 = " << c << endl;
	cin.ignore(); //���������� ���������� ������� � ��������� ������ ����� ����
	cin.get(c);
	cout << "\nc6 = " << c << endl;
}


int main(){
	setlocale(LC_ALL, "RUS");
	srand(time(NULL));

	cout<<"������� 5.\n\n����� 1\n";
	char str[255];
	cout << "������� ������ �� ����� 10 ��������: ";
	cin >> setw(10+1) >> str; //����������� ����� �� 10 ��������
    cout <<"�������� ������: "<<str << endl; // ����� 10 ��������
	while (cin.get()!='\n'); //������� ������, cin.clear() �� ��������


	cout<<"\n\n����� 2\n";
	F2();


	getch();

	delete str;
	return 0;
}
