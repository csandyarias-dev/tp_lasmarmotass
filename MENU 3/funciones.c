int agregarPaciente(nodo_paciente_t ** primero, int * ultimo_ID_utilizado) {
	
	nodo_paciente_t * nuevo = NULL, * auxp = NULL;
	int estado=ERROR_MEMORIA;
	
	auxp =(nodo_paciente_t *) malloc(sizeof(nodo_paciente_t)); 
	
	if (auxp!=NULL) {
		nuevo = auxp; 
		
		
		printf("Ingrese tipo de paciente: "); // AMPLIAR 
		
		printf("Ingrese nombre del paciente: ");
		
		printf("Ingrese año de nacimiento: ");
		
		printf("Ingrese mes de nacimiento: ");
		
		printf("Ingrese dia de nacimiento: ");
		
		nuevo->paciente.pacID=(*ultimo_ID_utilizado)+1;
		
		if (añadirordenado_p(primero, nuevo)) printf("ERROR AL AÑADIR");
		else printf("añadido con exito");
		}
		return estado;
	}
	
int añadirordenado_c(nodo_paciente_t ** primero, paciente_t cliente){
	
	nodo_paciente_t * nuevo = NULL, * auxp = NULL;
	int estado=ERROR_MEMORIA, i, j;
	
	auxp =(nodo_paciente_t *) malloc(sizeof(nodo_paciente_t)); 
	
	if (auxp!=NULL) {
		nuevo = auxp; 
		
		nuevo->paciente=cliente; 
		
		
		
	
	}
	else estado=ERROR_MEMORIA;
}
