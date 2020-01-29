CC=gcc
CFLAGS=-W -Wall
LDFLAGS=
EXEC=dictionnaire

all: clean $(EXEC)

dictionnaire: main.o
	$(CC) main.o -o $@

clean:
	rm -rf *.o

mrproper: clean
	rm -rf $(EXEC)s


