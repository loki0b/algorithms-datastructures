build:
	gcc -Wall ./*.c	 */*.c -o elf

run:
	./elf

clean:
	rm elf
