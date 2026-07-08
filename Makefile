CXX := c++
CXXFLAGS := -Wall -Wextra -Werror -std=c++20 -Iinclude

LIB_SRC := src/hello_world.cpp
TEST_SRC := tests/hello_world_test.cpp

all: test

test:
	$(CXX) $(CXXFLAGS) $(LIB_SRC) $(TEST_SRC) -o test

clean:
	rm -f test

re: clean all

.PHONY: all clean re
