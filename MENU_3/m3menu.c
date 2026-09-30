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

enum m34{añadir=1, modificar, eliminar, volver};

//-------------
//-- Defines --
//-------------
//Acá poner los define.


/**
	\fn      <Prototipo de la función>
	\brief   <Función de la función>
	\author  <Apellido y Nombre (mail)>
	\date    <Año.Mes.Día>
	\param   <Parámetro A (si no tiene no se pone)>
	\param   <Parámetro B (si no tiene no se pone)>
	\return  <Lo que retorna>
*/


void menu3(nodo_paciente_t ** lista, int ultimo_ID){
	int opcion=0;
	int loop=OK;
	
	while (loop) {
		printf("Ingrese \n \t 1- Añadir paciente \n \t 2- Modificar paciente \n \t 3- Eliminar paciente \n \t 4 Volver");
		scanf("%d", &opcion);
		
		switch (opcion) {
			case añadir: 
				añadir_paciente(lista, ultimo_ID);
			break;
			
			case modificar: 
				modificar_paciente(lista);
			break; 
			
			case eliminar:
				eliminar_paciente(lista);
			break;		
			
			case volver: 
			loop=0;
			break;
			
			default: 
				printf("Opcion invalida, intente nuevamente");
		
			}
		}
	
	}
