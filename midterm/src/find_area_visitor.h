#ifndef FIND_AREA_VISITOR_H
#define FIND_AREA_VISITOR_H
#include <vector>
#include <iostream>
using namespace std;
class Shape;
class FindAreaVisitor {
public:
    FindAreaVisitor(double min, double max);
    void visit(Shape* s);
    void clean(){
        _result.clear();
    }
    vector<Shape*> findResult();
private:
    double _min,_max;    
    vector<Shape *> _result;
};
#endif