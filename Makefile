build:
	gcc -Wall ./main.c ./tools.c search/*.c sort/*.c -o elf

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
