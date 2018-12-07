#include <math.h>
class Circle{
    public :
        Circle(double r):_r(r){}
        double area() const
        {
            return  M_PI * _r *_r;
        }
        double perimeter() const
        {
            return M_PI * 2 * _r;
        }
    private :
        double _r;    
};