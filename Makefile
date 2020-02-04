INCLUDEDIR_1=my_header
#INCLUDEDIR_2=lib_messages/include
SRCDIR=my_src
OBJDIR=my_obj

CC=gcc
SRCS=$(wildcard my_src/*.c)
OBJS=$(SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
CFLAGS=-Wall -I $(INCLUDEDIR_1) -g

#LDFLAGS= -L lib_messages/lib -lmessages

$(OBJDIR)/%.o:$(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

main:$(OBJS)
	$(CC) $(OBJDIR)/* -o $@ $(LDFLAGS)

clean:
	rm $(OBJDIR)/*.o