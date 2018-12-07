#include <gtest/gtest.h>
#include "../src/shape.h"
#include "../src/circle.h"
#include "../src/triangle.h"
#include "../src/rectangle.h"
using namespace std;

// TEST(ShapeTest, circle){
//     Circle c(10.0);
//     ASSERT_NEAR(314.159, c.area(),0.001);
//     ASSERT_NEAR(62.8318, c.perimeter(),0.001);
//     ASSERT_NEAR(12.56636, c.compactness(),0.001);
// }
// TEST(ShapeTest, rectangle){
//     Rectangle r(10.0,5.0);
//     ASSERT_NEAR(50, r.area(),0.001);
//     ASSERT_NEAR(30, r.perimeter(),0.001);
//     ASSERT_NEAR(18, r.compactness(),0.001);
// }
TEST(ShapeTest, triangle){
    Triangle tg(0,0,1,0,1,1);
    try{
        Triangle te(0,0,0,0,0,0);
    }catch(string msg){
        ASSERT_EQ(msg,"Not a triangle.");
    }
}