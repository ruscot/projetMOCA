##################################################
#	Compiler bibliotèque statique -> make LIB=s
#	Compiler bibliotèque dynamique -> make LIB=d
#	Par default, compile avec fichier locaux
##################################################

INCLUDEDIR_1=my_header
SRCDIR=my_src
OBJDIR=my_obj
LIBDIR=my_lib

CC=gcc
SRCS=$(wildcard my_src/*.c)
OBJS=$(SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
CFLAGS=-Wall -I $(INCLUDEDIR_1) -g

# Objets pour la bibliotèque statique
OBJ_LIB=$(patsubst my_obj/main.o,,$(OBJS))

# Objets pour la bibliotèque dynamique
SRCS2=$(patsubst my_src/main.c,,$(SRCS))
OBJDIR2=$(LIBDIR)/lib_obj
OBJ_LIB2=$(SRCS2:$(SRCDIR)/%.c=$(OBJDIR2)/%.o)

# Choisi l'option de linkage pour les libraries
ifeq ($(LIB),s)
LDFLAGS= -L $(LIBDIR)/ -static -lStatique
endif
ifeq ($(LIB),d)
LDFLAGS= -L $(LIBDIR)/ -Wl,-Bdynamic -lDynamique
endif

all: bibli2 bibli main 

# Règle générique 
# Créer les fichiers objs à partir des sources (my_src) dans le répertoire my_obj
$(OBJDIR)/%.o:$(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Compile le programme main avec les fichiers objs (my_obj)
main:$(OBJS)
	$(CC) $(OBJDIR)/* -o $@ $(LDFLAGS)

# Créer la librarie statique libStatique.a dans le répertoire my_lib
bibli:$(OBJ_LIB)
	ar r $(LIBDIR)/libStatique.a $(OBJ_LIB)

# Règle générique
# Créer les fichiers objs à partir des sources (my_src) dans le répertoire my_lib/lib_obj
$(OBJDIR2)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -fPIC -c $< -o $@

# Créer la librarie dynamique libDynamique.so dans le répertoire my_lib
# récupère les fichiers objs dans le répertoire my_lib/lib_obj (OBJ_LIB2)
bibli2:$(OBJ_LIB2)
	$(CC) -shared -o $(LIBDIR)/libDynamique.so $(OBJ_LIB2)

clean:
	-rm $(OBJDIR)/*.o $(LIBDIR)/*.* $(OBJDIR2)/*
