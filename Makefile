# executable name
EXE = $(shell basename $(CURDIR))

# commands
CC = gcc
RM = rm -f

# compiler flags
CFLAGS = -Wall -lm
LIBS = 

# sources
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o) 
OBJ_EXTRA = hash.o list.o

# rules
$(EXE): $(OBJ) $(OBJ_EXTRA)
	$(CC) -o $(EXE) $(OBJ) $(OBJ_EXTRA) $(LIBS) $(CFLAGS)

%.o: %.c
	$(CC) -c $< -o $@ $(CFLAGS)

run: $(EXE)
	./$(EXE)

clean:
	$(RM) $(EXE) $(OBJ)
