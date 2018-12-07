.PHONY : clean dict run

OUTPUT=output.txt
INPUT=input.txt
METHOD=area
ORDER=desc

all: clean dict bin/hw3 run
bin/hw3 : obj/main.o 
	g++ -o $@ obj/main.o -lgtest -lpthread
obj/main.o : src/main.cpp src/rectangle.h  src/circle.h src/triangle.h src/sort.h src/shape.h 
	g++ -std=c++11 -c src/main.cpp -o $@
clean :
	rm -rf obj bin output.txt
dict :
	mkdir -p obj bin
run :
	bin/hw3 $(INPUT) $(OUTPUT) $(METHOD) $(ORDER)