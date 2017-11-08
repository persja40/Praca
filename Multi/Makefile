all:
	make clean; make program; make run; make plot

# dla C++ wszedzie zmieniamy .c na .cpp
MAKEFLAGS = --no-print-directory

CC= g++		# dla C++:   CC=g++
CFLAGS= -O2 -std=c++14
INCLUDE=
LIB= -lpthread # dla lapacka:	LIB= -lm -llapack -lblas
SOURCES= 
OBJECTS= $(SOURCES:.cpp=.o)

TARGET = program

$(TARGET): main.cpp multigame.cpp $(OBJECTS)
	$(CC) -O2 -std=c++14 -o $@ $^ $(LIB)

.c.o:
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

run:
	./program $(G) $(F)

plot:
	gnuplot 'plot.gp'

.PHONY: clean

clean:
	rm -f *.dat *.o *.txt *.png $(TARGET)
