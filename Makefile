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

calculator.a: calculator.o
	ar rcs $@ $^

calculator.o: calculator.c
	$(CC) $(CFLAGS)  -c -o $@ $<

test: $(TEST-SUITE)
	./$(TEST-SUITE)

$(TEST-SUITE): calculator-test.o calculator.o
	$(CC) $(CFLAGS) -o $(TEST-SUITE) calculator.o calculator-test.o $(LIBS)

calculator-test.o: calculator-test.c calculator.h
	$(CC) $(CFLAGS) -c calculator-test.c

clean:
	rm -f *.o *.a $(TARGET) $(TEST-SUITE)
