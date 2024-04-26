build:
	gcc -Wall ./*.c	 */*.c -o elf

run:
	./elf

valgrind:
	valgrind ./elf

clean:
	rm elf
