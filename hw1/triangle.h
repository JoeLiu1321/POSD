#include <math.h>
#include <iostream>
#include <algorithm>
using namespace std;
class Triangle{
public:
    Triangle(double x1, double y1, double x2, double y2, double x3, double y3):_x1(x1), _x2(x2), _x3(x3), _y1(y1), _y2(y2), _y3(y3){
        _e1=sqrt((pow(x1-x2,2)+pow(y1-y2,2)));
        _e2=sqrt((pow(x2-x3,2)+pow(y2-y3,2)));
        _e3=sqrt((pow(x1-x3,2)+pow(y1-y3,2)));
        _s=(_e1+_e2+_e3)/2;
    }
    double area() const
    {
        return sqrt(_s * (_s-_e1) * (_s-_e2) * (_s-_e3));
    }
    double perimeter() const
    {
        return _e1+_e2+_e3;
    }
    bool isTriangle()
    {
        double tmp[3]={};
        tmp[0]=_e1;
        tmp[1]=_e2;
        tmp[2]=_e3;
        sort(tmp,tmp+3);
        return ((tmp[0]+tmp[1]>tmp[2])?true:false);
    }
private:
    double _x1,_x2,_x3,_y1,_y2,_y3,_e1,_e2,_e3,_s;    
};
