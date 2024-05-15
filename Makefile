# C++ compiler
CC = g++
# C++ compiler options
CXXFLAGS = -Wall -O2 -Iinclude/SDL2
# Linker options
LDFLAGS = -Lbin/SDL2.dll -lSDL2
# Header directory
ICNLUDE =

SRC_DIR = ./src
OBJ_DIR = ./obj

TARGET = main

# wildcard를 이용하여 SRC_DIR 에서 *.cc 파일 목록 추출
# notdir를 이용하여 경로가 아닌 파일 이름만 추출
SRCS = $(notdir $(wildcard $(SRC_DIR)/*.cpp $(SRC_DIR)/*/*.cpp))

# # *.cc -> *.o
OBJS = $(SRCS:.cpp=.o)

OBJECTS = $(patsubst %.o, $(OBJ_DIR)/%.o, $(OBJS))

DEPS = $(OBJECTS:.o=.d)

all: main
run: $(TARGET)
	./$(TARGET)

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cpp
	$(CC) $(CXXFLAGS) -c $< -o $@ -MD $(LDFLAGS)

$(OBJ_DIR)/%.o : $(SRC_DIR)/*/%.cpp
	$(CC) $(CXXFLAGS) -c $< -o $@ -MD $(LDFLAGS)

$(TARGET): $(OBJECTS)
	$(CC) $(CXXFLAGS) $(OBJECTS) -o $(TARGET) $(LDFLAGS)

.PHONY : clean all
clean:
	rm -f $(OBJECTS) $(DEPS) $(TARGET)

-include $(DEPS)
