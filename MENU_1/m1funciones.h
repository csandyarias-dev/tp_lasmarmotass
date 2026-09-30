//==============================================================================
//-- PROTOTIPOS DE FUNCIONES MAIN 1 --
//==============================================================================
/*
Menú 1 - Consultar información
Una vez ingresado al menú 1 mostrará las siguientes opciones:
1.01) Consultar Paciente por ID
1.02) Consultar Paciente por Nombre
1.03) Consultar Responsable por ID
1.04) Consultar Responsable por Nombre y Apellido
1.05) Consultar Turnos por Pacientes
1.06) Consultar Turnos por Responsables
1.07) Consultar Turnos por fecha
1.08) Mostrar el listado completo de Pacientes
1.09) Mostrar el listado completo de Responsables
1.10) Volver
*/
#ifndef ENCABEZADO_MAIN1_H
#define ENCABEZADO_MAIN1_H

//----------------------------------
// Búsquedas y Consultas de Datos 
//----------------------------------

/**
 * Busca coincidencias de paciente por ID en los datos.
 * Retorna OK  si encuentra al menos una coincidencia, o un valor != OK en caso contrario.
 */
int ConsultarPacienteID(nodo_paciente_t *lista_pacientes, int id_ingresado);

/**
 * Busca coincidencias de paciente por Nombre.
 */
int ConsultarPaciente_Nombre(nodo_paciente_t *lista_pacientes, const char *nombre_ingresado);

/**
 * Busca coincidencias de responsable por ID del Paciente o por ID del Responsable.
 */
int ConsultarResponsableID(nodo_responsable_t *lista_responsables, int id_ingresado);

/**
 * Busca coincidencias de responsable por Nombre (y apellido).
 */
int ConsultarResponsableNombre(nodo_responsable_t *lista_responsables, const char *nombre_ingresado);

/**
 * Busca turnos asignados filtrando por nombre o apellido.
 */
int ConsultarTurnos_Paciente(nodo_turnos_t *lista_turnos, const char *nombre_ingresado);

/**
 * Busca turnos por una fecha específica.
 */
int ConsultarTurnos_Fecha(nodo_turnos_t *lista_turnos, nfecha_t fecha_ingresada);

//----------------------------------
// Opciones de Menú 1
//----------------------------------

void ConsultarPacientePorID_Menu(nodo_paciente_t *lista_pac, nodo_responsable_t *lista_resp);
void ConsultarPacientePorNombre_Menu(nodo_paciente_t *lista_pac, nodo_responsable_t *lista_resp);
void ConsultarResponsablePorID_Menu(nodo_responsable_t *lista_resp);
void ConsultarResponsablePorNombre_Menu(nodo_responsable_t *lista_resp);
void ConsultarTurnosPorPacientes_Menu(nodo_paciente_t *lista_pac, nodo_turnos_t *lista_turnos);
void ConsultarTurnosPorResponsable_Menu(nodo_responsable_t *lista_resp, nodo_turnos_t *lista_turnos);
void ConsultarTurnosPorFecha_Menu(nodo_turnos_t *lista_turnos);
void MostrarListadoCompletoPacientes(nodo_paciente_t *lista_pac);
void MostrarListadoCompletoResponsables(nodo_responsable_t *lista_resp);
void MenuPrincipal(void);

#endif 