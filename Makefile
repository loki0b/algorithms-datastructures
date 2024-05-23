build:
	gcc -Wall ./*.c search/*.c sort/*.c list/*.c types/*.c -o elf

run:
	./elf

valgrind:
	valgrind ./elf

clean:
	rm elf
