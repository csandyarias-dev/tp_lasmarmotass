

void cargar_pacientes_archivo(nodo_paciente_t ** lista, int *ultimoPacID) {
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

void cargar_responsables_archivo(nodo_responsable_t ** lista) {
    FILE *fp;
	responsable_t respon_aux;
    int cant_responsables=0;

    // Abrimos el archivo en modo lectura binaria 
    fp = fopen("responsables.dat", "rb");

    if (fp != NsULL) {
        // fread(ultimoPacID, sizeof(int), 1, fp);
        
        while (fread(&respon_aux, sizeof(responsable_t), 1, fp) == 1) { 
          //  añadir_ordenado_r(lista, pacAux); AÑADIR FUNCION LIZ
            cant_responsables++; 
        }
        
        fclose(fp);
    } 
    return cant_responsables;
}

void cargar_turnos_archivo(nodo_turnos_t ** lista) {
    FILE *fp;
    turnos_t turnos_aux;
    int cant_turnos=0;

    // Abrimos el archivo en modo lectura binaria 
    fp = fopen("turnos.dat", "rb");

    if (fp != NULL) {
        // fread(ultimoPacID, sizeof(int), 1, fp);
        
        while (fread(&turnos_aux, sizeof(turnos_t), 1, fp) == 1) { 
          //  añadir_ordenado_t(lista, pacAux); AÑADIR FUNCION AGREGAR TURNOS
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
	
	printf("Ingrese el ID del paciente:");
	scanf("%d", &id);
	
	// AGREGAR FUNCION VICKY QUE VERIFICA QUE EXISTA EL PACIENTE Y DEVUELVE EL PUNTERO 
	// estado=ConsultarPacienteID(* lista_pacientes, id, paciente);
	printf("Paciente seleccionado:");
	mostrar_paciente(**paciente);
	
	nuevo.pacID=ID;
	nuevo.responID=(*paciente)->responID;
	
	printf("Ingrese la fecha siguiendo el siguiente formato: DIA-MES-AÑO");
	sscanf("%d-%d-%d", &(nuevo.fecha.bits1.dia), &(nuevo.fecha.bits1.mes), &(nuevo.fecha.bits1.año));
	
	printf("Ingrese la hora formato 24hs de la siguiente forma HH:MM");
	sscanf("%d:%d", &(nuevo.hora.bits.hora), &(nuevo.hora.bits.min));
	
	añadir_ordenado_t(turnos, nuevo);
	
	}
	
int añadir_ordenado_t(nodo_turnos_t ** lista, turnos_t nuevo){
	nodo_turnos_t * agregando = NULL, *actual=NULL, * anterior= NULL; 
	int estado=ERROR_MEMORIA;
	
	agregando = (nodo_turnos_t *) malloc(sizeof(nodo_turnos_t));
	
	if (nuevo!=NULL){
		agregando->turnos=nuevo; 
		actual=*lista; 
		if (*lista != NULL){
			while (actual!=NULL)&&(lugar==0){
				if (nuevo.fecha.bits1.anio>=actual.fecha.bits1.anio) {
					if (nuevo.fecha.bits1.anio>=actual.fecha.bits1)
				}
				
				
			}
			
		}
		else *lista = agregando; 
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

act_pacientes_archivos(nodo_paciente_t ** primero){
	
	nodo_paciente_t * actual, * siguiente;
	int id=0, estado=0;
	
	fp = fopen("pacientes.dat", "wb+"); 
	
	if (fp!=NULL){
		
		if (primero!=NULL) {
			actual=*primero; 
			while(actual->sig!=NULL)
			{
				if (id<actual->paciente.pacID) id=actual->paciente.pacID;
				actual=actual->sig;				
			}
			fwrite(&id, sizeof(int), 1, fp); 
			actual=*primero; 
			while(actual->sig!=NULL) {
				fwrite(actual, sizeof(nodo_paciente_t), 1, fp); 
				actual=actual->sig;
				estado++;
				}
			fclose(fp);
		}
		else estado=-1;
	}
	return estado;
}

act_resp_archivos(nodo_responsable_t ** primero){
	
	nodo_paciente_t * actual, * siguiente;
	int id=0, estado=0;
	
	fp = fopen("responsables.dat", "wb+"); 
	
	if (fp!=NULL){
		
		if (primero!=NULL) {
			actual=*primero; 
			while(actual->sig!=NULL)
			{
				if (id<actual->responsable.responID) id=actual->responsable.responID;
				actual=actual->sig;				
			}
			fwrite(&id, sizeof(int), 1, fp); 
			actual=*primero; 
			while(actual->sig!=NULL) {
				fwrite(actual, sizeof(nodo_responsable_t), 1, fp); 
				actual=actual->sig;
				estado++;
				}
			fclose(fp);
		}
		else estado=-1;
	}
	return estado;
}
	
act_turnos_archivos(nodo_turnos_t ** primero){
	
	nodo_turnos_t * actual;
	int estado = 0;
	
	fp = fopen("turnos.dat", "wb+"); 
	
	if (fp!=NULL){
		
		if (primero!=NULL) {
			actual=*primero; 
			while(actual->sig!=NULL) {
				fwrite(actual, sizeof(nodo_turnos_t), 1, fp); 
				actual=actual->sig;
				estado++;
				}
			fclose(fp);
		}
		else estado=-1;
	}
	return estado;
}
