

int cargar_pacientes_archivo(nodo_paciente_t ** lista, int *ultimoPacID) {
    FILE *fp;
    paciente_t pacAux;
    int cant_pacientes=0;

    // Abrimos el archivo en modo lectura binaria 
    fp = fopen("pacientes.dat", "rb");

    if (fp != NULL) {
        fread(ultimoPacID, sizeof(int), 1, fp);
        
        while (fread(&pacAux, sizeof(paciente_t), 1, fp) == 1) { 
            añadir_ordenado_p(lista, pacAux);
            cant_pacientes++; 
        }
        
        fclose(fp);
    } 
    return cant_pacientes;
}

int cargar_responsables_archivo(nodo_responsable_t ** lista, int *ultimoResponID) {
    FILE *fp;
	responsable_t respon_aux;
    int cant_responsables=0;

    // Abrimos el archivo en modo lectura binaria 
    fp = fopen("responsables.dat", "rb");

    if (fp != NULL) {
        fread(ultimoResponID, sizeof(int), 1, fp);
        
        while (fread(&respon_aux, sizeof(responsable_t), 1, fp) == 1) { 
          //  añadir_ordenado_r(lista, pacAux); AÑADIR FUNCION LIZ
            cant_responsables++; 
        }
        
        fclose(fp);
    } 
    return cant_responsables;
}

int cargar_turnos_archivo(nodo_turnos_t ** lista) {
    FILE *fp;
    turnos_t turnos_aux;
    int cant_turnos=0;

    // Abrimos el archivo en modo lectura binaria 
    fp = fopen("turnos.dat", "rb");

    if (fp != NULL) {
        
        while (fread(&turnos_aux, sizeof(turnos_t), 1, fp) == 1) { 
           aniadir_ordenado_t(lista, turnos_aux); 
           cant_turnos++; 
        }
        
        fclose(fp);
    } 
    return cant_turnos;
}

void agregar_turno(nodo_turnos_t ** turnos) {
	int id;
	turnos_t nuevo; 
	nfecha_t fecha;
	nhora_t hora;
	paciente_t ** paciente; 
	int dia, mes año, hora, min;
	
	printf("Ingrese el ID del paciente:");
	scanf("%d", &id);
	
	// AGREGAR FUNCION VICKY QUE VERIFICA QUE EXISTA EL PACIENTE Y DEVUELVE EL PUNTERO 
	// estado=ConsultarPacienteID(* lista_pacientes, id, paciente);
	printf("Paciente seleccionado:");
	mostrar_paciente(**paciente);
	
	nuevo.pacID=ID;
	nuevo.responID=(*paciente)->responID;
	
	printf("Ingrese la fecha siguiendo el siguiente formato: DIA-MES-AÑO");
	sscanf("%d-%d-%d", &dia, &mes, &año);
	nuevo.fecha.bits1.dia = dia;
    nuevo.fecha.bits1.mes = mes;
    nuevo.fecha.bits1.anio = anio;    
	
	printf("Ingrese la hora formato 24hs de la siguiente forma HH:MM");
	sscanf("%d:%d", &hora, &min);
	nuevo.hora.bits.hora = hora;
    nuevo.hora.bits.min = min;
    
    if (aniadir_ordenado_t(turnos, nuevo) == OK) estado = OK;
    else estado = ERROR;
    
	return estado;
	
	}
	
int comparar_fecha_hora(turnos_t a, turnos_t b) {
    int resultado = 0;

    if (a.fecha.bits1.anio != b.fecha.bits1.anio) {
        resultado = a.fecha.bits1.anio - b.fecha.bits1.anio;
    } else if (a.fecha.bits1.mes != b.fecha.bits1.mes) {
        resultado = a.fecha.bits1.mes - b.fecha.bits1.mes;
    } else if (a.fecha.bits1.dia != b.fecha.bits1.dia) {
        resultado = a.fecha.bits1.dia - b.fecha.bits1.dia;
    } else if (a.hora.bits.hora != b.hora.bits.hora) {
        resultado = a.hora.bits.hora - b.hora.bits.hora;
    } else {
        resultado = a.hora.bits.min - b.hora.bits.min;
    }

    return resultado;
}

int aniadir_ordenado_t(nodo_turnos_t **lista, turnos_t nuevo) {
    nodo_turnos_t *agregando = NULL, *actual = NULL, *anterior = NULL;
    int estado = ERROR_MEMORIA;
    int lugar = 0;

    agregando = (nodo_turnos_t *) malloc(sizeof(nodo_turnos_t));

    if (agregando != NULL) {
        agregando->turnos = nuevo;
        agregando->sig = NULL;
        actual = *lista;

        if (*lista != NULL) {
            while ((actual != NULL) && (lugar == 0)) {
                if (comparar_fecha_hora(nuevo, actual->turnos) >= 0) {
                    anterior = actual;
                    actual = actual->sig;
                } 
                else lugar = 1; // actualizo el flag
                
            }

            if (anterior == NULL) {
                agregando->sig = *lista;
                *lista = agregando;
            } else {
            
                agregando->sig = actual;
                anterior->sig = agregando;
            }
        } 
        else *lista = agregando;
        estado = OK;
        }
        
    }

    return estado;
}
		
		
	}
	
void alarma_handler(int nsig) {
	
	flag_alarma=1;
	signal(SIGALRM, alarma_handler); 
		
	}
	
int act_archivos(nodo_paciente_t ** pac_primero, nodo_responsable ** resp_primero, nodo_turnos_t ** turnos_primero){
	// MUTEX ARCHIVOS LOCK
	act_pacientes_archivos(pac_primero);
	act_resp_archivos(resp_primero);
	act_turnos_archivos(turnos_primero);
	// MUTEX ARCHIVOS UNLOCK
}

int act_pacientes_archivos(nodo_paciente_t ** primero) {
    FILE *fp;
    nodo_paciente_t * actual;
    int id=0, estado=0;
    
    fp = fopen("dat/pacientes.dat", "wb+");  // DEFINE NOMBRE ARCHIVO
    
    if (fp != NULL) {
        if (*primero != NULL) {
            actual = *primero; 
            while (actual != NULL) {
                if (id < actual->paciente.pacID) id = actual->paciente.pacID;
                actual = actual->sig;                
            }
            fwrite(&id, sizeof(int), 1, fp); 
            actual = *primero; 
            while (actual != NULL) {
                fwrite(&(actual->paciente), sizeof(paciente_t), 1, fp); 
                actual = actual->sig;
                estado++;
            }
        }
        else estado = ERROR;
        fclose(fp);
    }
    return estado;
}

int act_resp_archivos(nodo_responsable_t ** primero) {
    FILE *fp;
    nodo_responsable_t * actual;
    int id=0, estado=0;
    
    fp = fopen("dat/responsables.dat", "wb+"); 
    
    if (fp != NULL) {
        if (*primero != NULL) {
            actual = *primero; 
            while (actual != NULL) {
                if (id < actual->responsable.responID) id = actual->responsable.responID;
                actual = actual->sig;                
            }
            fwrite(&id, sizeof(int), 1, fp); 
            actual = *primero; 
            while (actual != NULL) {
                fwrite(&(actual->responsable), sizeof(responsable_t), 1, fp); 
                actual = actual->sig;
                estado++;
            }
        }
        else estado = ERROR;
        fclose(fp);
    }
    return estado;
}
    
int act_turnos_archivos(nodo_turnos_t ** primero) {
    FILE *fp;
    nodo_turnos_t * actual;
    int estado = 0;
    
    fp = fopen("dat/turnos.dat", "wb+"); 
    
    if (fp != NULL) {
        if (*primero != NULL) {
            actual = *primero; 
            while (actual != NULL) {
                fwrite(&(actual->turnos), sizeof(turnos_t), 1, fp); 
                actual = actual->sig;
                estado++;
            }
        }
        else estado = ERROR;
        fclose(fp);
    }
    return estado;
}
