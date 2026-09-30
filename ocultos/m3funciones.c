/**
	\file    m3funciones.c
	\brief   Contienen las funciones pertenecientes al menu 3
	\author  Grupo las marmotas
	\date    2026.09.02
	\version 1.0.0
*/

//--------------
//-- Includes --
//--------------
#include "m3funciones.h"
#include "../encabezadogeneral.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//---------------
//-- Funciones --
//---------------
int agregarPaciente(nodo_paciente_t ** primero, int * ultimo_ID_utilizado) {
	
	paciente_t cliente;
	int estado=ERROR_MEMORIA;
		
	printf("Ingrese tipo de paciente: "); // AMPLIAR 
	
	printf("Ingrese nombre del paciente: ");
	scanf(" %[^\n]", cliente.nombre);
	
	printf("Ingrese la fecha de nacimiento SIGUIENDO el siguiente formato DD-MM-AAAA");
	scanf("%d-%d-%d", &(cliente.nacimiento.bits1.dia), &(cliente.nacimiento.bits1.mes), &(cliente.nacimiento.bits1.anio));

	
	cliente.pacID=(*ultimo_ID_utilizado)+1;
	
	if (anadirordenado_c(primero, nuevo)) printf("ERROR AL AÑADIR");
	else { 
		printf("añadido con exito");
		estado=OK;
		(*ultimo_ID_utilizado)++;
	}

	return estado;
	
	}
	
int anadirordenado_c(nodo_paciente_t ** lista, paciente_t cliente){
	
	nodo_paciente_t * nuevo = NULL, * auxp = NULL, * anterior= NULL, *actual = NULL;
	int estado=ERROR_MEMORIA, i, j;
	
	auxp =(nodo_paciente_t *) malloc(sizeof(nodo_paciente_t)); 
	
	if (auxp!=NULL) {
		nuevo = auxp; 
		
		nuevo->paciente=cliente; 
		nuevo->sig=NULL; 
		
		actual = *lista;
		
		while ((actual->sig!=NULL)&&(strcmp(nuevo->paciente.nombre, actual->paciente.nombre)>=0)
		{
			ant = actual;        
			actual = actual->sig;                                                              
		}
		if (ant!=NULL){
			ant->sig=nuevo; 
			nuevo->sig=actual;
		}
		else {
			if ((*lista)!=NULL) nuevo->sig=*lista; 
			else *lista=nuevo;  	
		}
		estado=OK;
	}
	else estado=ERROR_MEMORIA;
	
	return estado;
}

int modificarPaciente(nodo_paciente_t ** lista){
	
	int opcion, paciente=0;
	char nombre[30]={0};
	nodo_paciente_t * anterior, * actual, * siguiente, * encontrado;
	printf("Ingrese 1 para buscar por nombre y 2 para buscar por ID");
	scanf("%d", &opcion);	
	if (opcion==1){
		scanf("%s", nombre);
		actual=*lista;	
		while (actual->sig!=NULL){
			if (strcmp(actual->paciente.nombre, nombre)!=0)
			{
				anterior = actual; 
				actual=actual->sig;
			}
			else {
				siguiente=actual->sig; 
				if (strcmp(siguiente->paciente.nombre, nombre)!=0) modificarNodo(actual);
				else printf("Duplicado, debe modificar ingresando el ID");
			}
		}
	  }
	else if (opcion==2){
		printf("Ingrese ID");
		scanf("%d", ID);
		
		while (actual->sig!=NULL){
			if (actual->paciente.pacID==ID){
				encontrado++; 
				modificarNodo(&actual);
			}
			else {
				anterior=actual;
				actual=actual->sig; 
			}	
			}
			if (encontrado==0) printf("Paciente no encontrado");		
	}
	else {
		printf("Opcion invalida, intente nuevamente");
		modificarPaciente(lista);
	}
	}
	
	int modificarPaciente(nodo_paciente_t ** lista){
	
	int opcion, paciente=0;
	char nombre[30]={0};
	nodo_paciente_t * anterior, * actual, * siguiente, * encontrado;
	
	do {
	printf("Ingrese 1 para buscar por nombre y 2 para buscar por ID");
	scanf("%d", &opcion);
	} while((opcion!=1)||(opcion!=2));	
	
	if (opcion==1){
		scanf("%s", nombre);
		actual=*lista;	
		while (actual->sig!=NULL){
			if (strcmp(actual->paciente.nombre, nombre)!=0)
			{
				anterior = actual; 
				actual=actual->sig;
			}
			else {
				siguiente=actual->sig; 
				if (strcmp(siguiente->paciente.nombre, nombre)!=0) modificarNodo(actual);
				else printf("Duplicado, debe modificar ingresando el ID");
			}
		}
	  }
	else if (opcion==2){
		printf("Ingrese ID");
		scanf("%d", ID);
		
		while (actual->sig!=NULL){
			if (actual->paciente.pacID==ID){
				encontrado++; 
				modificarNodo(&actual);
			}
			else {
				anterior=actual;
				actual=actual->sig; 
			}	
			}
			if (encontrado==0) printf("Paciente no encontrado");		
	}
	}


// hasta aca
int modificarNodo(nodo_paciente_t * actual){
	int opcion;
	char nombreN[30]={0};
	
	printf("El paciente a modificar es:");
	mostrarPaciente(actual);
	
	printf("Ingrese el numero del item a modificar: \n \t 1- Nombre \n \t 2- Fecha de nacimiento \n \t 3- ID del responsable");
	scanf("%d", &opcion);
	
	switch(opcion){
		case NOMBRE:
			printf("Ingrese el nombre nuevo");
			scanf("%[^\n]", nombreN);
			
			strcpy(actual->paciente.nombre, nombreN);		
		
		break; 
		
		case FECHA_NACIMIENTO:
			printf("Ingrese la fecha de nacimiento SIGUIENDO el siguiente formato DD-MM-AAAA");
			scanf("%d-%d-%d", &(actual->paciente.nacimiento.bits1.dia), &(actual->paciente.nacimiento.bits1.mes), &(actual->paciente.nacimiento.bits1.anio));
			
		
		break;
		
		case ID_RESPONSABLE:
		
		break;
		
		
		}
	
	
	}
