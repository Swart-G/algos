out: main.o reverse_array.o
	gcc main.o reverse_array.o -o out

main.o: main.c reverse_array.h
	gcc main.c -c

reverse_array.o: reverse_array.c
	gcc reverse_array.c -c

run: out
	./out

clean:
	rm -f *.o out