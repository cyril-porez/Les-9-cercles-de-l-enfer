CC := g++
CFLAGS := -I./include -I../Common/include
LDFLAGS := -lws2_32

SRC := ./src
INC := ./include
OBJ := ./build
EXE := ../server.exe

COMMON_SRC_FILES := $(wildcard ../Common/src/*.cpp)

SRC_FILES := $(wildcard $(SRC)/*.cpp)
OBJ_FILES := $(patsubst $(SRC)/%.cpp, $(OBJ)/%.o, $(SRC_FILES))

all: $(EXE)

$(EXE): $(OBJ_FILES)
	$(CC) $(CFLAGS) -o $@ $(OBJ_FILES) $(LDFLAGS);

$(OBJ)/%.o: $(SRC)/%.cpp $(COMMON_SRC_FILES)
	$(CC) $(CFLAGS) $^ -o $@;