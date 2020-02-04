########################################################################
#Exemples :
#	Utiliser la commande : make CFLAGS=-DEBUG
#		pour activer le debug à partir du Makefile
#
#	Utiliser la commande : make CFLAGS=-DN="valeur de n"
#		pour changer dynamiquement la valeur de N par défaut
########################################################################

CC=gcc
ifdef N
 CFLAGS=-W -Wall -DN=$(N)
else
 CFLAGS=-W -Wall
endif
SRCS=$(wildcard *.c)
OBJS=$(SRCS:.c=.o)

#Nos exécutables
EXEC=prog



all: $(EXEC)

##############################################
#On laisse make créer tous les .o nécessaires
##############################################

#Règles de création de l'exécutables dictionnaire
$(EXEC):$(OBJS)
	$(CC) $(OBJS) -o $(EXEC)


clean:
	rm -rf *.o


