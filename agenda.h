#ifndef AGENDA_H
#define AGENDA_H

#include "contacto.h"

typedef struct{ 
	Contacto *lista_contactos; 
	int cantidad; 
   
} Agenda; 

void inicializar_agenda(Agenda *ag);
void agregar_contacto(Agenda *ag, Contacto nuevo);
void lista_contactos(Agenda *ag); 
void liberar_agenda(Agenda *ag); 
void borrar_contacto(Agenda *ag, int posicion);


#endif 