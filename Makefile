INCLUDEDIR_1=include/
INCLUDEDIR_2=lib_messages/include

CC=gcc
SRCS=$(wildcard src/*.c)
OBJS=$(SRCS:.c=.o)
CFLAGS=-Wall -I $(INCLUDEDIR_1) -I $(INCLUDEDIR_2)
LDFLAGS= -L lib_messages/lib -lmessages

main:$(OBJS)
	$(CC) $(OBJS) -o $@ $(LDFLAGS)

clean:
	rm src/*.o main