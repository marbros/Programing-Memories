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
     *  Esta función retorna un cola de prioridades ordenada por   
     *  frecuencia de cada caracter en el mapa.
     *
     *  @param map    Es el mapa de caracteres asociado con su frecuencia.
     *  @param arbol  Es una instancia de la clase Arbol
     *  @Retun cola
     */
    private static PriorityQueue col_priority(TreeMap map, Arbol arbol) {
        PriorityQueue<Nodo> cola = new PriorityQueue<Nodo>();   
        Nodo node = null;       
        for (Object key : map.keySet()) {
            int value = (int) map.get(key);
            cola.add(node = new Nodo((String)key,value));
            //equivalente a
            //cola.add(arbol.insertarNodo((String)key,value,node));
        }       
        System.out.println(cola.toString());
        // while(!cola.isEmpty()){
        //     System.out.println(cola.poll());
        // }

        return cola;
    }

	/**
	 *  Esta función retorna un map <k,v> con cada caracter  
	 *  y el número de veces con que este se repite en un texto.
	 *
	 *  @param T    Es el Texto
	 *  @Retun map
	 */
	private static TreeMap cont_Letters(String T) {
		String[] letters = T.split("");
		int len = letters.length;
		TreeMap <String, Integer> map = new TreeMap <String, Integer>();

		for (int i=0; i < len; ++i) {
			String key = letters[i];
			if (letters[i].length() > 0) {
				if(map.get(key) == null) {
					map.put(key, 1);
				}else {
					int value = map.get(key).intValue();
					value++;
					map.put(key,value);
				}
			}
		}
		
		return map;	
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