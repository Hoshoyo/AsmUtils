all:
	nasm -felf64 aes.asm
	nasm -felf64 clock.asm
	gcc -g aes.c aes.o clock.o -o aes