#===============================================================================
#
 # Informations :
#
 # 	- Name		  : Makefile
#
 # 	- Author	  : CANTA Thomas 
#
 # 	- UE 		  : HLIN302 - Programmation Impératice Avancée (PIA)
#
 # 	- Utilisation :
#
 #		- make cls (supprimer les fichiers issus de la programmation)
#
 # 		- make arch (crée une archive pour la diffusion de l'application)
#
 # 		- make archive (crée une archive contenant les sources de l'application)
#
#===============================================================================

CC = g++
CFLAGS = -Wall

ARCH = $(VERSION).tar.gz
ARCH_SRC = $(VERSION)_src.tar.gz
SOURCE = TD1-1.cpp TD1-2.cpp TD1-3.cpp

THIS = Makefile
VERSION = $(shell date +%d_%m_%Y)


MSQ = @
RM = $(MSQ)rm -f
MKDIR = $(MSQ)mkdir -p
MV = $(MSQ)mv
TAR = $(MSQ)tar -czf
CLEAR = $(MSQ)clear


MSG = $(MSQ)echo
MSG1 = $(MSG) "Compilation de $^ ==> $@"
MSG2 = $(MSG) "Edition de lien de $^ ==> $@"
MSG_ARCH = $(MSG) "Création de l'archive $@\n Ajout des fichiers : $^"
MSG_SAVE = $(MSG) "Sauvegarde en cours de tous vos fichiers \n Ajout des fichiers : $^"
MSG_OK = $(MSG) ".......OK \n"

arch : $(ARCH)
archive : $(ARCH_SRC)
save : $(VERSION)

#Create archive
$(ARCH) : $(THIS) $(SOURCE) $(SOURCE:.cpp=)
	$(MSG_ARCH)
	$(TAR) $@ $^
	$(MSG_OK)

#Create archive source
$(ARCH_SRC) : $(THIS) $(SOURCE) $(SOURCE:.cpp=)
	$(MSG_ARCH)
	$(TAR) $@ $^
	$(MSG_OK)

#Create save
$(VERSION) : $(ARCH_SRC)
	$(MSG) "Création du répectoire de sauvegarde : $@"
	$(RM) -rf $@
	$(MKDIR) $@
	$(MSG_SAVE)
	$(MV) $< $@
	$(MSG_OK)

#clean
cls :
	$(RM) *.o
	$(RM) $(ARCH)
	$(RM) $(ARCH_SRC)
	$(RM) $(SOURCE:.cpp=)

clean : cls
	$(MSG) "Cleanup is running...."
	$(CLEAR)
	$(MSG_OK)

#Suffixes
.SUFFIXES : .cpp

#Compilation
.cpp :
	$(MSG1)
	$(CC) $(CFLAGS) $^ -o $@
	$(MSG_OK)