CC := g++
CFLAGS := -Wall -I./Client/include -I./Server/include -I./Common/include
LDFLAGS := -lws2_32

CLIENT_SRC_DIR := ./Client/src
CLIENT_OBJ_DIR := ./Client/obj
CLIENT_BIN_DIR := ./Client/bin
CLIENT_SRC := $(wildcard $(CLIENT_SRC_DIR)/*.cpp)
CLIENT_OBJ := $(patsubst $(CLIENT_SRC_DIR)/%.cpp, $(CLIENT_OBJ_DIR)/%.o, $(CLIENT_SRC))

SERVER_SRC_DIR := ./Server/src
SERVER_OBJ_DIR := ./Server/obj
SERVER_BIN_DIR := ./Server/bin
SERVER_SRC := $(wildcard $(SERVER_SRC_DIR)/*.cpp)
SERVER_OBJ := $(patsubst $(SERVER_SRC_DIR)/%.cpp, $(SERVER_OBJ_DIR)/%.o, $(SERVER_SRC))

COMMON_SRC_DIR := ./Common/src

CLIENT_EXEC := $(CLIENT_BIN_DIR)/client.exe
SERVER_EXEC := $(SERVER_BIN_DIR)/server.exe

.PHONY: all clean run

all: $(SERVER_EXEC) $(CLIENT_EXEC)

create-dirs:
	mkdir "$(CLIENT_OBJ_DIR)";
	mkdir "$(CLIENT_BIN_DIR)";
	mkdir "$(SERVER_OBJ_DIR)";
	mkdir "$(SERVER_BIN_DIR)";

$(CLIENT_EXEC): $(CLIENT_OBJ)
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

$(SERVER_EXEC): $(SERVER_OBJ)
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

$(CLIENT_OBJ_DIR)/%.o: $(CLIENT_SRC_DIR)/%.cpp $(COMMON_SRC_DIR)/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(SERVER_OBJ_DIR)/%.o: $(SERVER_SRC_DIR)/%.cpp $(COMMON_SRC_DIR)/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

run-client: $(CLIENT_EXEC)
	./$(CLIENT_EXEC)

run-server: $(SERVER_EXEC)
	./$(SERVER_EXEC)

clean:
	rm -rf $(CLIENT_OBJ_DIR)/*.o $(SERVER_OBJ_DIR)/*.o $(CLIENT_EXEC) $(SERVER_EXEC)