<<<<<<< HEAD
# Makefile for project
CC = gcc
LD = gcc
CFLAGS = -O0 -Wall -Werror -g -lm
=======
// Makefile for project
CC = gcc
LD = gcc
CFLAGS = -O0 -Wall -Werror -g
>>>>>>> 36946d8ef2c1cb887c753ecb267a081a98aa0e4b
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
