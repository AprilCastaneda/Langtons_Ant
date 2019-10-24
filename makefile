###
### File: makefile
### Author: April Castaneda
### Description: Makefile for Project1
###

CXX = g++

CXXFLAGS = -std=c++11

OBJS = main.o Menu.o Ant.o Board.o

SRCS = main.cpp Menu.cpp Ant.cpp Board.cpp

HEADERS = Menu.hpp Ant.hpp Board.hpp


edit: ${OBJS}
	${CXX} ${CXXFLAGS} ${OBJS} -o edit

main.o: main.cpp ${HEADERS}
	${CXX} ${CXXFLAGS} main.cpp -c

Menu.o: Menu.cpp Menu.hpp
	${CXX} ${CXXFLAGS} Menu.cpp -c

Ant.o: Ant.cpp Ant.hpp
	${CXX} ${CXXFLAGS} Ant.cpp -c

Board.o: Board.cpp Board.hpp Ant.hpp
	${CXX} ${CXXFLAGS} Board.cpp -c

clean:
	rm edit ${OBJS}
