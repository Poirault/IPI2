APPLI=morpion
CSRC= creationtableau.c terminerjeu.c main.c tourdejeu.c structurejeu.c liste.c
CC = gcc

CFLAGS = -Wall -Wextra -ansi  -I. -g

COBJ=$(CSRC:.c=.o)

.c.o:
	$(CC) $(CFLAGS) -c $*.c

$(APPLI):	$(COBJ)
	$(CC) -o $(APPLI) $(COBJ) -lm -lncurses

clean:
	-rm *.o *[~%] core *.bak