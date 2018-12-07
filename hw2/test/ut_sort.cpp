#include <gtest/gtest.h>
#include <vector>
#include "../src/sort.h"
using namespace std;
TEST(SortTest,sortPerimeter){
    Shape* shape_set[4]={new Triangle(0,0,1,0,1,1),new Circle(1.0),new Circle(1.5),new Rectangle(1.0,2.0)};
    vector<Shape*>shape_vec;
    for(int i=0;i<4;i++)
        shape_vec.push_back(shape_set[i]);  
    Sort s(&shape_vec);
    s.sortPerimeter(perimeterAscendingComparison);
    sort(shape_set,shape_set+4,perimeterAscendingComparison);
    for(int i=0;i<shape_vec.size();i++)
        ASSERT_NEAR(shape_set[i]->perimeter(),shape_vec[i]->perimeter(),0.001);  
    s.sortPerimeter(perimeterDescendingComparison);
    sort(shape_set,shape_set+4,perimeterDescendingComparison);
    for(int i=0;i<shape_vec.size();i++)
        ASSERT_NEAR(shape_set[i]->perimeter(),shape_vec[i]->perimeter(),0.001);  
}
TEST(SortTest,sortArea){
    Shape* shape_set[4]={new Triangle(0,0,1,0,1,1),new Circle(1.0),new Circle(1.5),new Rectangle(1.0,2.0)};
    vector<Shape*>shape_vec;
    for(int i=0;i<4;i++)
        shape_vec.push_back(shape_set[i]);  
    Sort s(&shape_vec);
    s.sortArea(areaAscendingComparison);
    sort(shape_set,shape_set+4,areaAscendingComparison);
    for(int i=0;i<shape_vec.size();i++)
        ASSERT_NEAR(shape_set[i]->area(),shape_vec[i]->area(),0.001);
    s.sortArea(areaDescendingComparison);
    sort(shape_set,shape_set+4,areaDescendingComparison);
    for(int i=0;i<shape_vec.size();i++)
        ASSERT_NEAR(shape_set[i]->area(),shape_vec[i]->area(),0.001);
}
TEST(SortTest,sortCompactness){
    Shape* shape_set[4]={new Triangle(0,0,1,0,1,1),new Circle(1.0),new Circle(1.5),new Rectangle(1.0,2.0)};
    vector<Shape*>shape_vec;
    for(int i=0;i<4;i++)
        shape_vec.push_back(shape_set[i]);  
    Sort s(&shape_vec);
    CompactnessAscendingComparison compactness_asc;
    CompactnessDescendingComparison compactness_desc;
    s.sortCompactness(compactness_asc);
    sort(shape_set,shape_set+4,compactness_asc);
    for(int i=0;i<shape_vec.size();i++)
        ASSERT_NEAR(shape_set[i]->compactness(),shape_vec[i]->compactness(),0.001);
        //cout << shape_set[i]->compactness()<<" = "<<shape_vec[i]->compactness() <<endl;
    s.sortCompactness(compactness_desc);
    sort(shape_set,shape_set+4,compactness_desc);
    for(int i=0;i<shape_vec.size();i++)
        ASSERT_NEAR(shape_set[i]->compactness(),shape_vec[i]->compactness(),0.001);
}