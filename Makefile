CC=gcc
CFLAGS=-Wall
SRC=n-queen.c
OUT=n-queen

all: $(OUT)

$(OUT): $(SRC)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(OUT) *~
