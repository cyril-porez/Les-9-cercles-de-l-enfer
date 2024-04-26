CC := g++
CFLAGS := -Wall -I../Client/include -I../Server/include -I./include
LDFLAGS := -lws2_32

SRC_DIR := ./src
SRC_FILES := $(wildcard $(SRC_DIR)/*.cpp)

CLIENT_SRC_DIR := ../Client/src
CLIENT_OBJ_DIR := ../Client/obj
CLIENT_BIN_DIR := ../Client/bin
CLIENT_EXE := $(CLIENT_BIN_DIR)/client.exe

SERVER_SRC_DIR := ../Server/src
SERVER_OBJ_DIR := ../Server/obj
SERVER_BIN_DIR := ../Server/bin
SERVER_EXE := $(SERVER_BIN_DIR)/server.exe

SERVER_OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp, $(SERVER_OBJ_DIR)/%.o, $(SRC_FILES))
CLIENT_OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp, $(CLIENT_OBJ_DIR)/%.o, $(SRC_FILES))


all: $(SERVER_EXE) $(CLIENT_EXE)

$(SERVER_EXE): $(SERVER_OBJ_FILES)
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

$(CLIENT_EXE): $(CLIENT_OBJ_FILES)
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

$(SERVER_OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(CLIENT_OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@