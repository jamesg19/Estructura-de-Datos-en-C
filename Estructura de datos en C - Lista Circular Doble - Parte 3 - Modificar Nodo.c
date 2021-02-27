#include <stdio.h>
#include <conio.h>

typedef struct nodo{
	int dato;
	struct nodo* siguiente;
	struct nodo* atras;
} nodo;

nodo* primero = NULL;
nodo* ultimo = NULL;

void insertarNodo();
void buscarNodo();
void modificarNodo();
void desplegarListaPU();
void desplegarListaUP();

int main(){
	int opcionMenu = 0;
	do{
		printf("\n|-------------------------------------|");
		printf("\n|       � LISTA CIRCULAR DOBLE �      |");
		printf("\n|------------------|------------------|");
		printf("\n| 1. Insertar      | 5. Desplegar P.U |");
		printf("\n| 2. Buscar        | 6. Desplegar U.P |");
		printf("\n| 3. Modificar     | 7. Salir         |");
		printf("\n| 4. Eliminar      |                  |");		
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
				break;
			case 5:
				printf("\n\n DESPLEGAR LISTA DE NODOS DEL PRIMERO AL UTLIMO\n\n");
				desplegarListaPU();
				break;
			case 6:
				printf("\n\n DESPLEGAR LISTA DE NODOS DEL UTLIMO AL PRIMERO\n\n");
				desplegarListaUP();
				break;
			case 7:
				printf("\n\n Programa finalizado...");
				break;
			default:
				printf("\n\n Opcion No Valida \n\n");	
		}
	}while(opcionMenu != 7);
	return 0;
}


// primero = 12    ultimo = 7       nuevo = 7         actual =  6      nodoBuscado = 4     encontrado = 1               7  6 4 12

// lista circular doble   --     7 <- 12 -> <- 5 -> <- 6 -> <- 7 -> 12               12  4  6 7

void insertarNodo(){
	nodo* nuevo = (nodo*) malloc(sizeof(nodo));
	printf(" Ingrese el dato que contendra el nuevo Nodo: ");
	scanf("%d", &nuevo->dato);
	if(primero==NULL){
		primero = nuevo;
		primero->siguiente = primero;
		ultimo = primero;
		primero->atras = ultimo;
	}else{
		ultimo->siguiente = nuevo;
		nuevo->siguiente = primero;
		nuevo->atras = ultimo;
		ultimo = nuevo;
		primero->atras = ultimo;
	}
	printf("\n Nodo Ingresado\n\n");
}

void buscarNodo(){
	nodo* actual = (nodo*) malloc(sizeof(nodo));
	actual = primero;
	int nodoBuscado = 0, encontrado = 0;
	printf(" Ingrese el dato del nodo a Buscar: ");
	scanf("%d", &nodoBuscado);
	if(primero!=NULL){
		do{
			if(actual->dato == nodoBuscado){
				printf("\n Nodo con el dato ( %d ) Encontrado\n\n", nodoBuscado);
				encontrado = 1;
			}
			actual = actual->siguiente;
		}while(actual != primero && encontrado != 1);
		if(encontrado == 0){
			printf("\n Nodo no Encontrado\n\n");
		}
	}else{
		printf("\n La Lista se encuentra vacia\n\n");
	}	
}

void modificarNodo(){
	nodo* actual = (nodo*) malloc(sizeof(nodo));
	actual = primero;
	int nodoBuscado = 0, encontrado = 0;
	printf(" Ingrese el dato del nodo a Buscar para Modificar: ");
	scanf("%d", &nodoBuscado);
	if(primero!=NULL){
		do{
			if(actual->dato == nodoBuscado){
				printf("\n Nodo con el dato ( %d ) Encontrado", nodoBuscado);
				printf("\n Ingrese el nuevo dato para este Nodo: ");
				scanf("%d", &actual->dato);
				printf("\n Nodo Modificado\n\n");
				encontrado = 1;
			}
			actual = actual->siguiente;
		}while(actual != primero && encontrado != 1);
		if(encontrado == 0){
			printf("\n Nodo no Encontrado\n\n");
		}
	}else{
		printf("\n La Lista se encuentra vacia\n\n");
	}		
}

void desplegarListaPU(){
	nodo* actual = (nodo*) malloc(sizeof(nodo));
	actual = primero;
	if(primero!=NULL){
		do{
			printf("\n %d", actual->dato);
			actual = actual->siguiente;
		}while(actual != primero);
	}else{
		printf("\n La Lista se encuentra vacia\n\n");
	}
}

void desplegarListaUP(){
	nodo* actual = (nodo*) malloc(sizeof(nodo));
	actual = ultimo;
	if(primero!=NULL){
		do{
			printf("\n %d", actual->dato);
			actual = actual->atras;
		}while(actual != ultimo);
	}else{
		printf("\n La Lista se encuentra vacia\n\n");
	}
}




/*

*/

































