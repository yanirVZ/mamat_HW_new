CC=gcc
CFLAGS=-g -Wall -std=c99 -fpic
LDFLAGS=-shared

# Object files
OBJ_GRADES=grades.o

# Shared library
LIB_GRADES=libgrades.so

all: $(LIB_GRADES)

$(LIB_GRADES): $(OBJ_GRADES)
	$(CC) $(LDFLAGS) -o $@ $(OBJ_GRADES) -llinked-list -L.

grades.o: grades.c grades.h linked-list.h
	$(CC) $(CFLAGS) -c grades.c

clean:
	$(RM) *.o $(LIB_GRADES)