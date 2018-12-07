#include <gtest/gtest.h>
#include <iostream>
#include "ut_shape.cpp"
#include "ut_sort.cpp"
int main(int argc,char **argv){
    //Shape *s=new Rectangle(0,0);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}