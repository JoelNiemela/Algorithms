a.out: demo.c DFS.o
	gcc -o demo demo.c DFS.o

DFS.o: DFS.c
	gcc -o DFS.o -c DFS.c

clean:
	rm -f demo
	rm -f *.o
