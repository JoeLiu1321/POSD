#include "complex_shapes.h"

double ComplexShapes::area() const{
    double sum=0;
    for(int i=0;i<numberOfChild();i++)
        sum+=getChild(i)->area();
    return sum;    
}

double ComplexShapes::perimeter() const{
    double sum=0;
    for(int i=0;i<_shapes->size();i++)
        sum+=getChild(i)->perimeter();
    return sum;    
}
