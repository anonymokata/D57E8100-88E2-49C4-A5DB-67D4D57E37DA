DEMO = demo
TEST-SUITE = test-suite
CC=gcc
CFLAGS= -Wall
ODIR= obj
SDIR= src/main
TDIR= src/tests
BIN= bin
LIBS=-lcheck -lm -lpthread -lrt

all: $(TEST-SUITE) $(DEMO)
	./$(BIN)/$(TEST-SUITE)
	./$(BIN)/$(DEMO)

demo: $(ODIR)/demo.o $(ODIR)/calculator.o $(ODIR)/roman-numerals-sorter.o
	$(CC) $(CFLAGS) -o $(DEMO) $(ODIR)/demo.o $(ODIR)/calculator.o $(ODIR)/roman-numerals-sorter.o
	mv demo $(BIN)

$(ODIR)/demo.o: demo.c $(SDIR)/calculator.h
	$(CC) $(CFLAGS) -c demo.c
	mv demo.o $(ODIR)

$(ODIR)/calculator.o: $(SDIR)/calculator.c
	$(CC) $(CFLAGS) -c -o $@ $<

$(ODIR)/roman-numerals-sorter.o: $(SDIR)/roman-numerals-sorter.c
	$(CC) $(CFLAGS) -c -o $@ $<

test: $(TEST-SUITE)
	./$(BIN)/$(TEST-SUITE)

$(TEST-SUITE): $(ODIR)/all-tests.o $(ODIR)/calculator-test.o $(ODIR)/roman-numerals-sorter-test.o $(ODIR)/calculator.o $(ODIR)/roman-numerals-sorter.o
	$(CC) $(CFLAGS) -o $(TEST-SUITE) $(ODIR)/all-tests.o $(ODIR)/calculator-test.o $(ODIR)/roman-numerals-sorter-test.o $(ODIR)/calculator.o $(ODIR)/roman-numerals-sorter.o $(LIBS)
	mv $(TEST-SUITE) $(BIN)

$(ODIR)/all-tests.o: $(TDIR)/all-tests.c $(TDIR)/calculator-test.h $(TDIR)/roman-numerals-sorter-test.h
	$(CC) $(CFLAGS) -c $(TDIR)/all-tests.c
	mv *.o $(ODIR)

$(ODIR)/calculator-test.o: $(TDIR)/calculator-test.c $(SDIR)/calculator.h
	$(CC) $(CFLAGS) -c $(TDIR)/calculator-test.c
	mv *.o $(ODIR)

$(ODIR)/roman-numerals-sorter-test.o: $(TDIR)/roman-numerals-sorter-test.c $(SDIR)/roman-numerals-sorter.h
	$(CC) $(CFLAGS) -c $(TDIR)/roman-numerals-sorter-test.c
	mv *.o $(ODIR)

clean:
	find . -type f -name '*.o' -delete
	find . -type f -name '*.a' -delete
	rm bin/*
