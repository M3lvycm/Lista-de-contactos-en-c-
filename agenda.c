#include "agenda.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void inicializar_agenda(Agenda *ag){
    ag->lista_contactos = NULL; 
    ag->cantidad = 0;
}

void agregar_contacto(Agenda *ag, Contacto nuevo){
    ag->cantidad++; 

    Contacto **temp = realloc(ag->lista_contactos, ag->cantidad * sizeof(Contacto*));
    if (temp == NULL){
        printf("No se pudo asignar memoria para la lista\n");
        ag->cantidad--; 
        return;
    }
    ag->lista_contactos = temp; 

    Contacto *nuevo_puntero = malloc(sizeof(Contacto));
    *nuevo_puntero = nuevo;

    int ultima_posicion = ag->cantidad - 1; 
    ag->lista_contactos[ultima_posicion] = nuevo_puntero; 

    printf("Se creo el contacto\n");
}

void lista_contactos(Agenda *ag){
    if (ag->cantidad == 0) {
        printf("\nLa agenda está vacía.\n");
        return;
    }

    printf("\n--- Lista de contactos ---\n");
    for(int i = 0; i < ag->cantidad; i++ ){
        printf("contacto %d: con el nombre %s, apellido %s y el telefono %s \n", i + 1, 
        ag->lista_contactos[i]->nombre, ag->lista_contactos[i]->apellido, ag->lista_contactos[i]->telefono );
    }
}

void liberar_agenda(Agenda *ag){ 
   if (ag->lista_contactos == NULL){
    printf("No hay nada para eliminar\n");
    return;
   }
   
   for(int i = 0; i < ag->cantidad; i++){
       free(ag->lista_contactos[i]);
   }
   
   free(ag->lista_contactos);
   ag->lista_contactos = NULL; 
   ag->cantidad = 0; 
   printf("Agenda liberada\n");
}

void borrar_contacto(Agenda *ag, int posicion){
    if(ag->cantidad == 0) {
        printf("La agenda esta vacia, no hay nada que eliminar\n");
        return;
    }

    int indice = posicion - 1;
    if (indice < 0 || indice >= ag->cantidad){
        printf("Posicion no valida.\n");
        return;
    }

    free(ag->lista_contactos[indice]);

    for (int i = indice; i < ag->cantidad - 1; i++){
        ag->lista_contactos[i] = ag->lista_contactos[i + 1];
    }

    ag->cantidad--;

    if (ag->cantidad == 0){
        free(ag->lista_contactos);
        ag->lista_contactos = NULL;
    } else {
        Contacto **temp = realloc(ag->lista_contactos, ag->cantidad * sizeof(Contacto*));
        if (temp != NULL) {
            ag->lista_contactos = temp;
        }
    }
    printf("¡Contacto eliminado con éxito!\n");
}