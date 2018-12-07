#include "shape.h"
#include "find_area_visitor.h"
#include <string>
using namespace std;
void Shape::add(Shape *s){
    throw string("can not add");
}
Shape * Shape::getChild(int i)const{
    throw string("can not get child");
}   
int Shape::numberOfChild()const{
    return 0;
}
