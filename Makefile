TARGET = demo
CC=gcc
CFLAGS= -Wall

$(TARGET): demo.o calculator.a
	$(CC) $(CFLAGS)  $^ -o $@

demo.o: demo.c
	$(CC) $(CFLAGS)  -c $< -o $@

calculator.a: calculator.o
	ar rcs $@ $^

calculator.o: calculator.c
	$(CC) $(CFLAGS)  -c -o $@ $<

clean:
	rm -f *.o *.a $(TARGET)
