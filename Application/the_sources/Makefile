# DECAMPS Marceau, LAGRANGE Nathan : Binome 4
CC = gcc
OBJS = main.o P2.o P1.o util.o ecrire_fichier.o # Liste de tous les fichiers
CFLAGS = -I ../the_headers # Les .h ne sont pas dans le même dossier

all: main clean

# Creation de l'executable
main: $(OBJS)
		$(CC) $(OBJS) -o ../bin/$@ -lm

# Creation des objets
%.o: %.c
		$(CC) -o $@ -c $< $(CFLAGS)

clean :
		-rm -f *.o *~
