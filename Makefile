###############################################################################
#	Compiler bibliotheque statique -> make LIBS=s
#	Compiler bibliotheque dynamique -> make LIBS=d
#	Par default, compile avec fichier locaux
#	Rajouter TEST=1 dans la commande pour compiler (En dynamique) avec les tests 
#	AFL source ~mounlaur/installe_afl.sh
# 	export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:./my_lib
###############################################################################

INCLUDEDIR_1=my_header
SRCDIR=my_src
OBJDIR=my_obj
LIBDIR=my_lib
TESTCOUV=test_couverture
SETUPAFL=setup_afl
LDD := $(shell printenv LD_LIBRARY_PATH)
LD_PATH := export LD_LIBRARY_PATH=./$(LIBDIR):$(LDD)

LIBTESTDIR=$(LIBDIR)/test_lib
OBJTESTDIR=$(LIBDIR)/test_obj

TESTDIR=tests
OBJTESTS=$(OBJDIR)/$(TESTDIR)
SRCTESTS=$(SRCDIR)/$(TESTDIR)
INCLUDETESTS=$(INCLUDEDIR_1)/$(TESTDIR)

SRCSTESTS=$(wildcard $(SRCTESTS)/*.c)
OBJSTESTS=$(SRCSTESTS:$(SRCTESTS)/%.c=$(OBJTESTS)/%.o)

CC=gcc

ifdef AFL
CC=afl-gcc
endif

SRCS=$(wildcard $(SRCDIR)/*.c)
OBJS=$(SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

CFLAGS=-Wall -I $(INCLUDEDIR_1) -I $(INCLUDETESTS) -I $(LIBTESTDIR) -fprofile-arcs -ftest-coverage

ifdef TEST
CFLAGS+= -DTEST=$(TEST)
endif

ifdef DEBUG
CFLAGS+= -g
endif

# Objets pour la bibliotheque statique
OBJ_LIB=$(patsubst my_obj/main.o,,$(OBJS))

# Objets pour la bibliotheque dynamique
SRCS2=$(patsubst my_src/main.c,,$(SRCS))
OBJDIR2=$(LIBDIR)/lib_obj
OBJ_LIB2=$(SRCS2:$(SRCDIR)/%.c=$(OBJDIR2)/%.o)

# Source pour la bibliotheque de tests dynamique
SRCTEST=$(wildcard $(LIBTESTDIR)/*.c)
OBJ_LIB_TEST=$(SRCTEST:$(LIBTESTDIR)/%.c=$(OBJTESTDIR)/%.o)

# Par defaut le projet est compile avec les libraries statiques
LIBS=s

# Choisi l'option de linkage pour les libraries
ifeq ($(LIBS),s)
LDFLAGS= -L $(LIBDIR)/ -static -lStatique -lTestS
# On compile seulement la partie statique
all: libTestS libS main
endif
ifeq ($(LIBS),d)

LDFLAGS= -L $(LIBDIR)/ -Wl,-rpath,./$(LIBDIR) -Bdynamic -lDynamique -lTestD
# On compile seulement la partie dynamique
all: libTestD libD main 
endif

LDFLAGS += -lgcov --coverage

# Regle generique 
# Creer les fichiers objs a partir des sources (my_src) dans le repertoire my_obj
$(OBJDIR)/%.o:$(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Regle generique
# Creer les fichiers objs des sources des tests dans my_obj/tests
$(OBJTESTS)/%.o:$(SRCTESTS)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Compile le programme main avec les fichiers objs (my_obj)
main : $(OBJS) $(OBJSTESTS)
	$(CC) $(OBJTESTS)/*.o $(OBJDIR)/*.o -o $@ $(LDFLAGS)

# Creer la librarie statique libStatique.a dans le repertoire my_lib
libS : $(OBJ_LIB)
	ar r $(LIBDIR)/libStatique.a $(OBJ_LIB)

# Regle generique
# Creer les fichiers objs a partir des sources (my_src) dans le repertoire my_lib/lib_obj
$(OBJDIR2)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -fPIC -c $< -o $@

# Creer la librarie dynamique libDynamique.so dans le repertoire my_lib
# recupere les fichiers objs dans le repertoire my_lib/lib_obj (OBJ_LIB2)

# NE PAS OUBLIER LE "-lgcov" SINON IMPOSSIBLE DE COMPILER
libD:$(OBJ_LIB2)
	$(CC) -shared -o $(LIBDIR)/libDynamique.so $(OBJ_LIB2) -lgcov

# Regle generique
# Creer les fichiers objs a partir des sources (my_lib/test_lib) dans le repertoire my_lib/test_obj
$(OBJTESTDIR)/%.o: $(LIBTESTDIR)/%.c
	$(CC) $(CFLAGS) -fPIC -c $< -o $@

# Creer la librarie dynamique libTestD.so dans le repertoire my_lib
# recupere les fichiers objs dans le repertoire my_lib/lib_obj (OBJ_LIB2)

# NE PAS OUBLIER LE "-lgcov" SINON IMPOSSIBLE DE COMPILER
libTestD: $(OBJ_LIB_TEST)
	$(CC) -shared -o $(LIBDIR)/libTestD.so $(OBJ_LIB_TEST) -lgcov
	# Configure la variable d'environnement LD_LIBRARY_PATH
	

# Creer la librarie statique libTestS.a dans le repertoire my_lib
libTestS: $(OBJ_LIB_TEST)
	ar r $(LIBDIR)/libTestS.a $(OBJ_LIB_TEST)

rungcov:
	gcov -b -c $(SRCS) -o $(OBJDIR)/
	gcov -b -c $(SRCSTESTS) -o $(OBJTESTS)/
	mv *.gcov $(TESTCOUV)

clean:
	rm -f main $(OBJDIR)/*.* $(OBJTESTS)/*.* $(LIBDIR)/*.* $(OBJDIR2)/* $(OBJTESTDIR)/*.* $(TESTCOUV)/*.*
