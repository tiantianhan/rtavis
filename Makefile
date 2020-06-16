#Main makefile
#Ref: http://nuclear.mutantstargoat.com/articles/make/#a-makefile-for-99-of-your-programs
CXX = g++
CXXFLAGS = -g

ccsrc = $(wildcard *.cpp)\
				$(wildcard utils/*.cpp)\
				$(wildcard tests/*.cpp)
obj = $(ccsrc:.cpp=.o)

#DFLAGS = -lGL -lglut -lpng -lz -lm
DFLAGS = -lm

main: $(obj)
	$(CXX) -o $@ $^ $(CXXFLAGS) $(DFLAGS)

run:
		main

.PHONY: clean
clean:
	-rm -f $(obj) main
