.PHONY: clean dirs run

BIN=bin
OBJ=obj
SRC=src
TEST=test
LIBS=-lgtest -lpthread
STD=c++11
OUT=$(BIN)/hw8	#out file name
OUTTEST=$(BIN)/ut_fs
OBJS=$(OBJ)/find_visitor.o $(OBJ)/info_content_visitor.o $(OBJ)/find_link_visitor.o $(OBJ)/find_node_by_pathname_visitor.o $(OBJ)/set_path_visitor.o
COMPILE=g++ -std=$(STD) -c $< -o $@
WXCOMPILE=g++ -c $< $(WXFLAG) -o $@
WXLIB=`wx-config --libs`
WXFLAG=`wx-config --cxxflags`
FILE=test_data

all: clean dirs $(OUT) run

$(OUT): src/tree_test.cpp $(OBJS)
	g++ -std=$(STD) $< $(OBJS) $(WXLIB) $(WXFLAG) -o $@

$(OUTTEST): $(TEST)/ut_fs.cpp $(TEST)/ut_fs.h $(OBJS)
	g++ -std=$(STD) $< $(OBJS) $(LIBS) -o $@

$(OBJ)/set_path_visitor.o : $(SRC)/set_path_visitor.cpp $(SRC)/set_path_visitor.h
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
	# $(OUTTEST)
	$(OUT)$(FILE)