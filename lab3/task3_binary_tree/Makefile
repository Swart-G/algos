out: main.o tree.o
	gcc main.o tree.o -o out

main.o: main.c tree.h
	gcc main.c -c

queue.o: tree.c tree.h
	gcc tree.c -c

run: out
	./out

clean:
	rm -f *.o out
