out: main.o queue.o
	gcc main.o queue.o -o out

main.o: main.c queue.h
	gcc main.c -c

queue.o: queue.c queue.h
	gcc queue.c -c

run: out
	./out

clean:
	rm -f *.o out
