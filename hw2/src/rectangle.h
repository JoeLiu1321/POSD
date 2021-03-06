#ifndef rectangle_h
#define rectangle_h
#include "shape.h"
class Rectangle :public Shape{
public:
    Rectangle(double l, double w):_l(l), _w(w){}
    double area() const{
        return _l * _w;
    }
    double perimeter() const{
        return (_l + _w) * 2;
    }
    double compactness() const{
        double area_tmp=area();
        cout << "triangle area = " << area_tmp <<endl<<"perimeter = "<<perimeter()<<endl;
        if(area_tmp==0)
            throw string("Division by zero");
        else
            return perimeter()*perimeter()/area();
    }
private:
    double _l,_w;
};
#endif