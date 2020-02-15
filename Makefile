###############################################################################
#	Compiler bibliothèque statique -> make LIB=s
#	Compiler bibliothèque dynamique -> make LIB=d
#	Par default, compile avec fichier locaux
#	Rajouter TEST=1 dans la commande pour compiler (En dynamique) avec les tests 
###############################################################################

INCLUDEDIR_1=my_header
SRCDIR=my_src
OBJDIR=my_obj
LIBDIR=my_lib
LIBTESTDIR=$(LIBDIR)/test_lib
OBJTESTDIR=$(LIBDIR)/test_obj

CC=gcc
SRCS=$(wildcard my_src/*.c)
OBJS=$(SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
CFLAGS=-Wall -I $(INCLUDEDIR_1) -I $(LIBTESTDIR) -g 
ifdef TEST
CFLAGS+=-DTEST=$(TEST)
endif
ifdef AFL
CC=afl-gcc
endif

# Objets pour la bibliothèque statique
OBJ_LIB=$(patsubst my_obj/main.o,,$(OBJS))

# Objets pour la bibliothèque dynamique
SRCS2=$(patsubst my_src/main.c,,$(SRCS))
OBJDIR2=$(LIBDIR)/lib_obj
OBJ_LIB2=$(SRCS2:$(SRCDIR)/%.c=$(OBJDIR2)/%.o)

# Source pour la bibliothèque de tests
SRCTEST=$(wildcard $(LIBTESTDIR)/*.c)
OBJ_LIB_TEST=$(SRCTEST:$(LIBTESTDIR)/%.c=$(OBJTESTDIR)/%.o)
 

# Choisi l'option de linkage pour les libraries
ifeq ($(LIB),s)
LDFLAGS= -L $(LIBDIR)/ -static -lStatique
endif
ifeq ($(LIB),d)
LDFLAGS= -L $(LIBDIR)/ -Wl,-Bdynamic -lDynamique -lTest
endif

all: libTest libD libS main 

# Règle générique 
# Créer les fichiers objs à partir des sources (my_src) dans le répertoire my_obj
$(OBJDIR)/%.o:$(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Compile le programme main avec les fichiers objs (my_obj)
main:$(OBJS)
	$(CC) $(OBJDIR)/* -o $@ $(LDFLAGS)

# Créer la librarie statique libStatique.a dans le répertoire my_lib
libS:$(OBJ_LIB)
	ar r $(LIBDIR)/libStatique.a $(OBJ_LIB)

# Règle générique
# Créer les fichiers objs à partir des sources (my_src) dans le répertoire my_lib/lib_obj
$(OBJDIR2)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -fPIC -c $< -o $@

# Créer la librarie dynamique libDynamique.so dans le répertoire my_lib
# récupère les fichiers objs dans le répertoire my_lib/lib_obj (OBJ_LIB2)
libD:$(OBJ_LIB2)
	$(CC) -shared -o $(LIBDIR)/libDynamique.so $(OBJ_LIB2)

$(OBJTESTDIR)/%.o: $(LIBTESTDIR)/%.c
	$(CC) $(CFLAGS) -fPIC -c $< -o $@

libTest: $(OBJ_LIB_TEST)
	$(CC) -shared -o $(LIBDIR)/libTest.so $(OBJ_LIB_TEST)

clean:
	-rm $(OBJDIR)/*.o $(LIBDIR)/*.* $(OBJDIR2)/*
