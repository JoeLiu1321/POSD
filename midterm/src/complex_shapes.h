#ifndef COMPLEX_SHAPES_H
#define COMPLEX_SHAPES_H
#include "shape.h"
#include "find_area_visitor.h"
#include <vector>
using namespace std;
class ComplexShapes:public Shape{
public:
    ComplexShapes(vector<Shape*>*shapes):_shapes(shapes){

    }
    ~ComplexShapes(){
        delete _shapes;
    }
    double area() const ;
    double perimeter() const;
    void add(Shape *s){
        _shapes->push_back(s);
    }
    Shape * getChild(int i)const{
        return _shapes->at(i);
    }
    int numberOfChild()const{
        return _shapes->size();
    }
    void accept(FindAreaVisitor *fav){
        fav->clean();
        fav->visit(this);
    }
    void acceptInner(FindAreaVisitor *fav){
        fav->visit(this);
    }
private:
    vector<Shape*>*_shapes;
};


#endif