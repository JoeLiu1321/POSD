all:clean hello.out run
OUT=hello.out
$(OUT):hello.cpp
	g++ $< -o $@

clean:
	rm -f $(OUT)

run:
	./$(OUT)	