program: main.o random.o
	gcc main.o random.o -o program

main.o: main.c random.h
	gcc -c main.c -o main.o

random.o: random.c random.h
	gcc -c random.c -o random.o

clean:
	rm -f *.o program

.PHONY: clean


