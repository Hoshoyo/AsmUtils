all:
	nasm -felf64 aes.asm
	gcc -g aes.c aes.o ../random/random.o -o aes