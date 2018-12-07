#include <gtest/gtest.h>
#include "../src/shape.h"
#include "../src/circle.h"
#include "../src/triangle.h"
#include "../src/rectangle.h"
using namespace std;

TEST(ShapeTest, triangle){
    Triangle tg(0,0,1,0,1,1);
    try{
        Triangle te(0,0,0,0,0,0);
    }catch(string msg){
        ASSERT_EQ(msg,"Not a triangle.");
    }
}