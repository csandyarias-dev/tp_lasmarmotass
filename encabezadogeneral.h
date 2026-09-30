/**
	\file    encabezadogeneral.h
	\brief   Contiene las estructuras comunes a todo el programa
	\author  Grupo las marmotas
	\date    2026.09.02
	\version 1.0.0
*/

#ifndef ENCABEZADOGENERAL_H
#define ENCABEZADOGENERAL_H

//--------------
//-- Includes --
//--------------

#include "MENU_1/m1funciones.h"
#include "MENU_3/m3funciones.h"
#include "MENU_4/m4funciones.h"
#include "MENU_5/m5funciones.h"

//-------------
//-- Structs --
//-------------

typedef struct tipoPac {
	unsigned char tipoID;
	char * nombre;
	} tipopac_t; 
	
	// PACIENTE
	
typedef struct Paciente{
	unsigned char tipoID;
	int pacID;
	char nombre [30];
	nfecha_t nacimiento; 
	int responID;
	}paciente_t;
	
typedef struct nodo_paciente{
	paciente_t paciente;
	struct nodo_paciente * sig;
	}nodo_paciente_t; 
	
	// RESPONSABLE
	
typedef struct Responsable{
	int responID;
	char nombre[30];
	char apellido[30];
	unsigned long int telcont;
	}responsable_t;
	
typedef struct nodo_responsable{
	responsable_t responsable;
	struct nodo_responsable * sig;
	}nodo_responsable_t; 
	
	// TURNOS
	
typedef struct Turnos{
	int responID; 
	int pacID; 
	nfecha_t fecha; 
	nhora_t hora;
	}turnos_t;
	
typedef struct nodo_turnos{
	turnos_t turnos;
	struct nodo_turnos * sig;
	}nodo_turnos_t; 
	
typedef struct {
    unsigned short int min : 6;
    unsigned short int vacio1 : 2;
    unsigned short int hora : 4;   
    unsigned short int vacio2 : 3; 
    unsigned short int am_pm : 1;  
} bits_hora_t;

typedef union {
    unsigned short int valor; 
    bits_hora_t bits;     
} nhora_t;

typedef struct {
    unsigned int anio : 12;  
    unsigned int vacio1 : 1; 
    unsigned int mes : 4;   
    unsigned int vacio2 : 1;  
    unsigned int dia : 5;    
    unsigned int vacio3 : 1;  
} bits_fecha_t;

typedef union {
    unsigned int valor;   
    bits_fecha_t bits1; 
} nfecha_t;

//-------------
//-- Enums --
//-------------

enum errores_generales{ERROR_MEMORIA=-2, ERROR_ARCHIVO, OK=1};
enum menu_principal{consultar_informacion=1, agregar_turno, menu_paciente, menu_responsable, menu_configuracion, salir};	
	
#endif	
