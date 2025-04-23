# Variables
CXX = g++
CXXFLAGS = -g -Wall -D_CXX -Isrc
LEX = flex
YACC = bison
LDFLAGS = -lfl

# Paths
SRC_DIR = src
LEXER = $(SRC_DIR)/lexer.l
PARSER = $(SRC_DIR)/grammar.y
LEX_OUTPUT = $(SRC_DIR)/lex.yy.c
YACC_OUTPUT = $(SRC_DIR)/grammar.tab.c
YACC_HEADER = $(SRC_DIR)/grammar.tab.h
CPP_SRC = $(SRC_DIR)/classes_NT.cpp $(SRC_DIR)/tac.cpp $(SRC_DIR)/symtab_print.cpp $(SRC_DIR)/cfg.cpp $(SRC_DIR)/registerAllocator.cpp $(SRC_DIR)/selinst.cpp $(SRC_DIR)/codegen.cpp 
BIN = parser

# Targets
all: $(BIN)

$(BIN): $(LEX_OUTPUT) $(YACC_OUTPUT) $(CPP_SRC)
	$(CXX) $(CXXFLAGS) $(LEX_OUTPUT) $(YACC_OUTPUT) $(CPP_SRC) $(LDFLAGS) -o $(BIN)

$(LEX_OUTPUT): $(LEXER)
	cd $(SRC_DIR) && $(LEX) lexer.l

$(YACC_OUTPUT): $(PARSER)
	$(YACC) -d -o $(YACC_OUTPUT) $(PARSER)

clean:
	rm -f $(SRC_DIR)/lex.yy.c $(SRC_DIR)/grammar.tab.c $(SRC_DIR)/grammar.tab.h $(BIN)

.PHONY: all clean
