CC = g++
CFLAGS = -Wall
SOURCE = cellule.cpp population_vivante.cpp option.cpp tabOption.cpp JDV2.cpp JDV2_main.cpp
PROGNAME = run

MSQ = @
RM = $(MSQ)rm -f
CLEAR = $(MSQ)clear

MSG = $(MSQ)echo
MSG1 = $(MSG) "Compilation de $^ ==> $@"
MSG_OK = $(MSG) ".......OK"

all : $(PROGNAME)
	
#clean
cls :
	$(RM) *.o
	$(RM) $(SOURCE:.cpp=)

clean : cls
	$(MSG) "Cleanup is running...."
	$(CLEAR)
	$(MSG_OK)

#Compilation
$(PROGNAME) : $(SOURCE:.cpp=.o)
	$(MSG1)
	$(CC) $(CFLAGS) $^ -o $@
	$(CLEAR)
	$(MSG_OK)
