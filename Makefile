CC = gcc
CFLAGS = -Wall

all: programa_agenda

programa_agenda: main.c agenda.c
	$(CC) $(CFLAGS) main.c agenda.c -o programa_agenda

clean:
	rm -f programa_agenda