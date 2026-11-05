out: main.o array.o
	gcc main.o array.o -o out

main.o: main.c array.h
	gcc main.c -c

array.o: array.c array.h
	gcc array.c -c

run: out
	./out

clean:
	rm -f *.o out