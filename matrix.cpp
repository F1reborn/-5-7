#include "additions.cpp"
#include "matrix.h"

using namespace std;


template <typename T>                      //обозначаем шаблоны
Matrix<T>::Matrix(T **x, int l, int h){    // конструктор, в который передаем явное значение матрицы (массив)
	for(int i=0; i<l; i++)
		for(int j=0; j<h; j++)
			m[i][j] = x[i][j];
	a = l; b = h;
}

template <typename T>                      //присваивание
Matrix<T>::operator= (const Matrix&temp){
	for(int i=0; i<temp.a; i++)
		for(int j=0; j<temp.b; j++)
			m[i][j] = temp.m[i][j];
	a = temp.a; b = temp.b;
}

template <typename T>        // 0 - int, 1 - float, 3 - complex
int Matrix<T>::ThisType(){
	int f=0;
	T temp;
	const char *s = typeid(temp).name();
	if (compare(s, typeid(Complex).name())) f=2;
	else if(compare(s, typeid(double).name())||compare(s, typeid(float).name())) f=1;
	else if(compare(s, typeid(int).name())) f=0;
	return f;
}

template <typename T>
T Matrix<T>::complex_to_T(Complex c, int type){
	WriteToTempFile(c);
	T temp;
	return ReadTempAndDelFile(temp, 'c', 'c');
}

template <typename T>
T Matrix<T>::double_to_T(double d, int type){
	WriteToTempFile(d);
	T temp;
	return ReadTempAndDelFile(temp, 'd', 'i');
}

template <typename T>
T Matrix<T>::int_to_T(int i, int type){
	WriteToTempFile(i);
	T temp;
	return ReadTempAndDelFile(temp, 'i', 'i');
}

template <typename T>
T Matrix<T>::random_T(){ //рандомное значение для шаблонного типа т
	int f = ThisType();
	T temp;
	Complex temp0;
	if(f==2)
		return complex_to_T(temp0, f);
	else if(f==1)
		return double_to_T(rand()%100 + rand()%100*1.0/100.0, f);
	else return int_to_T(rand()%100, f);
}

template <typename T>
void Matrix<T>::Random(int l, int h){ //рандомное заполнение матрицы
	for(int i=0; i<l; i++)
		for(int j=0; j<h; j++){
			m[i][j] = random_T();
		}
	a = l; b = h;
}

template <typename T> //рандомная матрица размера l h
Matrix<T>::Matrix(int l, int h){
	Random(l,h);

}

template <typename T> //рандомная матрица рандомного размера
Matrix<T>::Matrix(){
	int l = 3 + rand()%5;
	int h = 3 + rand()%5;
	Random(l,h);
}


