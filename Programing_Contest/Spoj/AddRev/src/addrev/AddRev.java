package addrev;

/**
 *
 * @author BBW Latino
 */

import java.util.Scanner;

public class AddRev {
    
    static public long invertir(long num1){

        long aux1;
        long aux2 = -1;
        String aux3 = "";
        
        while(aux2 != 0){
            aux1 = num1 % 10;
            aux2 = num1 / 10;
            num1 = aux2;
            aux3 += Long.toString(aux1);
        }
        num1 = Long.parseLong(aux3);
        return num1;
    }

    static public void Ejercicio42() {
        
        Scanner sc = new Scanner(System.in);
        System.out.println("Casos");
        int cases = sc.nextInt();
        long num1;
        long num2;
        long inver;
        for(int i = 0; i < cases; i++){
            num1 = sc.nextLong();
            num2 = sc.nextLong();

            inver = invertir(invertir(num1) + invertir(num2));
            System.out.println(inver);
        }
    }

    public static void main(String[] args) {    
        Ejercicio42();
    }
}
