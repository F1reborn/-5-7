#ifndef FIGURE_H_INCLUDED
#define FIGURE_H_INCLUDED




class Figure {                     //�� �������������� �������-�����������
public:                            //����� ������������ ����������
    virtual double area(void) = 0; //��� � ����� S ������
    virtual void show(void) = 0;   //����� ��� � ����, ������� ������, � S
};





class Circle : public Figure{
public:
    double r;
    Circle(double r);            //�����������, ������ 1 ��� - ������ � ������ ����
    void show(void);
    double area(void);
    double* getRAddress();
};




class Rectangle : public Figure{
public:
    double a, b;                  //�����������, ������ 2 ��� - ����� ������
    Rectangle(double a);
    Rectangle(double a, double b);
    double area(void);
    double* getAAddress();
    double* getBAddress();
    void show(void);
};

#endif // FIGURE_H_INCLUDED
