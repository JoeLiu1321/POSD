.PHONY : clean
all: clean hw1 run
hw1 : ut_shape.o
	g++ -o $@ $< -lgtest -lpthread
ut_shape.o : ut_shape.cpp 
	g++ -c $< -o $@
clean :
	rm -f ut_shape.o hw1
run :
	./hw1