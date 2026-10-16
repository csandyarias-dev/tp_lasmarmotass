#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "encabezadogeneral.h"

#define MAX_LETRAS_NOMBRE 30
#define MAX_CARACTERES_FECHA 11


/*                          FUNCIONES PARA IMPRIMIR LOS DATOS                     */


/*Funcion para imprimir los datos del paciente encontrado:*/
void mostrar_paciente(nodo_paciente_t * actual) {
    if (actual != NULL) {
        printf("ID: %d | Nombre: %s | Nacimiento: %02d-%02d-%04d | Resp ID: %d\n", 
            actual->paciente.pacID, 
            actual->paciente.nombre, 
            actual->paciente.nacimiento.bits.dia, 
            actual->paciente.nacimiento.bits.mes, 
            actual->paciente.nacimiento.bits.anio,
            actual->paciente.responID);
    }
}

/*Funcion para imprimir los datos del responsable encontrado:*/
void mostrar_responsable(nodo_responsable_t * actual) {
    if (actual != NULL) {
        printf("Resp ID: %d | Nombre: %s %s | Tel: %lu\n", 
            actual->responsable.responID, 
            actual->responsable.nombre, 
            actual->responsable.apellido, 
            actual->responsable.telcont);
    }
}


/*Funciones para imprimir los datos del turno(fecha y hora)*/
// Imprime únicamente la fecha con formato DD-MM-AAAA
void imprimir_fecha(nfecha_t f) {
    printf("%02d-%02d-%04d", f.dia, f.mes, f.anio);
}

// Imprime la hora formateada HH:MM AM/PM
void imprimir_hora(nhora_t h) {
    // Si la estructura usa un campo am_pm de 1 bit: 0 = AM, 1 = PM
    const char *periodo = (h.AM_PM == 0) ? "AM" : "PM";
    printf("%02d:%02d %s", h.hora, h.min, periodo);
}

// Imprime combinación de fecha y hora juntos
void imprimir_fecha_hora(nfecha_t f, nhora_t h) {
    imprimir_fecha(f);
    printf(" ");
    imprimir_hora(h);
}

/*                          FUNCIONES PARA CHEQUEAR LOS DATOS                     */
//funcion para chequear que el dato ingresado es un numero. usada para ID.



/*                          FUNCIONES DEL MAIN 1                                           */

//FUNCIONES INTERNAS: Son las funciones donde buscamos coincidencias del dato pedido en la struct

//Funcion Interna 1: busca coincidencias de ID en la lista de pacientes e imprime cada coincidencia.Devuelve la cantidad de coincidencias.
int ConsultarCoincidencias_PacienteID(nodo_paciente_t *lista_pacientes, int id_ingresado, nodo_paciente_t **Paciente_encontrado){
    int contador = 0;
    nodo_paciente_t *aux_pacientes = lista_pacientes;
  
    while (aux_pacientes != NULL) { 
        if (aux_pacientes->paciente.pacID == id_ingresado) { 
            // Imprime los datos del paciente encontrado
            mostrar_paciente(aux_pacientes);

            if (Paciente_encontrado == NULL) { 
                *Paciente_encontrado = aux_pacientes;
            }
            contador++; 
        }
        aux_pacientes = aux_pacientes->sig; 
    }

    return contador; // Devuelve la cantidad de coincidencias
}

//Funcion Interna 2: busca coincidencias de nombre en la lista de pacientes e imprime cada coincidencia. Devuelve la cantidad de coincidencias.
int ConsultarCoincidencias_PacienteNombre(nodo_paciente_t *lista_pacientes, const char *nombre_ingresado, nodo_paciente_t **Paciente_encontrado){
    int contador = 0;
    nodo_paciente_t *aux_pacientes = lista_pacientes;

    while (aux_pacientes != NULL) { 
        if (strcmp(aux_pacientes->paciente.nombre, nombre_ingresado) == 0) { 
            // Imprime los datos del paciente encontrado
            mostrar_paciente(aux_pacientes);

            if (Paciente_encontrado == NULL) { 
                *Paciente_encontrado = aux_pacientes; 
            }
            contador++; 
        }
        aux_pacientes = aux_pacientes->sig; 
    }

    return contador; // Devuelve la cantidad de coincidencias
}

//Funcion Interna 3: busca coincidencias de ID en la lista de responsables e imprime cada coincidencia.Devuelve la cantidad de coincidencias-
int ConsultarCoincidencias_ResponsableID(nodo_responsable_t *lista_responsables, int id_ingresado, nodo_responsable_t **Responsable_encontrado){
    int contador = 0;
    nodo_responsable_t *aux_responsables = lista_responsables;
  
    while (aux_responsables != NULL) { 
        if (aux_responsables->responsable.responID == id_ingresado) { 
            // Imprime los datos del responsable encontrado
            mostrar_responsable(aux_responsables);

            if (Responsable_encontrado == NULL) { 
                *Responsable_encontrado = aux_responsables;
            }
            contador++; 
        }
        aux_responsables = aux_responsables->sig; 
    }
      
    return contador; // Devuelve la cantidad de coincidencias
}

//Funcion Interna 4: busca coincidencias de nombre en la lista de responsables e imprime cada coincidencia. Devuelve la cantidad de coincidencias.
int ConsultarCoincidencias_ResponsableNombre(nodo_responsable_t *lista_responsables, const char *nombre_ingresado, nodo_responsable_t **Responsable_encontrado){
    int contador = 0;
    nodo_responsable_t *aux_responsables = lista_responsables;

    while (aux_responsables != NULL) { 
        if (strcmp(aux_responsables->responsable.nombre, nombre_ingresado) == 0) { 
            // Imprime los datos del responsable encontrado
            mostrar_responsable(aux_responsables);

            if (Responsable_encontrado == NULL) { 
                *Responsable_encontrado = aux_responsables; 
            }
            contador++; 
        }
        aux_responsables = aux_responsables->sig; 
    }

    return contador; // Devuelve la cantidad de coincidencias
}

//Funcion Interna 5: la funcion busca coincidencias por nombre y apellido en la lista de turnos.  Devuelve la variable contador
   //->la idea es que primero se use la funcion ConsultarCoincidencias_PacienteNombre(), si es que existe el unico nombre que se quiere buscar(la funcion retorna 1) abajo se use esta.
int ConsultarTurnos_PacienteNombre(nodo_turnos_t *lista_turnos, const char *nombre_ingresado, nodo_turnos_t ***turnos_encontrados) {
    int contador = 0, i = 0;
    nodo_turnos_t *aux_turnos = lista_turnos, **vector_turnos = NULL;

    while (aux_turnos != NULL) {                                                            //contamos cuantos turnos hay registrados con ese nombre
        if (strcmp(aux_turnos->turno.paciente.nombre, nombre_ingresado) == 0) {
            contador++;
        }
        aux_turnos = aux_turnos->sig;
    }                                                                                       //la variable contador termina con el valor de la cantidad de turnos que tuvo el paciente

    if (contador > 0) {                                                                     //Si se encontraron turnos, reservar memoria y hacer el segundo recorrido
        if (turnos_encontrados != NULL) {
            33  //se le da la memoria al vector segun la cantidad de turnos en contrados para imprimirlos posteriormente
        }
            if (turnos_encontrados == NULL || vector_turnos != NULL) {                      
                aux_turnos = lista_turnos;                                                  

                while (aux_turnos != NULL) {
                    if (strcmp(aux_turnos->turno.paciente.nombre, nombre_ingresado) == 0) {
                        
                        mostrar_turno(aux_turnos);                                            // Imprime fecha y hora mediante la función atómica
                        if (vector_turnos != NULL) {                                          // Almacena el puntero en el vector dinámico
                            vector_turnos[i] = aux_turnos;
                            i++;
                        }
                    }
                    aux_turnos = aux_turnos->sig;
                }
        } else {
                                                                                      // Si falló el malloc, la cantidad devuelta se resetea a 0
            contador = 0;
        }
    }
    if (turnos_encontrados != NULL) {                                                   // Asignación final del vector reservado (o NULL si no hubo coincidencias/falló malloc)
        *turnos_encontrados = vector_turnos;
    }
    return contador;
}
//funcion interna 6: c 
int ConsultarTurnos_Fecha(nodo_turnos_t *lista_turnos, nfecha_t fecha_ingresada, nodo_turnos_t ***turnos_encontrados) {
    int contador = 0, i = 0;
    nodo_turnos_t *aux_turnos = lista_turnos, **vector_turnos = NULL;

    if (es_fecha_valida(fecha_ingresada)) {                                                 //buscamos que existan turnos el dia de la fecha
                                                                                            // Primer recorrido: contar coincidencias que coincidan en día, mes y año
        while (aux_turnos != NULL) {
            if (aux_turnos->turno.fecha.dia  == fecha_ingresada.dia &&
                aux_turnos->turno.fecha.mes  == fecha_ingresada.mes &&
                aux_turnos->turno.fecha.anio == fecha_ingresada.anio) {
                contador++;
            }
            aux_turnos = aux_turnos->sig;
        }
                                                                                            //  Si hay coincidencias, reservar memoria dinámica con malloc
        if (contador > 0) {
            if (turnos_encontrados != NULL) {
                vector_turnos = (nodo_turnos_t **) malloc(contador * sizeof(nodo_turnos_t *));
            }
                                                                                             // Si la memoria se asignó correctamente o no se requirió guardar el arreglo
            if (turnos_encontrados == NULL || vector_turnos != NULL) {
                aux_turnos = lista_turnos;
                                                                                            // Segundo recorrido: imprimir y guardar los turnos
                while (aux_turnos != NULL) {
                    if (aux_turnos->turno.fecha.dia  == fecha_ingresada.dia &&
                        aux_turnos->turno.fecha.mes  == fecha_ingresada.mes &&
                        aux_turnos->turno.fecha.anio == fecha_ingresada.anio) {
                    
                        mostrar_turno(aux_turnos);                                           // Imprime los datos del turno (fecha y hora) con la función atómica
                        
                        if (vector_turnos != NULL) {                                         // Almacena la dirección del nodo en el vector dinámico
                            vector_turnos[i] = aux_turnos;
                            i++;
                        }
                    }
                    aux_turnos = aux_turnos->sig;
                }
            } else {
                contador = 0;                                                               // Si malloc falla, resetea el contador a 0
            }
        }

    } else {
        printf("Error: La fecha ingresada (%02d/%02d/%04d) no existe o es invalida.\n", 
               fecha_ingresada.dia, fecha_ingresada.mes, fecha_ingresada.anio);
    }

    if (turnos_encontrados != NULL) {                                                       // Guardar el puntero al vector reservado en la variable dada por referencia
        *turnos_encontrados = vector_turnos;
    }
    return contador;
}

// Funcion Interna 7: busca coincidencias por nombre de responsable en la lista de turnos. Devuelve la cantidad de coincidencias.
int ConsultarTurnos_ResponsableNombre(nodo_turnos_t *lista_turnos, const char *nombre_ingresado, nodo_turnos_t ***turnos_encontrados) {
    int contador = 0, i = 0;
    nodo_turnos_t *aux_turnos = lista_turnos, **vector_turnos = NULL;

    // 1. Primer recorrido: contamos cuántos turnos hay registrados con el nombre del responsable
    while (aux_turnos != NULL) {
        if (strcmp(aux_turnos->turno.responsable.nombre, nombre_ingresado) == 0) {
            contador++;
        }
        aux_turnos = aux_turnos->sig;
    }

    // 2. Si se encontraron turnos, reservamos memoria dinámica y realizamos el segundo recorrido
    if (contador > 0) {
        if (turnos_encontrados != NULL) {
            vector_turnos = (nodo_turnos_t **) malloc(contador * sizeof(nodo_turnos_t *));
        }

        if (turnos_encontrados == NULL || vector_turnos != NULL) {
            aux_turnos = lista_turnos;

            while (aux_turnos != NULL) {
                if (strcmp(aux_turnos->turno.responsable.nombre, nombre_ingresado) == 0) {
                    
                    mostrar_turno(aux_turnos); // Imprime fecha y hora mediante la función atómica
                    
                    if (vector_turnos != NULL) { // Almacena el puntero en el vector dinámico
                        vector_turnos[i] = aux_turnos;
                        i++;
                    }
                }
                aux_turnos = aux_turnos->sig;
            }
        } else {
            // Si falló el malloc, la cantidad devuelta se resetea a 0
            contador = 0;
        }
    }

    // Asignación final del vector reservado (o NULL si no hubo coincidencias/falló malloc)
    if (turnos_encontrados != NULL) {
        *turnos_encontrados = vector_turnos;
    }

    return contador;
}

//FUNCIONES EXTERNAS: Son las funciones donde usamos las funciones internas

/--------------------------------------/Funcion externa 1: ----------------------------------------------------------------------------
void ConsultarPacientePorID_Menu1(nodo_paciente_t *lista_pac, nodo_responsable_t *lista_resp, nodo_paciente_t **Paciente_encontrado){
int id_ingresado = 0, resultado_funcion = 0;

printf(" \ningrese el ID del paciente:");
 scanf("%d", &ID_ingresado);

 
 resultado_funcion = ConsultarCoincidencias_PacienteID(lista_pacientes, id_ingresado, &Paciente_encontrado);

    if(resultado_funcion == 0){
        printf("No existe ese ID. Vuelva a intentarlo.");
    }else{
        printf("\n %d resultados de busqueda",resultado_funcion);
    } 

}

//------------------------------------------------------Funcion externa 2: ------------------------------------------
void ConsultarPacientePorNombre_Menu1(nodo_paciente_t *lista_pac, nodo_responsable_t *lista_resp, nodo_paciente_t **Paciente_encontrado ){
  int  resultado_funcion = 0;
  char nombre_ingresado[MAX_LETRAS_NOMBRE];

  printf(" \nIngrese el Nombre del paciente:  ");
  scanf("%c", &nombre_ingresado); 
   
  resultado_funcion = ConsultarCoincidencias_PacienteNombre(lista_pacientes, nombre_ingresado, &Paciente_encontrado);
  
  if(resultado_funcion == 0){
        printf("\nNo existe ese nombre ingresado en la lista de pacientes. Vuelva a intentarlo.");
    }else{
        printf("\n %d resultados de busqueda",resultado_funcion);
    } 


}
//----------------------------------------------------Funcion externa 3:------------------------------------------
void ConsultarResponsablePorID_Menu1(nodo_responsable_t *lista_resp, nodo_responsable_t **Responsable_encontrado){
int ID_ingresado = 0, resultado_funcion = 0;

printf(" \ningrese el ID del responsable:");
 scanf("%d", &ID_ingresado);

resultado_funcion = ConsultarCoincidencias_ResponsableID(lista_responsables, id_ingresado, &Responsable_encontrado); 
   if(resultado_funcion == 0){
        printf("\nNo existe ese ID ingresado en la lista de responsables. Vuelva a intentarlo.");
    }else{
        printf("\n %d resultados de busqueda",resultado_funcion);
    } 
}

//---------------------------------------funcion externa 4:-------------------------------------------------------------

void ConsultarResponsablePorNombre_Menu(nodo_responsable_t *lista_resp, nodo_responsable_t **Responsable_encontrado){
  int  resultado_funcion = 0;
  char nombre_ingresado[MAX_LETRAS_NOMBRE];

  printf(" \nIngrese el Nombre del responsable:  ");
  scanf("%c", &nombre_ingresado); 
  
   resultado_funcion = ConsultarCoincidencias_ResponsableNombre(lista_responsables, nombre_ingresado, &Responsable_encontrado);
   
   if(resultado_funcion == 0){
        printf("\nNo existe ese nombre ingresado en la lista de pacientes. Vuelva a intentarlo.");
    }else{
        printf("\n %d resultados de busqueda",resultado_funcion);
    } 

}
//---------------------------------------funcion externa 5:-------------------------------------------------------------
void ConsultarTurnosPorPacientes_Menu1(nodo_paciente_t *lista_pac, nodo_turnos_t *lista_turnos, nodo_turnos_t ***turnos_encontrados){
int  resultado_funcion = 0;
schar nombre_ingresado[MAX_LETRAS_NOMBRE];

  printf("ingrese el nombre del paciente del cual quiere saber los turnos");
  scanf("%d",nombre_ingresado);
  resultado_funcion = ConsultarTurnos_PacienteNombre(&lista_turnos, &nombre_ingresado, &turnos_encontrados);
  
   if(resultado_funcion == 0){
        printf("\nNo existe ese nombre ingresado en la lista de pacientes. Vuelva a intentarlo.");
    }else{
        printf("\n %d resultados de busqueda",resultado_funcion);
    } 

}

//---------------------------------------funcion externa 6:-------------------------------------------------------------

void ConsultarTurnosPorResponsable_Menu1(nodo_responsable_t *lista_resp, nodo_turnos_t *lista_turnos, nodo_turnos_t ***turnos_encontrados){
int  resultado_funcion = 0;
char nombre_ingresado[MAX_LETRAS_NOMBRE];

  printf("ingrese el nombre del responsable del cual quiere saber los turnos");
  scanf("%c",nombre_ingresado);
  resultado_funcion = ConsultarTurnos_ResponsableNombre(lista_turnos, nombre_buscar, &turnos_encontrados);

 if(resultado_funcion == 0){
        printf("\nNo existe ese nombre ingresado en la lista de pacientes. Vuelva a intentarlo.");
    }else{
        printf("\n %d resultados de busqueda",resultado_funcion);
    } 
}

//---------------------------------------funcion externa 7:-------------------------------------------------------------
void ConsultarTurnosPorFecha_Menu(nodo_turnos_t *lista_turnos, nodo_turnos_t ***turnos_encontrados){
nfecha_t fecha_ingresada;
    char buffer[100];
    int dia, mes, anio;


    printf("ingrese la fecha con el formato DD.MM.AAAA: ");
     if (sscanf(buffer, "%d%*c%d%*c%d", &dia, &mes, &anio) == 3) {
            
            // Asignación a los miembros de la estructura nfecha_t
            fecha_ingresada.dia = dia;
            fecha_ingresada.mes = mes;
            fecha_ingresada.anio = anio;

            printf("Dia: %02d | Mes: %02d | Anio: %04d\n", fecha_ingresada.dia, fecha_ingresada.mes, fecha_ingresada.anio);
            resultado_funcion = ConsultarTurnos_Fecha(lista_turnos, fecha_ingresada, &turnos_encontrados);
    
            if(resultado_funcion == 0){
                    printf("\nNo existe esa fecha ingresada en la lista de turnos. Vuelva a intentarlo.");
            }else{
                    printf("\n %d resultados de busqueda",resultado_funcion);
            } 

        } else {
            printf("Error: El formato ingresado no es valido.\n");
        }

}


//---------------------------------------funcion externa 8:-------------------------------------------------------------

void MostrarListadoCompletoPacientes(nodo_paciente_t *lista_pac){
    
    nodo_paciente_t *aux = lista_pac;

    if (aux == NULL) {
        printf("No hay pacientes registrados en el sistema.\n");
    } else {
        printf("\n=================== LISTADO DE PACIENTES ===================\n");
        while (aux != NULL) {
            mostrar_paciente(aux); // Reutiliza la función atómica de impresión
            aux = aux->sig;
        }
        printf("============================================================\n");
    }
}
  




//---------------------------------------funcion externa 9:-------------------------------------------------------------
void MostrarListadoCompletoResponsables(nodo_responsable_t *lista_resp){
  nodo_responsable_t *aux = lista_resp;

  if (aux == NULL) {
        printf("No hay responsables registrados en el sistema.\n");
  } else {
        printf("\n=================== LISTADO DE PACIENTES ===================\n");
        while (aux != NULL) {
            mostrar_responsable(aux); // Reutiliza la función atómica de impresión
            aux = aux->sig;
        }
        printf("============================================================\n");
    }

}



  
