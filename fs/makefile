.PHONY: clean dirs run

BIN=bin
OBJ=obj
SRC=src
TEST=test
LIBS=-lgtest -lpthread
STD=c++11
OUT=$(BIN)/hw7	#out file name
OBJS=$(OBJ)/ut_fs.o $(OBJ)/find_visitor.o $(OBJ)/info_content_visitor.o $(OBJ)/find_link_visitor.o $(OBJ)/find_node_by_pathname_visitor.o
COMPILE=g++ -std=$(STD) -c $< -o $@

all: clean dirs $(OUT) run

$(OUT): $(OBJS)
	g++ -std=$(STD) $(OBJS) -o $@ $(LIBS)

$(OBJ)/ut_fs.o : $(TEST)/ut_fs.cpp $(TEST)/ut_fs.h $(SRC)/*.h
	$(COMPILE)

$(OBJ)/find_visitor.o : $(SRC)/find_visitor.cpp $(SRC)/find_visitor.h
	$(COMPILE)

$(OBJ)/info_content_visitor.o : $(SRC)/info_content_visitor.cpp $(SRC)/info_content_visitor.h
	$(COMPILE)	

$(OBJ)/find_link_visitor.o : $(SRC)/find_link_visitor.cpp $(SRC)/find_link_visitor.h
	$(COMPILE)	

$(OBJ)/find_node_by_pathname_visitor.o : $(SRC)/find_node_by_pathname_visitor.cpp $(SRC)/find_node_by_pathname_visitor.h
	$(COMPILE)

dirs:
	mkdir -p $(SRC) $(TEST) $(BIN) $(OBJ)
clean:
	rm -rf $(BIN) $(OBJ)
run:
	$(OUT)