CXX=g++
RM=rm -f
CPPFLAGS=-g -O0 -std=c++14
LDFLAGS=-g
LDLIBS= -lgtest_main -lgtest -lpthread

SRCS=test.cpp
OBJS=$(subst .cpp,.o,$(SRCS))

all: test

test: $(OBJS)
	$(CXX) $(LDFLAGS) -o test $(OBJS) $(LDLIBS)

test.o: test.cpp

clean:
	$(RM) $(OBJS)