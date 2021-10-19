/*
   INSTITUTO POLITÉCNICO NACIONAL
   ESCUELA SUPERIOR DE CÓMPUTO
   ESTRUCTURAS DE DATOS
   GRUPO: 1CV7
   ALUMNOS:
        CERON RIVERA IAN
        DELGADO RAMOS GAMALIEL ARMANDO
   PROFESOR: BENJAMÍN LUNA BENOSO
  @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
  ARCHIVO DE CABECERA PARA LA DEFINICIÓN DEL TAD PILA
  ARCHIVO: IMPLEMENTACIÓN DE LAS FUNCIONES FUNDAMENTALES DEL TAD PILA
  FECHA: 12/02/2019
*/
#include <stdio.h>
#include <stdlib.h>
#define TAM 100
//Definición del TAD PILA
typedef struct pila
{
	int ListaPila[TAM];
	int cima;
}PILA;
//definición del tipo de dato genérico
typedef char TipoDato;
//Operaciones fundamentales del TAD PILA
void crearPila(PILA *P);
void insertarPila(PILA *P,TipoDato x);
TipoDato quitarPila(PILA *P);
TipoDato mostrarCima(PILA P);
int pilaVacia(PILA P);
int pilaLlena(PILA P);
void eliminarPila(PILA *P);

//función que inicializa el valor de cima en -1
void crearPila(PILA *P)
{
	P->cima=-1;
}
//función que comprueba si una pila se encuentra vacia
int pilaVacia(PILA P)
{
	return (P.cima==-1?1:0);
}
//función que comprueba si una pila se encuentra llena
int pilaLlena(PILA P)
{
	return (P.cima==TAM-1?1:0);
}
//función para ingresar elementos en una pila
void insertarPila(PILA *P,TipoDato x)
{
	if(pilaLlena(*P)==1)
	{
		printf ("\nError, pila llena\n");
		exit(-1);
	}
	P->cima=P->cima+1;
	P->ListaPila[P->cima]=x;
}
//función para sacar los elementos de una pila
TipoDato quitarPila(PILA *P)
{
	if(pilaVacia(*P)==1)
	{
		printf("\nError, pila vacia\n");
		exit(-1);
	}
	TipoDato aux=P->ListaPila[P->cima];
	P->cima=P->cima-1;
	return aux;
}
//función que lee el elemento de la cima de la pila sin eliminarlo
TipoDato mostrarCima(PILA P)
{
	if(pilaVacia(P)==1)
	{
		printf("\nError, pila vacia\n");
		exit(-1);
	}
	return (P.ListaPila[P.cima]);
}
//función que devuelve el valor de cima a -1
void eliminarPila(PILA *P)
{
	P->cima=-1;
}


