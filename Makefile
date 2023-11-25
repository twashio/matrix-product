SRC = matrix.c

run: $(SRC)
	gcc -o a.out $(SRC)
	./a.out

test: $(SRC)
	gcc -Wall -Wextra -o a.out $(SRC) 