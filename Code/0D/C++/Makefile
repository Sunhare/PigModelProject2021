CXX=g++

INCLUDE=-I/usr/local/include
LIB    =-L/usr/local/lib

CXXFLAGS = -Ilib -O3 -std=c++11 -fopenmp  -I $(INCLUDE) -lsundials_cvode

main:$(patsubst %.cpp,%.o,$(wildcard lib/*.cpp))


clean:
	rm lib/*.o main
