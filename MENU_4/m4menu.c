/**
	\file    main_menu4.c
	\brief   Programa principal para ejecutar y probar localmente el Menú 4 (Responsables).
	\author  Grupo las marmotas
	\date    2026.10.02
	\version 1.0.0
*/

#include "m4funciones.h"
#include <stdio.h>
#include <stdlib.h>

void ejecutar_menu_responsables(nodo_responsable_t ** lista, int * ultimo_id) {
    int continuar = 1;
    int opcion = 0;
    
    p_menu4_t acciones[4] = {
        agregar_responsable, 
        modificarResponsable, 
        eliminarResponsable
    };

    while (continuar == 1) {
        printf("\n--- MENU 4: RESPONSABLES ---\n");
        printf("1) Agregar responsable\n");
        printf("2) Modificar responsable\n");
        printf("3) Eliminar responsable\n");
        printf("4) Volver\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        if (opcion >= OPCION_AGREGAR && opcion <= OPCION_VOLVER) {
            acciones[opcion - 1](lista, ultimo_id);
            
            if (opcion == OPCION_VOLVER) continuar = 0;
        } else {
            printf("[ERROR] Opcion invalida. Intente nuevamente.\n");
        }
    }
}

int main(int argc, char ** argv) {
    nodo_responsable_t * lista_responsables = NULL;
    nodo_responsable_t * actual = NULL;
    nodo_responsable_t * a_borrar = NULL;
    int ultimo_id = 0;

    printf("Iniciando modulo local de Responsables...\n");
    
    ejecutar_menu_responsables(&lista_responsables, &ultimo_id);

    actual = lista_responsables;
    while (actual != NULL) {
        a_borrar = actual;
        actual = actual->sig;
        free(a_borrar);
    }

    printf("Memoria liberada con exito. Programa finalizado.\n");
    return 0;
}
