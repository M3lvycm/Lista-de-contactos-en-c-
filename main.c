#include <stdio.h>
#include "agenda.h"

int main(){

    Agenda mi_agenda;
    inicializar_agenda(&mi_agenda);
    int opcion;

    do { 

        printf("\n1. Agregar contacto\n2. Listar contactos\n3. Eliminar contacto\n4. Salir\nElige: ");
        scanf("%d", &opcion);

        switch(opcion){
            case 1: { 
                Contacto c; 
                printf("Nombre: "); 
                scanf("%s", c.nombre); 

                printf("Apellido: ");
                scanf("%s", c.apellido); 

                printf("Telefono: "); 
                scanf("%s", c.telefono);

                agregar_contacto(&mi_agenda, c);
                break;
            }
            case 2:
                lista_contactos(&mi_agenda);
                break;
                
            case 3: { 
                int pos;
                printf("Ingresa el número del contacto a eliminar (1, 2, 3...): ");
                scanf("%d", &pos);
                borrar_contacto(&mi_agenda, pos);
                break;
            }

            case 4: 
                printf("Saliendo...\n");
                break; 

            default:
                printf("Opción no válida\n");
        }

    } while (opcion != 4); 

    liberar_agenda(&mi_agenda);    
    
    return 0;
}