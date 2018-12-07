all : clean hello run
hello:hello_world.cpp
	g++ $< `wx-config --libs` `wx-config --cxxflags` -o $@
clean:
	rm -rf hello
run:
	./hello
