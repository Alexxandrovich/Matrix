FLAGS=-Wall -Wextra -Werror -std=c++17
LFLAGS=-lm
GFLAGS=-lgtest

all: test

s21_matrix_oop.a:
	g++ -c $(FLAGS) s21_matrix_oop.cc
	ar rc s21_matrix_oop.a s21_matrix_oop.o
	ranlib s21_matrix_oop.a

test: clean s21_matrix_oop.a
	g++ $(FLAGS) -c s21_matrix_oop.cc s21_googletest.cc
	g++ $(FLAGS) s21_matrix_oop.o s21_googletest.o $(LFLAGS) $(GFLAGS) -o test
	./test

clean:
	rm -f *.o *.out test

.PHONY: test clean s21_matrix_oop.a all
