CC = g++
CFLAGS = -Wall -ansi -pedantic
SRCS = fichierTP4.cpp progListeSC.cpp
OBJS = $(SRCS:.cpp = .o)
BIN = TP4
EXT = *.o

all: $(OBJS)
	clear; clear;
	$(CC) -o $(BIN) $(OBJS)

%.o: %.cpp
	$(CC) -c $< -o $@ $(CFLAGS)

clean:
	rm -f $(EXT) $(BIN)