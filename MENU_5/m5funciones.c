#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include "encabezadogeneral.h"

void menu_tipos_animales(tipopac_t **vector_tipos, int *cant_tipos, int *ultimo_tipoID) {
    int opcion = 0; 
    int continuar = 1;

    while(continuar == 1){
        printf("MENU DE CONFIRMACION\n");
        printf("1. Mostrar tipos de animales\n"
            "2. Agregar tipo de animal\n"
            "3.Modificar tipo de animal\n"
            "4. Borrar tipo de animal\n"
            "5. Volver al menú principal\n"
            "Seleccione una opción: ");
        scanf("%d", &opcion);

        if (opcion == 1){
            mostrar_tipos_animales(vector_tipos, cant_tipos, ultimo_tipoID);
        }
        else if (opcion == 2){
            agregar_tipo_animal(vector_tipos, cant_tipos, ultimo_tipoID);
        }
        else if (opcion == 3){
            modificar_tipo_animal(vector_tipos, cant_tipos, ultimo_tipoID);
        }
        else if (opcion == 4){
            borrar_tipo_animal(vector_tipos, cant_tipos , ultimo_tipoID);
        }
        else if (opcion == 5){
            volver_menu_principal(vector_tipos, cant_tipos, ultimo_tipoID);
            continuar = 0;
        }
        else if (opcion < 1 || opcion > 5){
            printf("Opción invalida, ingresar una opcion de las dadas\n");
        }
    }
}

void mostrar_tipos_animales(tipopac_t **vector_tipos, int *cant_tipos, int *ultimo_tipoID)
{
    int i;
    i = 0;
    if(*cant_tipos == 0){
        printf("No hay tipos de animales registrados\n");
    }
    else {
        printf("Lista de tipos de animales:\n");
        for(i = 0; i < *cant_tipos; i++){
            printf("ID: %d, Nombre: %s\n", (*vector_tipos)[i].tipoID, (*vector_tipos)[i].nombre);
        }
    }
        return;
    }


void agregar_tipo_animal(tipopac_t **vector_tipos, int *cant_tipos, int *ultimo_tipoID){
      tipopac_t *nuevo_animal;
      tipopac_t **vector_aux;

      (*ultimo_tipoID) ++;

      nuevo_animal = (tipopac_t *)malloc(sizeof(tipopac_t));

      if(nuevo_animal == NULL){
        printf("No hay suficiente memoria para agregar al animal\n");
      }
      else {
        nuevo_animal->tipoID = *ultimo_tipoID;
        nuevo_animal->nombre = (char *)malloc(50 * sizeof(char));
        
        printf("Ingrese el nombre del tipo de animal:\n");
        scanf("%s", nuevo_animal->nombre);

        vector_aux = (tipopac_t **)realloc(*vector_tipos, (*cant_tipos + 1) * sizeof(tipopac_t *));
            if(vector_aux == NULL){
                printf("No hay suficiente memoria para agregar al animal\n");
                free(nuevo_animal->nombre);
                free(nuevo_animal);
             }
            else{
                *vector_tipos = *vector_aux;
                vector_tipos[*cant_tipos] = nuevo_animal;
                (*cant_tipos) ++;

                printf("El tipo de animal se agrego\n");

            }
        }
        return;
 }


    void modificar_tipo_animal(tipopac_t **vector_tipos, int *cant_tipos, int *ultimo_tipoID){
        int i;
        int id_buscado;
        int p_encontrada;

        i = 0;
        id_buscado = 0;
        p_encontrada = -1;

        if(*cant_tipos == 0){
            printf("No hay tipos de animales registrados\n");
        }
        else{
            printf("Modificar tipo de animal\n");
            printf("Ingrese el ID del tipo de animal a modificar:\n");
            scanf("%d", &id_buscado);

            for(i = 0; i < *cant_tipos; i++){
                if((*vector_tipos)[i].tipoID == id_buscado){
                    p_encontrada = i;
                }
            }
        if(p_encontrada == -1){
            printf("No se encontro el animal con ID %d\n", id_buscado);
        }
        else{
            printf("Ingrese el nuevo nombre del tipo de animal:\n");
            scanf("%s", (*vector_tipos)[p_encontrada].nombre);
            printf("El animal con ID %d se modifico \n", id_buscado);
        }


        return;
    }

    }

    void borrar_tipo_animal(tipopac_t **vector_tipos, int *cant_tipos, int *ultimo_tipoID){
        int i;
        int id_buscado;
        int p_encontrada;
        tipopac_t **vector_aux;
        int nuevo_tamano;

        i = 0;
        id_buscado = 0;
        p_encontrada = -1;

        if (cant_tipos == 0){
            printf("No hay tipos de animales registrados\n");
        }
        else{
            
            printf("Borrar tipo de animal\n");
            printf("Ingrese el ID del tipo de animal a borrar:\n");
            scanf("%d", &id_buscado);

            for(i = 0; i < *cant_tipos; i++){
                if((*vector_tipos)[i].tipoID == id_buscado){
                    p_encontrada = i;
                }
            }
        if(p_encontrada == -1){
            printf("No se encontro el animal con ID %d\n", id_buscado);
        }
        else{
            free((*vector_tipos)[p_encontrada].nombre);

            for(i = p_encontrada; i < *cant_tipos - 1; i++){
                (*vector_tipos)[i] = (*vector_tipos)[i + 1];
            }

            nuevo_tamano = *cant_tipos - 1;
        

            if(nuevo_tamano == 0){
                free(*vector_tipos);
                *vector_tipos = NULL;
                (*cant_tipos) --;
                printf("El animal con ID %d se borro \n", id_buscado);
            }
            else{
                vector_aux = (tipopac_t **)realloc(*vector_tipos, nuevo_tamano * sizeof(tipopac_t *)); 
            }
            if(vector_aux == NULL){
                printf("No se puedo reducir la memoria\n");
            }
            else{
                *vector_tipos = *vector_aux;
                (*cant_tipos) --;
                printf("El animal con ID %d se borro \n", id_buscado);
            }
        }

        return;
    }
}

    void volver_menu_principal(tipopac_t **vector_tipos, int *cant_tipos, int *ultimo_tipoID){
        printf("Regresando al menu principal\n");
        return;
    }
