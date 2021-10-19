#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "PILH.h"
#define TAM 100

using namespace std;

class ExpresionRegular{	
	public:
		string expresionRegular;
		
		void setExpresionRegular(string r){
	    	expresionRegular = r;
	  	}

	  	string getExpresionRegular(){
	    	return expresionRegular;
	  	}
};

class Iterador{

	public:
		
		bool precedencia(char r,char t){

			if(t=='*'&&(r=='*'||r=='.'||r=='|')){
				return true;
			}
			else if(t=='*'&&r=='('){
				return false;
			}
			else if(t=='.'&&(r=='.'||r=='|')){
				return true;
			}
			else if(t=='.'&&(r=='*'||r=='(')){
				return false;
			}
			else if(t=='|'&&r=='|'){
				return true;
			}
			else if(t=='|'&&(r=='*'||r=='.'||r=='(')){
				return false;
			}
			
			else if(t=='('&&(r=='*'||r=='.'||r=='|'||r=='(')){
				return false;
			}
		}
		
		string infijaA_postfija(string cadenaInfija){

			int largo=0,x,z=0,operandos=0,operadores=0;
			char cadenaPostfija[TAM];
			bool val=1;
			PILA A;
			crearPila(&A);
			largo = cadenaInfija.length();

			for(x=0;x<largo;x++){

				if(cadenaInfija[x]=='*'||cadenaInfija[x]=='.'||cadenaInfija[x]=='|'||cadenaInfija[x]=='('){ //si encuentra operadores
					do{
						if(!pilaVacia(A)) 
							val=precedencia(cadenaInfija[x],mostrarCima(A)); //comparar la precedencia de dos signos
						else if(pilaVacia(A)) 
							val=false;

						if(val==true){
							cadenaPostfija[z]=quitarPila(&A);
							z++;
						}
					}while(val==true);
					insertarPila(&A,cadenaInfija[x]);
				}

				else if(cadenaInfija[x]!='*'&&cadenaInfija[x]!='.'&&cadenaInfija[x]!='|'&&cadenaInfija[x]!='('&&cadenaInfija[x]!=')'){ // si encuentra operandos
					cadenaPostfija[z]=cadenaInfija[x]; 
					z++;
					//operandos++;
				}

				else if(cadenaInfija[x]==')'){
					while(mostrarCima(A)!='('){ //saca los signos que encuentre en la pila antes del parentesis que abre
						cadenaPostfija[z]=quitarPila(&A);
						z++;				
					}
					quitarPila(&A); //saca de la pila al parentesis que abre 
				}		
			}

			if(!pilaVacia(A)){ //si al final nos quedaron elementos en la pila
				while(!pilaVacia(A)){
					cadenaPostfija[z]=quitarPila(&A);
					z++;
				}	
			}
			cadenaPostfija[z] = '\0';
			return (string)cadenaPostfija;
		}
};
 
int main () {
	ExpresionRegular er;
	Iterador x;
	string postfija;
	
	cout << "Cual es la expresion regular: ";
	cin >> er.expresionRegular;

  	//cout << "La expresion es: " << er.getExpresionRegular() << "\n";
	postfija = x.infijaA_postfija(er.getExpresionRegular());
	cout << "La expresion en postfija es: " << postfija;

   	return 0;
}
