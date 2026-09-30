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
#include "m1funciones.h"

enum m1{pac_id=1, pac_nombre, responsable_id, responsable_nombre, turnos_pacientes, turnos_responsables, turnos_fecha, listado_pacientes, listado_responsables, volver};

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


void menu1(void){
	int opcion=0;
	int loop=OK;
	
	while (loop) {
		printf("Ingrese \n \t 1- Consultar paciente por ID \n \t 2- Consultar paciente por nombre \n \t 3- Consultar responsable por ID \n \t 4- Consultar responsable por nombre y apellido \n \t 5- Consultar turnos por paciente \n \t 6- Consultar turnos por responsable \n \t 7- Consultar turnos por fecha \n \t 8- Mostrar listado completo de pacientes \n \t 9- Mostrar listado completo de responsables");
		scanf("%d", &opcion);
		
		switch (opcion) {
			case pac_id: 
				
			break;
			
			case pac_nombre: 
			
			break; 
			
			case responsable_id:
			
			break;
			
			case responsable_nombre:
			
			break; 
			
			case turnos_pacientes:
			
			break;
			
			case turnos_responsables:
			
			break;
			
			case turnos_fecha:
			
			break;
			
			case listado_pacientes:
			
			break;
			
			case listado_responsables:
			
			break;
			
			case volver: 
			loop=0;
			break;
			
			default: 
				printf("Opcion invalida, intente nuevamente");
		
			}
		}
	
	}
