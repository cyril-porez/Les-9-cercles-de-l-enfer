CC := g++
CFLAGS := -Wall -Wextra -I.\Common\include -I.\Server\include -I.\Client\include
LDFLAGS := -lws2_32

CLIENT_SRC_DIR := .\Client\src
CLIENT_INC_DIR := .\Client\include
CLIENT_BUILD_DIR := .\Client\build
CLIENT_BIN_DIR := .\Client\bin
CLIENT_EXE := $(CLIENT_BIN_DIR)\client.exe

SERVER_SRC_DIR := .\Server\src
CLIENT_INC_DIR := .\Server\include
SERVER_BUILD_DIR := .\Server\build
SERVER_BIN_DIR := .\Server\bin
SERVER_EXE := $(SERVER_BIN_DIR)\server.exe

COMMON_SRC_DIR := .\Common\src
COMMON_INC_DIR := .\Common\include
COMMON_BUILD_DIR := .\Common\build

CLIENT_SRCS := $(wildcard $(CLIENT_SRC_DIR)/*.cpp)
CLIENT_OBJS := $(patsubst $(CLIENT_SRC_DIR)/%.cpp,$(CLIENT_BUILD_DIR)/%.o,$(CLIENT_SRCS))

SERVER_SRCS := $(wildcard $(SERVER_SRC_DIR)/*.cpp)
SERVER_OBJS := $(patsubst $(SERVER_SRC_DIR)/%.cpp,$(SERVER_BUILD_DIR)/%.o,$(SERVER_SRCS))

COMMON_SRCS := $(wildcard $(COMMON_SRC_DIR)/*.cpp)
COMMON_OBJS := $(patsubst $(COMMON_SRC_DIR)/%.cpp,$(COMMON_BUILD_DIR)/%.o,$(COMMON_SRCS))

.PHONY: all clean fclean dirs

all: server client

run-client:
	$(CLIENT_EXE)

run-server:
	$(SERVER_EXE)

client: $(CLIENT_EXE)
server: $(SERVER_EXE)

$(CLIENT_EXE): $(CLIENT_OBJS) $(COMMON_OBJS)
	$(CC) $(CFLAGS) -o $@ $(CLIENT_OBJS) $(COMMON_OBJS) $(LDFLAGS)

$(SERVER_EXE): $(SERVER_OBJS) $(COMMON_OBJS)
	$(CC) $(CFLAGS) -o $@ $(SERVER_OBJS) $(COMMON_OBJS) $(LDFLAGS)

$(CLIENT_BUILD_DIR)/%.o: $(CLIENT_SRC_DIR)/%.cpp $(CLIENT_INC_DIR)/%.hpp
	$(CC) -c $(CFLAGS) $< -o $@ 
		
$(CLIENT_BUILD_DIR)/%.o: $(COMMON_SRC_DIR)/%.cpp $(COMMON_INC_DIR)/%.hpp
	$(CC) -c $(CFLAGS) $< -o $@


$(SERVER_BUILD_DIR)/%.o: $(SERVER_SRC_DIR)/%.cpp $(CLIENT_INC_DIR)/%.hpp
	$(CC) -c $(CFLAGS) $< -o $@

$(SERVER_BUILD_DIR)/%.o: $(COMMON_SRC_DIR)/%.cpp $(COMMON_INC_DIR)/%.hpp
	$(CC) -c $(CFLAGS) $< -o $@


$(COMMON_BUILD_DIR)/%.o: $(COMMON_SRC_DIR)/%.cpp $(COMMON_INC_DIR)/%.hpp
	$(CC) -c $(CFLAGS) $< -o $@


dirs:
	mkdir "$(CLIENT_BUILD_DIR)"; 
	mkdir "$(CLIENT_BIN_DIR)"; 
	mkdir "$(SERVER_BUILD_DIR)"; 
	mkdir "$(SERVER_BIN_DIR)";
	mkdir "$(COMMON_BUILD_DIR)";

clean:
	rmdir /s /Q "$(CLIENT_BUILD_DIR)"
	rmdir /s /Q "$(SERVER_BUILD_DIR)"
	rmdir /s /Q "$(COMMON_BUILD_DIR)"

fclean: clean
	rmdir /s /Q "$(CLIENT_BIN_DIR)"
	rmdir /s /Q "$(SERVER_BIN_DIR)"

re: fclean all