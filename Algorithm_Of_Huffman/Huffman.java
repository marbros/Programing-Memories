/**
 * @author Mario Giraldo Restrepo
 * @deprecated Algorithm of Huffman
 * @version 0.0.3
 */

//http://www.eztigma.tk/juegos/binary.php

import java.util.Scanner;
import java.util.TreeMap;
import java.util.PriorityQueue;

public class Huffman {

	static String keys = "";
	static String k = "";

	/**
	 *  Este método se encarga de retirar cada par de elementos de menor
	 *  frecuencia en la cola, y sumar su peso con el fin de crear 
	 *  pequeños subArboles, que seran nuevamente agregados a la cola
	 *  hasta obtener un unico arbol.
	 *
	 *  @param cola   Cola de prioridades ordenada por frecuencia de 
	 *				  cada caracter en el mapa.	 
	 *  @param arbol  Es una instancia de la clase Arbol.
	 */
	private static void createTree(PriorityQueue cola, Arbol arbol) {

		Nodo father = null;
		while(cola.size() > 1) {  
        	Nodo one = (Nodo) cola.poll();
        	//System.out.println(one);
        	Nodo two = (Nodo) cola.poll();
        	//System.out.println(two);
        	Integer onePlusTwo = one.getValue() + two.getValue(); 
        	father = arbol.insertarNodo(onePlusTwo,one,two,father);
        	cola.add(father);    	
		}
		/*while(!cola.isEmpty()) {
			System.out.println(cola.poll());
		}
		*/
		getKeys((Nodo)cola.poll());

		//Imprimir Arbol
		//posOrden((Nodo)cola.poll());	
	}


	/**
	 *  Este método realiza la tarea de contenedor de cada funcíon y  
	 *  método del programa y los ejecuta en un orden establecido.
	 *
	 *  @param T      Es el Texto
	 *  @Retun arbol  Es una instancia de la clase Arbol.
	 */
	private static void huffman (String T, Arbol arbol) {
		createTree(col_priority(cont_Letters(T),arbol),arbol);
		printKeys();
		prinTextCompress(T);
		printTextDescompress(T);
	}

	/**
     *	Metodo de inicio.
	 */
	public static void main(String[] args) {
		Arbol arbol = new Arbol();		
		Scanner Read = new Scanner(System.in);
		String text;
		System.out.print("Ingrese el texto :   ");
		text = Read.nextLine();
		System.out.print("\n");
		String k = "";
		huffman(text,arbol);		
	}
}