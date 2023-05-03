.PHONY: all clean
all: program
main.o: main.c
	gcc -m32 -c -o main.o main.c -no-pie
foo.o: foo.asm
	nasm -f elf32 -o foo.o foo.asm
program: foo.o main.o
	gcc -m32 -o prgrm.exe foo.o main.o -no-pie
clean: 
	rm -f foo.o main.o prgrm.exe