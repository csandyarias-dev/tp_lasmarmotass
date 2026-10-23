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
#include <stdio.h>

//--------------
//-- Defines --
//--------------

int flag_alarma=0;
int flag_modificacion=0;

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
	int salir=OK, entrada=0, ultimo_id=0;
	nodo_paciente_t * primero_pac = NULL;
	nodo_responsable_t * primero_resp = NULL; 
	nodo_turnos_t * primero_turnos = NULL;
	
	alarm(120);
	signal(SIGALRM, alarma_handler); 
	
	importar_desde_archivo(&ultimo_id, &primero_pac, &primero_resp, &primero_turnos);
	
	while(salir)	{
		if (flag_alarma) {
			act_archivos();
			}
		
		printf("Ingrese \n \t 1- Consultar informacion. \n \t 2- Agregar turno \n \t 3- Acceder al menu pacientes. \n \t 4- Acceder al menu responsables. \n \t 5- Acceder al menu configuracion. \n \t 6-Salir \n");
		switch (entrada) {
			case consultar_informacion:
				m1menu(&primero_pac, &primero_resp, &primero_turnos);
			break;
			
			case agregar_turno:
				agregar_turno(&primero_turnos);
			break;
			
			case menu_paciente: 
				m3menu(&ultimo_id, &primero_pac, &primero_resp, &primero_turnos);
			break; 
			
			case menu_responsable:
				
			break;
			
			case menu_configuracion:
			
			break;
			
			case salir:
				salir=0;
				// JOIN THREAD ARCHIVOS PARA QUE TERMINE DE CARGAR O PTHREADEXIT();
				printf("Sesion finalizada");
			break;
			
			default:
			printf("Entrada invalida, intente nuevamente.");
			break;
			}
		
		}
		// LIBERAR VARIABLES DINAMICAS 
		// DESTROY MUTEX 
		return 0;
	}
