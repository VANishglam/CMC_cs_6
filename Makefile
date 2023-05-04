.PHONY: all clean
all: program
main.o: main.c myfirstheader.h
	gcc -m32 -c -o main.o main.c -no-pie
foo.o: foo.asm
	nasm -f elf32 -o foo.o foo.asm
program: foo.o main.o
	gcc -m32 -o prgrm foo.o main.o -no-pie -lm
clean: 
	rm -rf foo.o main.o prgrm