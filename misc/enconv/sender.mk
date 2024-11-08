# File name	: sender.mk
# Description	: This Makefile script tells how to build the sender project.
#
#


CXX = arm-linux-gnueabihf-g++
CXXFLAGS = -std=c++14 -g -Wall

PROJECT = sender

OBJECTS = sender.o sender_main.o 

.PHONY : all clean rebuild show

all : $(PROJECT)

$(PROJECT) : $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o $@

sender.o : sender.cpp sender.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@


sender_main.o : sender_main.cpp sender.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@


clean :
	-rm -frv $(OBJECTS) $(PROJECT)

rebuild : clean all

show :
	@echo "PROJECT = " $(PROJECT)
	@echo "OBJECTS = " $(OBJECTS)

