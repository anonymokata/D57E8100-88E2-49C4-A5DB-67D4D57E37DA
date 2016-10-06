DEMO = demo
TEST-SUITE = test-suite
CC= gcc
LINKER= gcc -o
CFLAGS= -std=c99 -Wall -I.
LFLAGS= -Wall -I. -lm
SDIR= src/main
TDIR= src/tests
ODIR= obj
BIN= bin
LIBS=-lcheck -lm -lpthread -lrt

SOURCES  := $(wildcard $(SDIR)/*.c)
TESTSOURCES  := $(wildcard $(TDIR)/*.c)
INCLUDES := $(wildcard $(SDIR)/*.h)
OBJECTS  := $(SOURCES:$(SDIR)/%.c=$(ODIR)/%.o)
TESTOBJECTS  := $(TESTSOURCES:$(TDIR)/%.c=$(ODIR)/%.o)

all: $(TEST-SUITE) $(DEMO)
	./$(BIN)/$(TEST-SUITE)
	./$(BIN)/$(DEMO)

demo: $(OBJECTS)
	@$(LINKER) $@ $(LFLAGS) $(OBJECTS)
	@mv demo $(BIN)
	@echo "Linking complete!"

$(OBJECTS): $(ODIR)/%.o : $(SDIR)/%.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiled "$<" successfully!"

test: $(TEST-SUITE)
	./$(BIN)/$(TEST-SUITE)

$(TEST-SUITE): $(filter-out $(ODIR)/demo.o,$(OBJECTS)) $(TESTOBJECTS)
	@$(CC) $(CFLAGS) -o $(TEST-SUITE) $(TESTOBJECTS) $(filter-out $(ODIR)/demo.o,$(OBJECTS)) $(LIBS)
	@mv $(TEST-SUITE) $(BIN)

$(TESTOBJECTS): $(ODIR)/%.o : $(TDIR)/%.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiled "$<" successfully!"

removeDemo:
	@rm $(ODIR)/demo.o

valgrind:
	CK_FORK=no valgrind --leak-check=yes bin/test-suite

clean:
	find . -type f -name '*.o' -delete
	find . -type f -name '*.a' -delete
	rm bin/*
