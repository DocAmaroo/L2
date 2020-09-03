CC = g++
SOURCE = main-2.cpp tableau-cellule.cpp cellule.cpp population-vivante.cpp
PROGNAME = oui

MSQ = @
RM = $(MSQ) rm
MSG_OK = $(MSQ) echo "Done"

$(PROGNAME) : $(SOURCE:.cpp=.o)
	$(CC) $^ -o $@
	clear
	$(MSG_OK)

clean :
	$(RM) *.o
	clear
	$(MSG_OK)
