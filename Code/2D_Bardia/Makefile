CXX=g++-9

INC_PARAMS=-Ilib -I/usr/local/include
LIB    =-L/usr/local/lib

LDFLAGS= -lsundials_cvode ${LIB}
CXXFLAGS = -O3 -std=c++11 -fopenmp

0D_pig_main: 0D_pig_main.cpp $(objs)
	$(CXX) $(CXXFLAGS) $(INC_PARAMS) $^ -o $@ $(LDFLAGS)

2D_pig_main: 2D_pig_main.cpp $(objs)  
	$(CXX) $(CXXFLAGS) $(INC_PARAMS) $^ -o $@ $(LDFLAGS)

clean:
	rm lib/*.o pig_main 2D_pig_main 0D_pig_main
