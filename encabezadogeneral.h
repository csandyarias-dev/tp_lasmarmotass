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
//-- Defines --
//--------------

extern int flag_alarma;

//-------------
//-- Structs --
//-------------

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
	

//-------------
//-- Enums --
//-------------

enum ERRORES_GENERALES{ERROR_MEMORIA=-2, ERROR_ARCHIVO, OK=1};
enum MENU_PRINCIPAL{CONSULTAR_INFORMACION=1, AGREGAR_TURNO, MENU_PACIENTE, MENU_RESPONSABLE, MENU_CONFIGURACION, SALIR};
enum OPCIONES_MENU4 {OPCION_AGREGAR = 1, OPCION_MODIFICAR, OPCION_ELIMINAR, OPCION_VOLVER};

//--------------
//-- Includes --
//--------------

#include "MENU_1/m1funciones.h"
#include "MENU_3/m3funciones.h"
#include "MENU_4/m4funciones.h"
#include "MENU_5/m5funciones.h"


//----------------
//-- Prototipos --
//----------------

/**
	\fn     int cargar_pacientes_archivo(nodo_paciente_t ** lista, int *ultimoPacID);
	\brief  Se carga un paciente al archivo
	\author Grupo Las Marmotas
	\date   2026.09.02
	\param  int ultimo_id, nodo_paciente_t ** primero_pac, nodo_responsable_t **  primero_resp, nodo_turnos_t ** primero_turnos
	\return int estado
*/
int cargar_pacientes_archivo(nodo_paciente_t ** lista, int *ultimoPacID);


/**
	\fn    int cargar_responsables_archivo(nodo_responsable_t ** lista, int *ultimoResponID);
	\brief  Se carga un responsable al archivo
	\author Grupo Las Marmotas
	\date   2026.09.02
	\param  int ultimo_id, nodo_paciente_t ** primero_pac, nodo_responsable_t **  primero_resp, nodo_turnos_t ** primero_turnos
	\return int estado
*/
int cargar_responsables_archivo(nodo_responsable_t ** lista, int *ultimoResponID);


/**
	\fn     int cargar_turnos_archivo(nodo_turnos_t ** lista);
	\brief  Se carga un turno al archivo
	\author Grupo Las Marmotas
	\date   2026.09.02
	\param  int ultimo_id, nodo_paciente_t ** primero_pac, nodo_responsable_t **  primero_resp, nodo_turnos_t ** primero_turnos
	\return int estado
*/
int cargar_turnos_archivo(nodo_turnos_t ** lista);


/**
	\fn     void agregar_turno(nodo_turnos_t ** turnos);
	\brief  Se agrega el turno a la lista
	\author Grupo Las Marmotas
	\date   2026.09.02
	\param  int ultimo_id, nodo_paciente_t ** primero_pac, nodo_responsable_t **  primero_resp, nodo_turnos_t ** primero_turnos
	\return int estado
*/
void agregar_turno(nodo_turnos_t ** turnos);


/**
	\fn     int importar_desde_archivo(int ultimo_id, nodo_paciente_t ** primero_pac, nodo_responsable_t **  primero_resp, nodo_turnos_t ** primero_turnos);
	\brief  Se agrega un paciente a la lista
	\author Grupo Las Marmotas
	\date   2026.09.02
	\param  int ultimo_id, nodo_paciente_t ** primero_pac, nodo_responsable_t **  primero_resp, nodo_turnos_t ** primero_turnos
	\return int estado
*/
int importar_desde_archivo(int * ultimo_id, nodo_paciente_t ** primero_pac, nodo_responsable_t **  primero_resp, nodo_turnos_t ** primero_turnos);
	
#endif	
