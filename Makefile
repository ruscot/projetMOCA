###############################################################################
#	Compiler bibliothèque statique -> make LIBS=s
#	Compiler bibliothèque dynamique -> make LIBS=d
#	Par default, compile avec fichier locaux
#	Rajouter TEST=1 dans la commande pour compiler (En dynamique) avec les tests 
###############################################################################

INCLUDEDIR_1=my_header
SRCDIR=my_src
OBJDIR=my_obj
LIBDIR=my_lib
LIBTESTDIR=$(LIBDIR)/test_lib
OBJTESTDIR=$(LIBDIR)/test_obj

TESTDIR=tests
OBJTESTS=$(OBJDIR)/$(TESTDIR)
SRCTESTS=$(SRCDIR)/$(TESTDIR)
INCLUDETESTS=$(INCLUDEDIR_1)/$(TESTDIR)

CC=gcc
SRCS=$(wildcard my_src/*.c)
OBJS=$(SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

CFLAGS=-Wall -I $(INCLUDEDIR_1) -I $(LIBTESTDIR) -I $(INCLUDETESTS)

ifdef TEST
CFLAGS+= -DTEST=$(TEST)
endif

ifdef DEBUG
CFLAGS+= -g
endif

# Objets pour la bibliothèque statique
OBJ_LIB=$(patsubst my_obj/main.o,,$(OBJS))

# Objets pour la bibliothèque dynamique
SRCS2=$(patsubst my_src/main.c,,$(SRCS))
OBJDIR2=$(LIBDIR)/lib_obj
OBJ_LIB2=$(SRCS2:$(SRCDIR)/%.c=$(OBJDIR2)/%.o)

# Source pour la bibliothèque de tests dynamique
SRCTEST=$(wildcard $(LIBTESTDIR)/*.c)
OBJ_LIB_TEST=$(SRCTEST:$(LIBTESTDIR)/%.c=$(OBJTESTDIR)/%.o)

# Par défaut le projet est compilé avec les libraries statiques
LIBS=s

# Choisi l'option de linkage pour les libraries
ifeq ($(LIBS),s)
LDFLAGS= -L $(LIBDIR)/ -static -lStatique -lTestS
# On compile seulement la partie statique
all: libTestS libS main 
endif
ifeq ($(LIBS),d)
LDFLAGS= -L $(LIBDIR)/ -Wl,-Bdynamic -lDynamique -lTestD
# On compile seulement la partie dynamique
all: libTestD libD main 
endif

# Règle générique
# Créer les fichiers objs des sources des tests dans my_obj/tests
$(OBJTESTS)/%.o:$(SRCTESTS)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Règle générique 
# Créer les fichiers objs à partir des sources (my_src) dans le répertoire my_obj
$(OBJDIR)/%.o:$(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Compile le programme main avec les fichiers objs (my_obj)
main:$(OBJS)
	$(CC) $(OBJDIR)/*.o $(OBJTESTS)/*.o -o $@ $(LDFLAGS)

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

# Règle générique
# Créer les fichiers objs à partir des sources (my_lib/test_lib) dans le répertoire my_lib/test_obj
$(OBJTESTDIR)/%.o: $(LIBTESTDIR)/%.c
	$(CC) $(CFLAGS) -fPIC -c $< -o $@

# Créer la librarie dynamique libTestD.so dans le répertoire my_lib
# récupère les fichiers objs dans le répertoire my_lib/lib_obj (OBJ_LIB2)
libTestD: $(OBJ_LIB_TEST)
	$(CC) -shared -o $(LIBDIR)/libTestD.so $(OBJ_LIB_TEST)

# Créer la librarie statique libTestS.a dans le répertoire my_lib
libTestS: $(OBJ_LIB_TEST)
	ar r $(LIBDIR)/libTestS.a $(OBJ_LIB_TEST)

clean:
	rm -f $(OBJDIR)/*.o $(OBJTESTS)/*.o $(LIBDIR)/*.* $(OBJDIR2)/* $(OBJTESTDIR)/*.*
