#ifndef circle_h
#define circle_h
#include <math.h>
#include "shape.h"
#include <string>
using namespace std;
class Circle :public Shape{
    public :
        Circle(double r):_r(r){}
        double area() const{
            return  M_PI * _r *_r;
        }
        double perimeter() const{
            return M_PI * 2 * _r;
        }
        double compactness() const{
            double area_tmp=area();
            if(area_tmp==0)
                throw string("Division by zero");
            else
                return perimeter()*perimeter()/area();
    }
    private :
        double _r;    
};
#endif