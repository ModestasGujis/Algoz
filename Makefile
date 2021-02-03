# c++ -O3 -Wall -shared -std=c++11 -fPIC $(python3-config --includes) -Iextern/pybind11/include Edge.cpp Edge.h Graph.cpp Graph.h example.cpp -o python3-config --extension-suffix

CFLAGS = -O3 -Wall -shared -std=c++11 -fPIC $(shell python3-config --includes) -Iextern/pybind11/include
OUTPUT = main$(shell python3-config --extension-suffix)

SOURCES = $(wildcard *.cpp)
HEADERS = $(wildcard *.h)

.PHONY: all

all: ${HEADERS} ${SOURCES}
	c++ ${CFLAGS} $^ -o ${OUTPUT}
