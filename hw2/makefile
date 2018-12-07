.PHONY : clean dict run
all: clean dict bin/hw2 run
bin/hw2 : obj/ut_main.o 
	g++ -o bin/hw2 obj/ut_main.o -lgtest -lpthread
obj/ut_main.o : test/ut_main.cpp test/ut_sort.cpp test/ut_shape.cpp src/rectangle.h  src/circle.h src/triangle.h src/sort.h src/shape.h 
	g++ -std=c++11 -c test/ut_main.cpp -o obj/ut_main.o
clean :
	rm -rf obj bin
dict :
	mkdir -p obj bin
run :
	bin/hw2