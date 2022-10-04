a.out: demo.cpp DFS.o
	g++ -std=c++20 -o demo demo.cpp DFS.o

DFS.o: DFS.cpp
	g++ -std=c++20 -o DFS.o -c DFS.cpp

clean:
	rm -f demo
	rm -f *.o
