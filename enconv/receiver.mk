# File name	: receiver.mk
# Description	: This Makefile script tells how to build the receiver project.
#
#


CXX = arm-linux-gnueabihf-g++
CXXFLAGS = -std=c++14 -pg -Wall

PROJECT = receiver

OBJECTS = receiver.o receiver_main.o

.PHONY : all clean rebuild

all : $(PROJECT)

$(PROJECT) : $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o $@

receiver.o : receiver.cpp receiver.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

receiver_main.o : receiver_main.cpp receiver.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@


clean :
	-rm -frv $(PROJECT) $(OBJECTS)

rebuild : clean all


