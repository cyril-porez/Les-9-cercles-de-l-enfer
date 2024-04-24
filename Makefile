CC := g++
CFLAGS := -Wall -I./Client/include -I./Server/include 
LDFLAGS := -lws2_32

CLIENT_SRC_DIR := ./Client/src
CLIENT_OBJ_DIR := ./Client/obj
CLIENT_SRC := $(wildcard $(CLIENT_SRC_DIR)/*.cpp)
CLIENT_OBJ := $(patsubst $(CLIENT_SRC_DIR)/%.cpp, $(CLIENT_OBJ_DIR)/%.o, $(CLIENT_SRC))

SERVER_SRC_DIR := ./Server/src
SERVER_OBJ_DIR := ./Server/obj
SERVER_SRC := $(wildcard $(SERVER_SRC_DIR)/*.cpp)
SERVER_OBJ := $(patsubst $(SERVER_SRC_DIR)/%.cpp, $(SERVER_OBJ_DIR)/%.o, $(SERVER_SRC))

CLIENT_EXEC := ./Client/bin/client.exe
SERVER_EXEC := ./Server/bin/server.exe

.PHONY: all clean run

all: $(CLIENT_EXEC) $(SERVER_EXEC)

$(CLIENT_EXEC): $(CLIENT_OBJ)
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@

$(SERVER_EXEC): $(SERVER_OBJ)
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@

$(CLIENT_OBJ_DIR)/%.o: $(CLIENT_SRC_DIR)/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(SERVER_OBJ_DIR)/%.o: $(SERVER_SRC_DIR)/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

run-client: $(CLIENT_EXEC)
	./$(CLIENT_EXEC)

run-server: $(SERVER_EXEC)
	./$(SERVER_EXEC)

clean:
	rm -rf $(CLIENT_OBJ_DIR)/*.o $(SERVER_OBJ_DIR)/*.o $(CLIENT_EXEC) $(SERVER_EXEC)