CXXFLAGS = -std=c++0x
CC = clang++
SRCS = $(wildcard *.cpp)
OBJS = $(patsubst %.cpp,%.o,$(SRCS))
HEADERS = $(wildcard *.hpp)

main: $(OBJS)

-include .depend

.depend: $(SRCS) $(HEADERS)
	$(CC) $(CXXFLAGS) -MM $(SRCS) > .depend

test: main
	-for i in {1..100}; do ./main >> testout; done
clean:
	-rm -f *.ii
	-rm -f *.i
	-rm -f *.s
	-rm -f *.o
	-rm -f *.h.gch
	-rm -f *#	
	-rm -f *~
