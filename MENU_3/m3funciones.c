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

int agregar_paciente(nodo_paciente_t ** primero, int * ultimo_ID_utilizado) {
    paciente_t cliente;
    int estado=ERROR_MEMORIA;
        
    printf("Ingrese tipo de paciente: "); // AMPLIAR 
    
    printf("Ingrese nombre del paciente: ");
    scanf(" %[^\n]", cliente.nombre); 
    
    printf("Ingrese la fecha de nacimiento SIGUIENDO el siguiente formato DD-MM-AAAA");
    scanf("%d-%d-%d", &(cliente.nacimiento.bits1.dia), &(cliente.nacimiento.bits1.mes), &(cliente.nacimiento.bits1.anio));

    cliente.pacID=(*ultimo_ID_utilizado)+1;
    
    if (anadir_ordenado(primero, cliente) != OK) printf("ERROR AL AÑADIR"); 
    else { 
        printf("añadido con exito");
        estado=OK;
        (*ultimo_ID_utilizado)++;
    }

    return estado; 
}

int anadir_ordenado(nodo_paciente_t ** lista, paciente_t cliente){
    nodo_paciente_t * nuevo = NULL, * auxp = NULL, * anterior= NULL, *actual = NULL;
    int estado=ERROR_MEMORIA; 
    
    auxp =(nodo_paciente_t *) malloc(sizeof(nodo_paciente_t)); 
    
    if (auxp!=NULL) { 
        nuevo = auxp; 
        
        nuevo->paciente=cliente; 
        nuevo->sig=NULL; 
        
        actual = *lista;
        
        while ((actual!=NULL) && (strcmp(actual->paciente.nombre, cliente.nombre)<0))
        {
            anterior = actual;
            actual = actual->sig;                                                              
        }
        
        if (anterior!=NULL){ 
            anterior->sig=nuevo; 
            nuevo->sig=actual;
        }
        else {
            nuevo->sig=*lista; 
            *lista=nuevo;    
        }
        estado=OK;
    }
    else estado=ERROR_MEMORIA;
    
    return estado; 
}

int modificar_paciente(nodo_paciente_t ** lista){
    int opcion, idBuscado=0, encontrado=0; 
    char nombre[30]={0};
    nodo_paciente_t * anterior = NULL, * actual = NULL, * siguiente = NULL; 
    
    do {
        printf("Ingrese 1 para buscar por nombre y 2 para buscar por ID");
        scanf("%d", &opcion);
    } while((opcion!=1) && (opcion!=2));
    
    if (opcion==1){
        scanf(" %[^\n]", nombre); 
        actual=*lista;    
     
        while ((actual!=NULL) && (encontrado==0)){
            if (strcmp(actual->paciente.nombre, nombre)!=0)
            {
                anterior = actual; 
                actual=actual->sig;
            }
            else {
                siguiente=actual->sig; 
                if ((siguiente!=NULL) && (strcmp(siguiente->paciente.nombre, nombre)==0)) {
                    printf("Duplicado, debe modificar ingresando el ID\n");
                    mostrar_paciente(actual);
                    mostrar_paciente(siguiente);
                    encontrado = 1; 
                }
                else {
                    modificar_nodo(actual);
                    encontrado = 1; 
                }
            }
        }
        if (encontrado==0) printf("Paciente no encontrado\n"); 
    }
    else if (opcion==2){
        printf("Ingrese ID");
        scanf("%d", &idBuscado); 
        
        actual=*lista; 
            if (actual->paciente.pacID==idBuscado){
                encontrado=1; 
                modificar_nodo(actual);
            }
            else {
                anterior=actual;
                actual=actual->sig; 
            }    
        }
        if (encontrado==0) printf("Paciente no encontrado\n");        
    }

    return encontrado; 
}
    
int modificar_nodo(nodo_paciente_t * actual){
    int opcion;
    char nombreN[30]={0};
    int estado = 0; 
    
    printf("El paciente a modificar es:");
    mostrar_paciente(actual); 
    
    printf("Ingrese el numero del item a modificar: \n \t 1- Nombre \n \t 2- Fecha de nacimiento \n \t 3- ID del responsable");
    scanf("%d", &opcion);
    
    switch(opcion){
        case NOMBRE: 
            printf("Ingrese el nombre nuevo");
            scanf(" %[^\n]", nombreN); 
            
            strcpy(actual->paciente.nombre, nombreN);        
            estado = OK;
        break; 
        
        case FECHA_NACIMIENTO:
            printf("Ingrese la fecha de nacimiento SIGUIENDO el siguiente formato DD-MM-AAAA");
            scanf("%d-%d-%d", &(actual->paciente.nacimiento.bits1.dia), &(actual->paciente.nacimiento.bits1.mes), &(actual->paciente.nacimiento.bits1.anio));
            estado = OK;
        break;
        
        case ID_RESPONSABLE:
            printf("Ingrese el nuevo ID del responsable: "); 
            scanf("%d", &(actual->paciente.responID)); 
            estado = OK;
        break;
    }
    
    return estado; 
}

int eliminar_paciente (nodo_paciente_t ** lista) {
    int opcion, idBuscado=0, encontrado=0; 
    char nombre[30]={0};
    nodo_paciente_t * anterior = NULL, * actual = NULL, * siguiente = NULL; 
    
    do {
        printf("Ingrese 1 para buscar el paciente por nombre y 2 para buscar por ID: ");
        scanf("%d", &opcion);
    } while((opcion!=1) && (opcion!=2));
    
    if (opcion==1){
        scanf(" %[^\n]", nombre);
        actual=*lista;    
     
        while ((actual!=NULL) && (encontrado==0)){
            if (strcmp(actual->paciente.nombre, nombre)!=0)
            {
                anterior = actual; 
                actual=actual->sig;
            }
            else {
                siguiente=actual->sig; 
                if ((siguiente!=NULL) && (strcmp(siguiente->paciente.nombre, nombre)==0)) {
                    printf("Duplicado, debe eliminar ingresando el ID\n"); 
                    mostrar_paciente(actual); 
                    mostrar_paciente(siguiente); 
                    
                    encontrado = 1; 
                }
                else {
                    eliminar_nodo(lista, actual, anterior); 
                    encontrado = 1; 
                }
            }
        }
        if (encontrado==0) printf("Paciente no encontrado\n"); 
    }
    else if (opcion==2){
        printf("Ingrese ID: ");
        scanf("%d", &idBuscado); 
        
        actual=*lista; 
        
        while ((actual!=NULL) && (encontrado==0)){
            if (actual->paciente.pacID==idBuscado){
                encontrado=1; 
                eliminar_nodo(lista, actual, anterior); 
            }
            else {
                anterior=actual;
                actual=actual->sig; 
            }    
        }
        if (encontrado==0) printf("Paciente no encontrado\n");        
    }
    
    return encontrado; 
}

int eliminar_nodo(nodo_paciente_t ** lista, nodo_paciente_t * actual, nodo_paciente_t * anterior) {
    int estado = ERROR; 
    
    if (actual != NULL) {
        if (anterior == NULL) *lista = actual->sig;
        else  anterior->sig = actual->sig; 
        }
        
        free(actual);
        estado = 0; 
    }
    return estado; 
}	
	
void mostrar_paciente(nodo_paciente_t * actual) {
    if (actual != NULL) {
        printf("ID: %d | Nombre: %s | Nacimiento: %02d-%02d-%04d | Resp: %d\n", 
            actual->paciente.pacID, 
            actual->paciente.nombre, 
            actual->paciente.nacimiento.bits1.dia, 
            actual->paciente.nacimiento.bits1.mes, 
            actual->paciente.nacimiento.bits1.anio,
            actual->paciente.id_responsable);
    }
}
