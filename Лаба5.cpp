#include <iostream>
#include <locale>

using namespace std;
//----------------------------------- 1 -----------------------------------
class Base
{
    private:
		double d;
	protected:
		long l;
	public:
		int i;
		Base(int a1, long a2, double a3){
			i = a1;
			l = a2;
			d = a3;
		}
		double Get_d(){
			return d;
		}
		double* get_adr_d(){
			return &d;
		}
		void ff(){
			cout<<"\nff(); �� ������ Base";
		}
};
void ff();
//----------------------------------- 2 -----------------------------------
class DERIVED: public Base
{
    private:
		float f;
	protected:
		void ff(){
			cout<<"\nff(); �� ������ DERIVED";
		}
	public:
		               //6
		using Base::i;
		using Base::l;
		DERIVED():Base(0,0,0){
			f=0;
		}
//----------------------------------- 4 -----------------------------------
		DERIVED(int a1, long a2, double a3, float a4):Base(a1,a2,a3){
			i=a1;
			l=a2;
			//d=a3; // private �� ����������������
			f=a4;
		}
//----------------------------------- 5 -----------------------------------
		friend ostream &operator << (ostream &, DERIVED&d){
		    cout<<"____________________________________________________________"<<endl;
		    cout<<" ���������� �������� ������� � ����� ��� �� ������ DERIVED \n"<<endl;
			cout<<"    d = "<<d.Get_d()<<"     �����: "<<d.get_adr_d()<<"     //�� 8 ����"<<endl;
			cout<<"    l = "<<d.l<<"     �����: "<<&d.l<<"     //�� 4 �����"<<endl;
			cout<<"    i = "<<d.i<<"     �����: "<<&d.i<<"     //�� 4 �����"<<endl;
			cout<<"    f = "<<d.f<<"     �����: "<<&d.f<<"     //������ 8 ����"<<endl;
		}
};
//----------------------------------- 6 -----------------------------------
class DERIVED_1: public DERIVED{
	public:
		DERIVED_1():DERIVED(0,0,0,0){}
		DERIVED_1(int a1, long a2, double a3, float a4):DERIVED(a1,a2,a3,a4){}
		foo(){
//----------------------------------- 7 -----------------------------------
			Base::ff();
			ff();      //�������� � ����� �������������� � ������ ��� ���� ��
			//������� DERIVED. ���� ������, ������� BASE
			//���� ������ ff() �� BASE, ������� ���� �� - �8

			::ff(); //���� ������� � ����������� ������

			//6 - ������������ �������� �����, �������������� �� �������� ������
			i++;
			l+=1;
		}
};

void ff(){
	cout<<"\nff(); � ����������� ������";
}

int main()
{
	setlocale(LC_ALL, "RUS");
	cout<<"____________________________________________________________"<<endl;
    cout<<" ������� ����� \n"<<endl;
	cout<<" Base    : "<<sizeof(Base)<<endl;
	cout<<" DERIVED : "<<sizeof(DERIVED)<<endl;
	DERIVED_1 d1(1234567,1234567890,1.23456789,1.234567), d2;
	cout<<d1<<d2;
	d2.foo();
	cout<<"\n____________________________________________________________"<<endl;
    cout<<"\n �������� ������� foo():\n"<<d2;
	return 0;
}

