CC = clang
CFLAGS += -fcolor-diagnostics -fansi-escape-codes -g -Og -Wall -pthread -pedantic
SANITIZER = -fsanitize=address -fsanitize=undefined -fsanitize=leak

SRC = $(shell find . -name '*.c' -print)
OBJ = $(shell find . -name '*.o' -print)
DSYM = $(shell find . -name '*.dSYM' -print)
TRG = $(SRC:%.c=%)

all: $(TRG)

%: %.c
	@$(CC) -c $< $(CFLAGS) -o $@.o $(SANITIZER)
	@$(CC) $@.o $(CFLAGS) -o $@ $(SANITIZER)

clean:
	@rm -f $(TRG)
	@rm -f $(OBJ)
	@rm -rf $(DSYM)

.PHONY: all clean
