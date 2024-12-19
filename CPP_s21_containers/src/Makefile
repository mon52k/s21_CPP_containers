# Флаги компилятора
CC=g++ -std=c++17
FLAGS=-Wall -Werror -Wextra
OS=$(shell uname)
ifeq ($(OS),Darwin)
	LIBS=-lcheck -lm -lpthread -lgtest
else
	LIBS=-lcheck -lm -lpthread -lrt -lsubunit -lgtest -pthread
endif

HFILES:=$(wildcard */s21_*.h)
TFILES:=$(wildcard */s21_*_test.cpp)
TEST=s21_containers_test

all: clean check test

test: clean
	$(CC) $(FLAGS) $(TFILES) $(TEST).cpp -g -o $(TEST) $(LIBS)
	./$(TEST)

gcov_report: clean
	$(CC) $(FLAGS) -fprofile-arcs -ftest-coverage $(TFILES) $(TEST).cpp -o $(TEST) $(LIBS)
	./$(TEST)
	lcov -t "$(TEST)" -o $(TEST).info -c -d .
	genhtml -o report $(TEST).info
	open ./report/index.html

check:
	cp ../materials/linters/.clang-format ./
	clang-format -i $(HFILES)
	clang-format -i $(TFILES)
	clang-format -n $(TFILES)
	clang-format -n $(HFILES)
	
	rm -rf .clang-format

valgrind:	clean
	$(CC) $(FLAGS) $(TFILES) $(TEST).cpp -o $(TEST) $(LIBS)
	valgrind --leak-check=summary ./$(TEST) >> val_result.log 2>&1
	grep -e "ERROR SUMMARY:" val_result.log

clean:
	rm -f *.o
	rm -f $(TEST)
	rm -f *.gcda
	rm -f *.gcno
	rm -f *.info
	rm -f val_result.log
	rm -rf report/