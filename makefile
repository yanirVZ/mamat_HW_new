
CC = gcc
CFLAGS = -g -Wall -std=c99
CCLINK = $(CC)
LDFLAGS = -o
OBJS = main.o stack.o student.o
EXEC = prog.exe
RM = rm -rf
all: $(EXEC)

$(EXEC): $(OBJS)
	$(CCLINK) $(OBJS) $(LDFLAGS) $(EXEC)

main.o: main.c stack.h student.h common.h
	$(CC) $(CFLAGS) -c main.c -o main.o

stack.o: stack.c stack.h common.h
	$(CC) $(CFLAGS) -c stack.c -o stack.o

student.o: student.c student.h common.h
	$(CC) $(CFLAGS) -c student.c -o student.o

clean:
	$(RM) $(OBJS) $(EXEC)
