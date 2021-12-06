#ifndef MATRIX_H_INCLUDED
#define MATRIX_H_INCLUDED
#include <iostream>
#include <locale>
#include <cstring>
#include <cstdlib>
#include <string>
#include <conio.h>
#include <iomanip>
#include <typeinfo>
#include <fstream>
#include "complex.cpp"

using namespace std;

template <typename T>
class Matrix{
	protected:
		T m[1024][1024];
		int a, b;
	public:
		Matrix(T **x, int l, int h);
		operator= (const Matrix&temp);
		int ThisType();
		T complex_to_T(Complex c, int type);
		T double_to_T(double d, int type);
		T int_to_T(int i, int type);
		T random_T();
		void Random(int l, int h);
		Matrix(int l, int h);
		Matrix();
		const Matrix& operator+(Matrix&x){
			T **temp = new T*[x.a];
			for(int i=0; i<x.a; i++)
				temp[i] = new T[x.b];
			for(int i=0; i<x.a; i++)
				for(int j=0; j<x.b; j++)
					temp[i][j] = x.m[i][j] + m[i][j];
			Matrix<T>* z = new Matrix<T>(temp, x.a, x.b);
			return *z;
		}
		const Matrix& operator-(Matrix&x){
			T **temp = new T*[x.a];
			for(int i=0; i<x.a; i++)
				temp[i] = new T[x.b];
			for(int i=0; i<x.a; i++)
				for(int j=0; j<x.b; j++)
					temp[i][j] = m[i][j] - x.m[i][j];
			Matrix<T>* z = new Matrix<T>(temp, x.a, x.b);
			return *z;
		}
	    friend ostream& operator << (ostream & out,const Matrix<T>&x){
			for(int i=0; i<x.a; i++){
				if(i==0) out<<"\n/   \t";
				else if (i==x.a-1) out<<"\\   \t";
				else out<<"|   \t";
				for(int j=0; j<x.b; j++) out<<x.m[i][j]<<'\t';
				if(i==0) out<<"   \\";
				else if (i==x.a-1) out<<"   /\n";
				else out<<"   |";
				out<<'\n';
			}
		}
		friend istream &operator >> (istream & in, Matrix<T>&x){
			cout<<"Нужно ли ввести параметры размера матрицы? [1 - Да, 0 - Нет]\n>";
			int f; in>>f;
			if (f){
				cout<<"Введите высоту матрицы\n>"; in>>x.a;
				cout<<"Введите ширину матрицы\n>"; in>>x.b;
			}
			for(int i=0; i<x.a; i++)
				for(int j=0; j<x.b; j++){
					cout<<"Введите a["<<i+1<<"]["<<j+1<<"]: \n>";
					if(i+j==0) in>>x.m[i][j];
					in>>x.m[i][j];
				}

		}
};


#endif // MATRIX_H_INCLUDED
