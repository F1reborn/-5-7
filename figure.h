#ifndef FIGURE_H_INCLUDED
#define FIGURE_H_INCLUDED




class Figure {                     //ВФ переопределена классом-наследником
public:                            //имеет отличающуюся реализацию
    virtual double area(void) = 0; //выч и возвр S фигуры
    virtual void show(void) = 0;   //вывод инф о типе, размерн фигуры, её S
};





class Circle : public Figure{
public:
    double r;
    Circle(double r);            //конструктор, приним 1 арг - радиус и провер знач
    void show(void);
    double area(void);
    double* getRAddress();
};




class Rectangle : public Figure{
public:
    double a, b;                  //конструктор, приним 2 арг - длины сторон
    Rectangle(double a);
    Rectangle(double a, double b);
    double area(void);
    double* getAAddress();
    double* getBAddress();
    void show(void);
};

#endif // FIGURE_H_INCLUDED
