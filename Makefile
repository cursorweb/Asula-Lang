CXX = clang++
override CXXFLAGS += -g

SRCS = $(shell find . -name '.ccls-cache' -type d -prune -o -type f -name '*.cpp' -print)
OBJS = $(patsubst %.cpp, %.o, $(SRCS))

main: $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o main

clean:
	rm -f $(OBJS) main