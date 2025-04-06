//fadi.nujedat@msmail.ariel.ac.il
# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11 -g3

# Source files
SRC = main.cpp Graph.cpp Algorithms.cpp DataStructures.cpp
OBJS = $(SRC:.cpp=.o)
EXEC = main

# Test files (for future tests)
TEST_SRC = test_algorithms.cpp Graph.cpp Algorithms.cpp DataStructures.cpp
TEST_EXEC = test_algorithms

# Default target: build the main executable
all: $(EXEC)

$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(EXEC) $(OBJS)

main.o: main.cpp Graph.hpp Algorithms.hpp
Graph.o: Graph.cpp Graph.hpp
Algorithms.o: Algorithms.cpp Algorithms.hpp Graph.hpp DataStructures.hpp
DataStructures.o: DataStructures.cpp DataStructures.hpp

# Test target (optional for doctest)
test: $(TEST_EXEC)
	./$(TEST_EXEC)

$(TEST_EXEC): $(TEST_SRC)
	$(CXX) $(CXXFLAGS) -o $(TEST_EXEC) $(TEST_SRC)

# Valgrind memory check
valgrind: $(EXEC)
	valgrind --leak-check=full ./$(EXEC)

# Clean build files
clean:
	rm -f *.o $(EXEC) $(TEST_EXEC)
