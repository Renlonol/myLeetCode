SRC_FILES = $(wildcard ./*.cpp)
OBJ_FILES = $(patsubst ./%.cpp, ./%.o, $(SRC_FILES))
BIN_FILES = $(patsubst ./%.cpp, ./%, $(SRC_FILES))

CC = g++
CFLAGS = -g -Wall
LIBRARY =

LIBS += $(LIBRARY:%=-l%)

all: $(BIN_FILES)

% : ./%.o
	@$(CC) $^ -o $@ $(LIBS)

.PRECIOUS: ./%.o
./%.o : %.cpp
	@echo "  cc $<"
	@$(CC) $(CFLAGS) -c $< -o $@

.PHONY : clean
clean:
	@rm -fr $(BIN_FILES) $(OBJ_FILES)
	@echo "Clean done"
