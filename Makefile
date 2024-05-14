CXX := g++
CXXFLAGS := -I./Common/include -I./Server/include -I./Client/include
LDFLAGS := -lws2_32

CLIENT_SRC_DIR := ./Client/src
CLIENT_BUILD_DIR := ./Client/build
CLIENT_BIN_DIR := ./Client/bin
CLIENT_EXE := ./Client/bin/client.exe

SERVER_SRC_DIR := ./Server/src
SERVER_BUILD_DIR := ./Server/build
SERVER_BIN_DIR := ./Server/bin
SERVER_EXE := ./Server/bin/server.exe

COMMON_SRC_DIR := ./Common/src
COMMON_BUILD_DIR := ./Common/build

CLIENT_SRCS := $(wildcard $(CLIENT_SRC_DIR)/*.cpp)
CLIENT_OBJS := $(patsubst $(CLIENT_SRC_DIR)/%.cpp,$(CLIENT_BUILD_DIR)/%.o,$(CLIENT_SRCS))

SERVER_SRCS := $(wildcard $(SERVER_SRC_DIR)/*.cpp)
SERVER_OBJS := $(patsubst $(SERVER_SRC_DIR)/%.cpp,$(SERVER_BUILD_DIR)/%.o,$(SERVER_SRCS))

COMMON_SRCS := $(wildcard $(COMMON_SRC_DIR)/*.cpp)

.PHONY: all clean fclean dirs

all: client server

client: $(CLIENT_EXE)

server: $(SERVER_EXE)

$(CLIENT_EXE): $(CLIENT_OBJS) | $(CLIENT_BIN_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $(CLIENT_OBJS) $(LDFLAGS)

$(SERVER_EXE): $(SERVER_OBJS) | $(SERVER_BIN_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $(SERVER_OBJS) $(LDFLAGS)


$(CLIENT_BUILD_DIR)/%.o: $(COMMON_SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) $^ $(COMMON_SRCS) -o $@;

$(CLIENT_BUILD_DIR)/%.o: $(CLIENT_SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) $^ $(COMMON_SRCS) -o $@;


$(SERVER_BUILD_DIR)/%.o: $(COMMON_SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) $^ $(COMMON_SRS) -o $@;

$(SERVER_BUILD_DIR)/%.o: $(SERVER_SRC_DIR)/%.cpp 
	$(CXX) $(CXXFLAGS) $^ $(COMMON_SRCS) -o $@;


dirs:
	mkdir "$(CLIENT_BUILD_DIR)"; 
	mkdir "$(CLIENT_BIN_DIR)"; 
	mkdir "$(SERVER_BUILD_DIR)"; 
	mkdir "$(SERVER_BIN_DIR)";

clean:
	rm -r $(CLIENT_BUILD_DIR) $(SERVER_BUILD_DIR);

fclean: clean
	rm -r $(CLIENT_BIN_DIR) $(SERVER_BIN_DIR);

re: fclean all