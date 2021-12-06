#include <iostream>
#include <locale>
#include <cstring>
#include <cstdlib>
#include <string>
#include <conio.h>
#include <iomanip>
#include <typeinfo>
#include <fstream>
#include "matrix.cpp"

using namespace std;

void str(){
	cout<<"_______________________________________________________________________\n";
}

template <class T>
void Randomnaya(){
	str();
	Matrix<T>* t0 = new Matrix<T>;
	cout<<*t0;
	str();cout<<"\n\n\n\n\n\n";
}

void NotRandom(){
	cout<<"������ �����, ����������� ����������, ��������� � ���� �������:\n";
	int a=2, b=3;
	int **r = new int*[a];//{{1,2,3},{7,8,9}};
	for(int i=0; i<a; i++)
		r[i] = new int[b];
	r[0][0]=1; r[0][1]=2; r[0][2]=3;
	r[1][0]=7; r[1][1]=8; r[1][2]=9;
	Matrix<int>* m = new Matrix<int>(r,2,3);
	cout<<*m;

	str();

	cout<<"\n��������� ����� ������ ������������* �������:\n*��������� ��������� �� � ���� \"( a + bi )\"\n\n";
	Matrix<Complex>* m2 = new Matrix<Complex>;
	cin>>*m2;
	cout<<"\n�������� ��������� �������:\n";
	cout<<*m2;
}

template <class T>
void Plus_Minus(int a, int b){
	str();
	Matrix<T>* i1 = new Matrix<T>(a,b);
	Matrix<T>* i2 = new Matrix<T>(a,b);
	Matrix<T>* i3 = new Matrix<T>(a,b);
	 *i3 = (*i1+*i2);
	cout<<"� �������:\n"<<*i1;
	cout<<"\n�������� �������:\n"<<*i2;
	cout<<"\n�������� �������:\n"<<*i3;
	str();str();
	cout<<"�� �������:\n"<<*i3;
	 *i1 = (*i3-*i2);
	cout<<"\������� �������:\n"<<*i2;
	cout<<"\n�������� �������:\n"<<*i1;
	str();cout<<"\n\n\n\n\n\n\n\n\n\n\n\n";
}

int main(){
	setlocale(LC_ALL, "RUS");
	srand(time(NULL));
	int f;
	while(1){
		cout<<"�������� �����:\n1 - ��������� ������� ������ �����;\n2 - ������ ���� �������� �������;\n3 - ��������, ��������� ��� ������ ������ �����;\n4 - �����.\n\n>";
		cin>>f;
		if(f==1){
			str();cout<<"��� Complex :\n"; Randomnaya<Complex>();
			str();cout<<"��� int :\n";	 Randomnaya<int>();
			str();cout<<"��� long :\n";	 Randomnaya<long>();
			str();cout<<"��� float :\n";	 Randomnaya<float>();
			str();cout<<"��� double :\n";	 Randomnaya<double>();
		}
		else if(f==2) NotRandom();
		else if(f==3){
			str();cout<<"��� Complex :\n"; Plus_Minus<Complex>(1+rand()%4,1+rand()%4);
			str();cout<<"��� int :\n";	 Plus_Minus<int>(1+rand()%4,1+rand()%4);
			str();cout<<"��� long :\n";	 Plus_Minus<long>(1+rand()%4,1+rand()%4);
			str();cout<<"��� float :\n";	 Plus_Minus<float>(1+rand()%4,1+rand()%4);
			str();cout<<"��� double :\n";	 Plus_Minus<double>(1+rand()%4,1+rand()%4);
		}
		else if(f==4) {
                break;
		}
		else break;
		cout<<"������� ����� ������� ��� ����������� � ����...";
		getch();
		system("cls");
	}
	return 0;
}
