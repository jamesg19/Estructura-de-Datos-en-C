#include <stdio.h>
#include <conio.h>

typedef struct nodo{
	int dato;
	struct nodo* siguiente;
} nodo;

nodo* primero = NULL;
nodo* ultimo = NULL;

void insertarNodo();
void buscarNodo();
void modificarNodo();
void desplegarLista();

int main(){
	int opcionMenu = 0;
	do{
		printf("\n|-------------------------------------|");
		printf("\n|           � LISTA SIMPLE �          |");
		printf("\n|------------------|------------------|");
		printf("\n| 1. Insertar      | 4. Eliminar      |");
		printf("\n| 2. Buscar        | 5. Desplegar     |");
		printf("\n| 3. Modificar     | 6. Salir         |");
		printf("\n|------------------|------------------|");
		printf("\n\n Escoja una Opcion: ");
		scanf("%d", &opcionMenu);
		switch(opcionMenu){
			case 1:
				printf("\n\n INSERTA NODO EN LA LISTA \n\n");
				insertarNodo();
				break;
			case 2:
				printf("\n\n BUSCAR UN NODO EN LA LISTA \n\n");
				buscarNodo();
				break;	
			case 3:
				printf("\n\n MODIFICAR UN NODO DE LA LISTA \n\n");
				modificarNodo();
				break;
			case 4:
				printf("\n\n ELIMINAR UN NODO DE LA LISTA \n\n");
				//eliminarNodo();
				break;
			case 5:
				printf("\n\n DESPLEGAR LISTA DE NODOS \n\n");	
				desplegarLista();
				break;
			case 6:
				printf("\n\n Programa finalizado...");
				break;
			default:
				printf("\n\n Opcion No Valida \n\n");	
		}
	}while(opcionMenu != 6);
	return 0;
}

// primero = 7     ultimo = 9     actual = 2   nodoBuscado = 5   encontrado = 1

/// Lista   7 -> 3 -> 2 ->  9 -> NULL

// 7, 5, 2, 9

void insertarNodo(){
	nodo* nuevo = (nodo*) malloc(sizeof(nodo));
	printf(" Ingrese el dato que contendra el nuevo Nodo: ");
	scanf("%d", &nuevo->dato);
	if(primero==NULL){
		primero = nuevo;
		primero->siguiente = NULL;
		ultimo = nuevo;
	}else{
		ultimo->siguiente = nuevo;
		nuevo->siguiente = NULL;
		ultimo = nuevo;
	}
	printf("\n Nodo ingresado con Exito\n\n");
}

void buscarNodo(){
	nodo* actual = (nodo*) malloc(sizeof(nodo));
	actual = primero;
	int nodoBuscado = 0, encontrado = 0;
	printf(" Ingrese el dato del nodo a Buscar: ");
	scanf("%d", &nodoBuscado);
	if(primero!=NULL){
		while(actual != NULL && encontrado != 1){
			
			if(actual->dato == nodoBuscado){
				printf("\n El nodo con el dato ( %d ) Encontrado\n\n", nodoBuscado);
				encontrado = 1;
			}
				
			actual = actual->siguiente;
		}
		if(encontrado == 0){
			printf("\n Nodo no encontrado\n\n");
		}
	}else{
		printf("\n La lista se encuentra vacia\n\n");
	}
}

void modificarNodo(){
	nodo* actual = (nodo*) malloc(sizeof(nodo));
	actual = primero;
	int nodoBuscado = 0, encontrado = 0;
	printf(" Ingrese el dato del nodo a Buscar para Modificar: ");
	scanf("%d", &nodoBuscado);
	if(primero!=NULL){
		while(actual != NULL && encontrado != 1){
			
			if(actual->dato == nodoBuscado){
				printf("\n El nodo con el dato ( %d ) Encontrado", nodoBuscado);
				printf("\n Ingrese el nuevo dato para este Nodo: ");
				scanf("%d", &actual->dato);
				printf("\n Nodo modificado con exito\n\n");
				encontrado = 1;
			}
				
			actual = actual->siguiente;
		}
		if(encontrado == 0){
			printf("\n Nodo no encontrado\n\n");
		}
	}else{
		printf("\n La lista se encuentra vacia\n\n");
	}
}

void desplegarLista(){
	nodo* actual = (nodo*) malloc(sizeof(nodo));
	actual = primero;
	if(primero!=NULL){
		while(actual != NULL){
			printf("\n %d", actual->dato);
			actual = actual->siguiente;
		}
	}else{
		printf("\n La lista se encuentra vacia\n\n");
	}
}





/*


*/