compile: node.o playlist.o main.o
	gcc node.o playlist.o main.o -o test
node.o: node.c node.h
	gcc -c node.c
playlist.o: playlist.c playlist.h
	gcc -c playlist.c
main.o: main.c node.h playlist.h
	gcc -c main.c
run: compile
	./test
