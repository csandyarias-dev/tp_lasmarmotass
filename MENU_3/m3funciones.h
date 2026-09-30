/**
	\file    m3funciones.h
	\brief   Contienen las funciones pertenecientes al menu 3
	\author  Grupo las marmotas
	\date    2026.09.02
	\version 1.0.0
*/



#ifndef MENU3_H
#define MENU3_H

//--------------
//-- Includes --
//--------------

#include "../encabezadogeneral.h"

//-------------
//-- Structs --
//-------------

enum OPCIONESM3{NOMBRE=1, FECHA_NACIMIENTO, ID_RESPONSABLE};

//----------------
//-- Prototipos --
//----------------

/**
	\fn     int agregarPaciente(nodo_paciente_t ** primero, int * ultimo_ID_utilizado);
	\brief  Se agrega un paciente a la lista
	\author Grupo Las Marmotas
	\date   2026.09.02
	\param  void 
	\return int estado
*/
int agregarPaciente(nodo_paciente_t ** primero, int * ultimo_ID_utilizado);

/**
	\fn     int anadirordenado_p(nodo_paciente_t ** primero, paciente_t nuevo);
	\brief  Se añade a la lista el nuevo paciente 
	\author Grupo Las Marmotas
	\date   2026.09.02
	\param  void 
	\return int estado
*/
int anadirordenado_p(nodo_paciente_t ** primero, paciente_t nuevo);

/**
	\fn     int modificarPaciente(nodo_paciente_t ** primero);
	\brief  Se modifica un paciente de la lista 
	\author Grupo Las Marmotas
	\date   2026.09.02
	\param  void 
	\return int estado
*/
int modificarPaciente(nodo_paciente_t ** primero);

/**
	\fn     int modificarNodo(nodo_paciente_t ** elegido);
	\brief  Se modifica un paciente de la lista 
	\author Grupo Las Marmotas
	\date   2026.09.02
	\param  void 
	\return int estado
*/
int modificarNodo(nodo_paciente_t ** elegido);

/**
	\fn     int eliminarPaciente(nodo_paciente_t ** primero);
	\brief  Se elimina un paciente de la lista 
	\author Grupo Las Marmotas
	\date   2026.09.02
	\param  void 
	\return int estado
*/
int eliminarPaciente(nodo_paciente_t ** primero);
