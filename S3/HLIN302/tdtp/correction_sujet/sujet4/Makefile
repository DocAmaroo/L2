CC = g++
CFLAGS = -Wall
SOURCE = cellule.cpp population-vivante-v2.cpp option.cpp tabOptions.cpp JDV0.cpp JDV0-main.cpp
PROGNAME = run


MSQ = @
RM = $(MSQ)rm -f
CLEAR = $(MSQ)clear


MSG = $(MSQ)echo
MSG1 = $(MSG) "Compilation de $^ ==> $@"
MSG2 = $(MSG) "Edition de lien de $^ ==> $@"
MSG_OK = $(MSG) ".......OK \n"

all : $(PROGNAME)
#clean
cls :
	$(RM) *.o
	$(RM) $(SOURCE:.cpp=)

clean : cls
	$(MSG) "Cleanup is running...."
	$(CLEAR)
	$(MSG_OK)

#Suffixes
#.SUFFIXES : .cpp

#Compilation
$(PROGNAME) : $(SOURCE:.cpp=.o)
	$(MSG1)
	$(CC) $(CFLAGS) $^ -o $@
	$(MSG_OK)

