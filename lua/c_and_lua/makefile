SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)
BIN = list-1

all: $(BIN)

CC = gcc
CFLAGS = -g -O2
LDFLAGS = -llua

$(BIN): $(OBJS)
	$(CC) -o $@ $(OBJS) $(LDFLAGS)

%.o:%.c
	$(CC) -c -o$@  $(CFLAGS) $<

clean:
	-$(RM) $(OBJS) $(BIN)