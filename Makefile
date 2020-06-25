#Main makefile
#Ref: http://nuclear.mutantstargoat.com/articles/make/#a-makefile-for-99-of-your-programs
#Ref: https://riptutorial.com/makefile/example/21376/building-from-different-source-folders-to-different-target-folders
#TODO: Compile to build folder
#TODO: Make clean only works on windows, replace with general purpose makefile?
CXX = g++
CXXFLAGS = -g

ccsrc = $(wildcard src/*.cpp)\
		$(wildcard src/utils/*.cpp)\
		$(wildcard src/hittable/*.cpp)\
		$(wildcard tests/*.cpp)
obj = $(ccsrc:.cpp=.o)
target = rtavis.exe

#DFLAGS = -lGL -lglut -lpng -lz -lm
DFLAGS = -lm

$(target): $(obj)
	$(CXX) -o $@ $^ $(CXXFLAGS) $(DFLAGS)

run:
	$(target) out\\test.ppm 384 -spp 100 -depth 50

.PHONY: clean
clean:
	del $(subst /,\\,$(obj))
	del $(target)
