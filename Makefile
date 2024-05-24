build:
	gcc -Wall ./*.c search/*.c sort/*.c list/*.c -o elf

run:
	./elf

valgrind:
	valgrind ./elf

clean:
	rm elf
