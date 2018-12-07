#include "find_area_visitor.h"
#include "shape.h"
#include "complex_shapes.h"
#include <iostream>
FindAreaVisitor::FindAreaVisitor(double min, double max):_min(min),_max(max){

}
void FindAreaVisitor::visit(Shape *s){
    for(int i=0;i<s->numberOfChild();i++){
        if(s->getChild(i)->area()<=_max && s->getChild(i)->area()>=_min )
            _result.push_back(s->getChild(i));
        s->getChild(i)->acceptInner(this);
    }
}

vector<Shape *> FindAreaVisitor::findResult(){
    return _result;
}