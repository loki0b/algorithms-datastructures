build:
	gcc -Wall ./*.c	 */*.c -o elf

run:
	./elf

valgrind:
	valgrind ./elf

test:
	./elf < test.in > test.out

diff:
	diff test.in test.out

clean:
	rm elf
