import java.util.Scanner;
import java.util.ArrayList;
import java.util.List;
import java.util.Arrays;

public class AFD{

	String [] alfabeto;
	String [] estados_Q;
	String estado_Inicial = "";
	String [] estados_Aceptacion;
	String [][] tabla_Transiciones;
	
	public void setEstadosQ(){
		Scanner myObj = new Scanner(System.in);
		System.out.println("Ingresa el nombre de cada estado separado por espacios. Por ejemplo: q0 q1 q2 ...");
		String estados = myObj.nextLine();
		estados_Q = estados.split(" ");
	}
	
	public void setEstadoInicial(){
	    Scanner myObj = new Scanner(System.in);
	    String estado_I;
	    
	    do{
	        System.out.println("Indica cual es el estado inicial");
		    estado_I = myObj.nextLine();
	    }while(!(Arrays.asList(estados_Q).contains(estado_I)));  //de detiene hasta que indiquemos un estado que se encuentre en el conjunto de estados Q
	}
	
	public void setAlfabeto(){
	    Scanner myObj = new Scanner(System.in);
		System.out.println("Ingresa las letras del alfabeto del automata, separadas por espacios.");
		String letras = myObj.nextLine();
		alfabeto = letras.split(" ");
	}
	
	public void setTablaTransiciones(){
	    int i, j;
	    Scanner myObj = new Scanner(System.in);
	    String estado;
	    
	    for (i=0; i < estados_Q.length; i++){
	        for (j=0; j < alfabeto.length; j++){
	            System.out.println("Del estado " + estados_Q[i] + " con el caracter de entrada '" + alfabeto[j] + "', va hacia el estado: ");
	            estado = myObj.nextLine();
	            tabla_Transiciones[i][j] = estado;
	        }
	    }
	}


	public static void main(String[] args) {
	    AFD obj1 = new AFD();
	    obj1.setEstadosQ();
	    obj1.setEstadoInicial();
	    obj1.setAlfabeto();
	    obj1.setTablaTransiciones();
  	}
}
