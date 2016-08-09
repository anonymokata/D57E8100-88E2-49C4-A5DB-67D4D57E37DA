TARGET = demo
TEST-SUITE = test-suite
CC=gcc
CFLAGS= -Wall
LIBS=-lcheck -lm -lpthread -lrt

all: $(TEST-SUITE) $(TARGET)
	./$(TEST-SUITE)
	./$(TARGET)

$(TARGET): demo.o calculator.a
	$(CC) $(CFLAGS)  $^ -o $@

demo.o: demo.c
	$(CC) $(CFLAGS)  -c $< -o $@

calculator.a: calculator.o roman-numerals-sorter.o
	ar rcs $@ $^

calculator.o: calculator.c
	$(CC) $(CFLAGS)  -c -o $@ $<

roman-numerals-sorter.o: roman-numerals-sorter.c
	$(CC) $(CFLAGS)  -c -o $@ $<

test: $(TEST-SUITE)
	./$(TEST-SUITE)

$(TEST-SUITE): all-tests.o calculator-test.o roman-numerals-sorter-test.o calculator.o roman-numerals-sorter.o
	$(CC) $(CFLAGS) -o $(TEST-SUITE) all-tests.o calculator-test.o roman-numerals-sorter-test.o calculator.o roman-numerals-sorter.o $(LIBS)

all-tests.o: all-tests.c calculator-test.h roman-numerals-sorter-test.h
	$(CC) $(CFLAGS) -c all-tests.c

calculator-test.o: calculator-test.c calculator.h
	$(CC) $(CFLAGS) -c calculator-test.c

roman-numerals-sorter-test.o: roman-numerals-sorter-test.c roman-numerals-sorter.h
		$(CC) $(CFLAGS) -c roman-numerals-sorter-test.c


clean:
	rm -f *.o *.a $(TARGET) $(TEST-SUITE)
