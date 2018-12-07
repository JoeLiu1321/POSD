#ifndef sort_h
#define sort_h
#include <vector>
#include <algorithm>
#include <functional>
#include "shape.h"
class Sort{
    public :
        Sort(std::vector<Shape*>*v):_v(v){}
        void sortArea(std::function <bool (Shape*,Shape*)> compare){
            std::sort(_v->begin(),_v->end(),compare);
        }
        void sortPerimeter(std::function <bool (Shape*,Shape*)> compare){
            std::sort(_v->begin(),_v->end(),compare);
        }
        void sortCompactness(std::function <bool (Shape*,Shape*)> compare){
            std::sort(_v->begin(),_v->end(),compare);
        }
    private :
        std::vector<Shape*>*_v;    
};
auto areaDescendingComparison = [](Shape* a,Shape* b){
    return a->area() > b->area();
};
auto areaAscendingComparison = [](Shape* a,Shape* b){
    return a->area() < b->area();
};
bool perimeterDescendingComparison(Shape *a, Shape *b){
    return a->perimeter() > b->perimeter();
}
bool perimeterAscendingComparison(Shape *a, Shape *b){
    return a->perimeter() < b->perimeter();
}

class CompactnessAscendingComparison{
    public :
        bool operator() (Shape* a,Shape* b){
            return a->compactness() < b->compactness();
        }
}compactnessAsc;

class CompactnessDescendingComparison{
    public :
        bool operator()(Shape* a,Shape* b){
            return a->compactness() > b->compactness();
        }
}compactnessDesc;
#endif