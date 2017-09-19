# compiler
  CC = gcc

# compiler flags:
  #-lreadline references the GNU readline library
  #-Wall turns on most, but not all, compiler warnings
  CFLAGS  = -pthread

# the build target executable:

default: ep2

ep2: ep2.c ciclista.o pista.o my_time.o aux.o
	$(CC) ep2.c $(CFLAGS) -o ep2 ciclista.o pista.o my_time.o aux.o

my_time: my_time.c my_time.h
	(CC) $(CFLAGS) -c my_time

pista: pista.c pista.h
	(CC) $(CFLAGS) -c pista

ciclista: ciclista.c ciclista.h
	(CC) $(CFLAGS) -c ciclista

aux: aux.c aux.h
	(CC) $(CFLAGS) -c aux

clean:
	$(RM) ep1 ep1sh *.o *~
