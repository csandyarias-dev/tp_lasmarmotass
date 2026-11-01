/**
	\file    <Nombre del archivo>
	\brief   <Que contiene el archivo>
	\author  <Apellido y Nombre (mail)>
	\date    <Año.Mes.Día> 
	\version <Versión (ejemplo: 1.0.0)>

	Compilación: 	gcc -c main.c -o main_ejemplo.o -Wall
					gcc -c funciones.c -o funciones.o -Wall
	Linkeo: 		gcc main_ejemplo.o funciones.o -o ejecutable -Wall
	Ejecución: 		./ejecutable
*/


//--------------
//-- Includes --
//--------------
#include "m3funciones.h"
#include "../encabezadogeneral.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum m34{añadir=1, modificar, eliminar, volver};

//-------------
//-- Defines --
//-------------

/**
	\fn      <Prototipo de la función>
	\brief   <Función de la función>
	\author  <Apellido y Nombre (mail)>
	\date    <Año.Mes.Día>
	\param   <Parámetro A (si no tiene no se pone)>
	\param   <Parámetro B (si no tiene no se pone)>
	\return  <Lo que retorna>
*/

int m3menu(int * u_pac, int * u_resp, nodo_paciente_t ** pac, nodo_responsable_t ** resp, nodo_turnos_t ** tur, tipopac_t ** tipos, int * cant_t, int * u_tipo) {
    int opcion = 0;
    int loop = OK;

    p_menu3_t acciones_m3[3] = {
        agregar_paciente,
        modificar_paciente,
        eliminar_paciente
    };
	
    while (loop) {
        printf("\nIngrese:\n\t 1- Añadir paciente\n\t 2- Modificar paciente\n\t 3- Eliminar paciente\n\t 4- Volver\nOpcion: ");
        scanf("%d", &opcion);
		
        if (opcion >= OPCION_AGREGAR && opcion <= OPCION_ELIMINAR) {
            acciones_m3[opcion - 1](pac, u_pac,tipos,cant_t,u_tipo);
        } else if (opcion == OPCION_VOLVER) {
            loop = 0;
        } else {
            printf("Opcion invalida, intente nuevamente.\n");
        }
    }
    return OK;
}
