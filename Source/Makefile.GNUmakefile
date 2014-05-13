// Makefile for project
CC = gcc
LD = gcc
CFLAGS = -O0 -Wall -Werror -g
LDFLAGS = 
RM = /bin/rm -f
OBJS = main.o funcs.o
EXECUTABLE = exam

all: clean $(EXECUTABLE)

$(EXECUTABLE): $(OBJS)
	$(LD) $(LDFLAGS) $(OBJS) -o $(EXECUTABLE)

funcs.o: common.h funcs.h funcs.c
	$(CC) $(CFLAGS) -c funcs.c

main.o: common.h funcs.h main.c
	$(CC) $(CFLAGS) -c main.c 

clean:
	$(RM) $(EXECUTABLE) $(OBJS)
