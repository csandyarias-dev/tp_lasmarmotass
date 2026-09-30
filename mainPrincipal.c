/**
	\file    mainPrincipal.c
	\brief   <Que contiene el archivo>
	\author  <Apellido y Nombre (mail)>
	\date    <Año.Mes.Día> 
	\version <Versión (ejemplo: 1.0.0)>

	Compilación: 	gcc -c mainPrincipal.c -o mainPrincipal.o -Wall
					gcc -c funciones.c -o funciones.o -Wall
	Linkeo: 		gcc main_ejemplo.o funciones.o -o ejecutable -Wall
	Ejecución: 		./ejecutable
*/


//--------------
//-- Includes --
//--------------
#include "encabezadogeneral.h"

/**
	\fn      <Prototipo de la función>
	\brief   <Función de la función>
	\author  <Apellido y Nombre (mail)>
	\date    <Año.Mes.Día>
	\param   <Parámetro A (si no tiene no se pone)>
	\param   <Parámetro B (si no tiene no se pone)>
	\return  <Lo que retorna>
*/

int main(void) {
	int salir=OK, entrada=0;
	
	while(salir)	{
		printf("Ingrese \n \t 1- Consultar informacion. \n \t 2- Agregar turno \n \t 3- Acceder al menu pacientes. \n \t 4- Acceder al menu responsables. \n \t 5- Acceder al menu configuracion. \n \t 6-Salir \n");
		switch (entrada) {
			case consultar_informacion:
				menu1();
			break;
			
			case agregar_turno:
			
			break;
			
			case menu_paciente: 
			
			break; 
			
			case menu_responsable:
			
			break;
			
			case menu_configuracion:
			
			break 
			
			case salir:
			
			break;
			
			default:
			printf("Entrada invalida, intente nuevamente.");
			break;
			}
		
		
		}
	
	}
