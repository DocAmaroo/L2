CC = g++
SOURCE = myvectormain.cpp cellule.cpp
PROGNAME = run

MSQ = @
RM = $(MSQ) rm
MSG_OK = $(MSQ) echo "Done"

$(PROGNAME) : $(SOURCE:.cpp=.o)
	$(CC) -ansi -pedantic $^ -o $@
	clear
	$(MSG_OK)

clean :
	$(RM) *.o
	clear
	$(MSG_OK)
