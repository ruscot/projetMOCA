########################################################################
#Exemples :
#	Utiliser la commande : make CFLAGS=-DEBUG
#		pour activer le debug à partir du Makefile
#
#	Utiliser la commande : make CFLAGS=-DN="valeur de n"
#		pour changer dynamiquement la valeur de N par défaut
########################################################################

CC=gcc
CFLAGS=-W -Wall
LDFLAGS=

#Nos exécutables
EXEC=dictionnaire



all: $(EXEC)

##############################################
#On laisse make créer tous les .o nécessaires
##############################################

#Règles de création de l'exécutables dictionnaire
dictionnaire: main.o
	$(CC) main.o -o $@

clean:
	rm -rf *.o
