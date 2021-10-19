/*
   INSTITUTO POLIT�CNICO NACIONAL
   ESCUELA SUPERIOR DE C�MPUTO
   ESTRUCTURAS DE DATOS
   GRUPO: 1CV7
   ALUMNOS:
        CERON RIVERA IAN
        DELGADO RAMOS GAMALIEL ARMANDO
   PROFESOR: BENJAM�N LUNA BENOSO
  @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
  ARCHIVO DE CABECERA PARA LA DEFINICI�N DEL TAD PILA
  ARCHIVO: IMPLEMENTACI�N DE LAS FUNCIONES FUNDAMENTALES DEL TAD PILA
  FECHA: 12/02/2019
*/
#include <stdio.h>
#include <stdlib.h>
#define TAM 100
//Definici�n del TAD PILA
typedef struct pila
{
	int ListaPila[TAM];
	int cima;
}PILA;
//definici�n del tipo de dato gen�rico
typedef char TipoDato;
//Operaciones fundamentales del TAD PILA
void crearPila(PILA *P);
void insertarPila(PILA *P,TipoDato x);
TipoDato quitarPila(PILA *P);
TipoDato mostrarCima(PILA P);
int pilaVacia(PILA P);
int pilaLlena(PILA P);
void eliminarPila(PILA *P);

//funci�n que inicializa el valor de cima en -1
void crearPila(PILA *P)
{
	P->cima=-1;
}
//funci�n que comprueba si una pila se encuentra vacia
int pilaVacia(PILA P)
{
	return (P.cima==-1?1:0);
}
//funci�n que comprueba si una pila se encuentra llena
int pilaLlena(PILA P)
{
	return (P.cima==TAM-1?1:0);
}
//funci�n para ingresar elementos en una pila
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
//funci�n para sacar los elementos de una pila
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
//funci�n que lee el elemento de la cima de la pila sin eliminarlo
TipoDato mostrarCima(PILA P)
{
	if(pilaVacia(P)==1)
	{
		printf("\nError, pila vacia\n");
		exit(-1);
	}
	return (P.ListaPila[P.cima]);
}
//funci�n que devuelve el valor de cima a -1
void eliminarPila(PILA *P)
{
	P->cima=-1;
}


