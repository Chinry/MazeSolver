SRC_FILES := $(wildcard src/*.cpp)
SRC_FILES := $(filter-out src/main.cpp, $(SRC_FILES))

all:
	g++ -g -Wall -o prog src/*.cpp -lsfml-graphics -lsfml-window -lsfml-system
test:
	g++ -g -Wall -o test $(SRC_FILES) tests/*.cpp -lCppUTest -lCppUTestExt
clean:
	rm prog test
