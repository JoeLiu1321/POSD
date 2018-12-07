#include <gtest/gtest.h>
#include "circle.h"
#include "triangle.h"
#include "rectangle.h"
using namespace std;
TEST(ShapeTest, circle) {
    Circle c(10.0);
    ASSERT_NEAR(314.159, c.area(),0.001);
    ASSERT_NEAR(62.8318, c.perimeter(),0.001);
}
TEST(ShapeTest, rectangle) {
    Rectangle r(10.0,5.0);
    ASSERT_NEAR(50, r.area(),0.001);
    ASSERT_NEAR(30, r.perimeter(),0.001);
}
TEST(ShapeTest, triangle) {
    Triangle tg(0,0,1,0,1,1);
    ASSERT_NEAR(0.5,tg.area(),0.01);
    ASSERT_TRUE(tg.isTriangle());
    ASSERT_NEAR(3.414,tg.perimeter(),0.001);
}
int main(int argc,char **argv){
   testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}