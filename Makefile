all:
	nasm -felf64 aes_cbc.asm
	nasm -g -felf64 aes256_cbc.asm
	nasm -felf64 clock.asm
	#gcc -g aes.c aes_cbc.o clock.o -o aes
	gcc -g aes.c aes256_cbc.o -o aes256