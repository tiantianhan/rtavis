#Main makefile
#Ref: http://nuclear.mutantstargoat.com/articles/make/#a-makefile-for-99-of-your-programs
#TODO: Compile to build folder
#TODO: Fix make clean
CXX = g++
CXXFLAGS = -g

ccsrc = $(wildcard src/*.cpp)\
				$(wildcard src/utils/*.cpp)\
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
