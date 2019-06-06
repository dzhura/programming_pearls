CC = g++ 
#CXXFLAGS = -ggdb -Wall
CXXFLAGS = -O3 -Wall

all: bitmap_sort std_sort

bitmap_sort: bitmap_sort.o bitmap.o

std_sort: std_sort.o

bitmap_sort.o: bitmap_sort.cpp bitmap.h

bitmap.o: bitmap.cpp bitmap.h

.PHONY: clean
clean:
	rm *.o bitmap_sort std_sort
