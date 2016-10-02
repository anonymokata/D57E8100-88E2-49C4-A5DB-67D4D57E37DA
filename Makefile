DEMO = demo
TEST-SUITE = test-suite
CC=gcc
CFLAGS= -Wall -std=c99
ODIR= obj
SDIR= src/main
TDIR= src/tests
BIN= bin
LIBS=-lcheck -lm -lpthread -lrt

all: $(TEST-SUITE) $(DEMO)
	./$(BIN)/$(TEST-SUITE)
	./$(BIN)/$(DEMO)

demo: $(ODIR)/demo.o $(ODIR)/calculator.o $(ODIR)/roman-numerals-sorter.o $(ODIR)/roman-numerals-converter.o $(ODIR)/common-utils.o
	$(CC) $(CFLAGS) -o $(DEMO) $(ODIR)/demo.o $(ODIR)/calculator.o $(ODIR)/roman-numerals-sorter.o $(ODIR)/roman-numerals-converter.o $(ODIR)/common-utils.o
	mv demo $(BIN)

$(ODIR)/demo.o: demo.c $(SDIR)/calculator.h
	$(CC) $(CFLAGS) -c demo.c
	mv demo.o $(ODIR)

$(ODIR)/calculator.o: $(SDIR)/calculator.c
	$(CC) $(CFLAGS) -c -o $@ $<

$(ODIR)/roman-numerals-sorter.o: $(SDIR)/roman-numerals-sorter.c
	$(CC) $(CFLAGS) -c -o $@ $<

$(ODIR)/roman-numerals-converter.o: $(SDIR)/roman-numerals-converter.c
	$(CC) $(CFLAGS) -c -o $@ $<

$(ODIR)/common-utils.o: $(SDIR)/common-utils.c
	$(CC) $(CFLAGS) -c -o $@ $<


test: $(TEST-SUITE)
	./$(BIN)/$(TEST-SUITE)

$(TEST-SUITE): $(ODIR)/all-tests.o $(ODIR)/calculator-test.o $(ODIR)/roman-numerals-sorter-test.o $(ODIR)/roman-numerals-converter-test.o $(ODIR)/common-utils-test.o $(ODIR)/fitness-test.o $(ODIR)/calculator.o $(ODIR)/roman-numerals-sorter.o $(ODIR)/roman-numerals-converter.o $(ODIR)/common-utils.o
	$(CC) $(CFLAGS) -o $(TEST-SUITE) $(ODIR)/all-tests.o $(ODIR)/calculator-test.o $(ODIR)/roman-numerals-sorter-test.o $(ODIR)/roman-numerals-converter-test.o $(ODIR)/common-utils-test.o $(ODIR)/fitness-test.o $(ODIR)/calculator.o $(ODIR)/roman-numerals-sorter.o $(ODIR)/roman-numerals-converter.o $(ODIR)/common-utils.o $(LIBS)
	mv $(TEST-SUITE) $(BIN)

$(ODIR)/all-tests.o: $(TDIR)/all-tests.c $(TDIR)/calculator-test.h $(TDIR)/roman-numerals-sorter-test.h $(TDIR)/roman-numerals-converter-test.h $(TDIR)/common-utils-test.h $(TDIR)/fitness-test.h
	$(CC) $(CFLAGS) -c $(TDIR)/all-tests.c
	mv *.o $(ODIR)

$(ODIR)/calculator-test.o: $(TDIR)/calculator-test.c $(SDIR)/calculator.h
	$(CC) $(CFLAGS) -c $(TDIR)/calculator-test.c
	mv *.o $(ODIR)

$(ODIR)/fitness-test.o: $(TDIR)/fitness-test.c
	$(CC) $(CFLAGS) -c $(TDIR)/fitness-test.c
	mv *.o $(ODIR)

$(ODIR)/roman-numerals-sorter-test.o: $(TDIR)/roman-numerals-sorter-test.c $(SDIR)/roman-numerals-sorter.h
	$(CC) $(CFLAGS) -c $(TDIR)/roman-numerals-sorter-test.c
	mv *.o $(ODIR)

$(ODIR)/roman-numerals-converter-test.o: $(TDIR)/roman-numerals-converter-test.c $(SDIR)/roman-numerals-converter.h
	$(CC) $(CFLAGS) -c $(TDIR)/roman-numerals-converter-test.c
	mv *.o $(ODIR)

$(ODIR)/common-utils-test.o: $(TDIR)/common-utils-test.c $(SDIR)/common-utils.h
	$(CC) $(CFLAGS) -c $(TDIR)/common-utils-test.c
	mv *.o $(ODIR)

valgrind:
	valgrind --leak-check=yes bin/test-suite

clean:
	find . -type f -name '*.o' -delete
	find . -type f -name '*.a' -delete
	rm bin/*
