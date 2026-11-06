out: main.o stack.o
	gcc main.o stack.o -o out

main.o: main.c stack.h
	gcc main.c -c

stack.o: stack.c stack.h
	gcc stack.c -c

run: out
	./out

clean:
	rm -f *.o out