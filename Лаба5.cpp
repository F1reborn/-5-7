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
			cout<<"\nff(); из класса Base";
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
			cout<<"\nff(); из класса DERIVED";
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
			//d=a3; // private не инициализируется
			f=a4;
		}
//----------------------------------- 5 -----------------------------------
		friend ostream &operator << (ostream &, DERIVED&d){
		    cout<<"____________________________________________________________"<<endl;
		    cout<<" ПЕРЕГРУЗКА ОПЕРАЦИИ ВСТАВКИ В ПОТОК ДЛЯ ОБ КЛАССА DERIVED \n"<<endl;
			cout<<"    d = "<<d.Get_d()<<"     АДРЕС: "<<d.get_adr_d()<<"     //на 8 байт"<<endl;
			cout<<"    l = "<<d.l<<"     АДРЕС: "<<&d.l<<"     //на 4 байта"<<endl;
			cout<<"    i = "<<d.i<<"     АДРЕС: "<<&d.i<<"     //на 4 байта"<<endl;
			cout<<"    f = "<<d.f<<"     АДРЕС: "<<&d.f<<"     //займет 8 байт"<<endl;
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
			ff();      //сообщает о своей принадлежности к классу или глоб ур
			//выводит DERIVED. если убрать, выведет BASE
			//если убрать ff() из BASE, выведет глоб ур - з8

			::ff(); //берём функцию с глобального уровня

			//6 - модифицирует значения полей, унаследованных от базового класса
			i++;
			l+=1;
		}
};

void ff(){
	cout<<"\nff(); с глобального уровня";
}

int main()
{
	setlocale(LC_ALL, "RUS");
	cout<<"____________________________________________________________"<<endl;
    cout<<" РАЗМЕРЫ ТИПОВ \n"<<endl;
	cout<<" Base    : "<<sizeof(Base)<<endl;
	cout<<" DERIVED : "<<sizeof(DERIVED)<<endl;
	DERIVED_1 d1(1234567,1234567890,1.23456789,1.234567), d2;
	cout<<d1<<d2;
	d2.foo();
	cout<<"\n____________________________________________________________"<<endl;
    cout<<"\n Действия функции foo():\n"<<d2;
	return 0;
}

