/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */ 

package beziersurface;

import javax.swing.JFrame;

/**
 *
 * @author usuario
 */
public class BezierSurface extends JFrame{
    
 
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        window view = new window(); 
        
        // Al cerrar el frame, termina la ejecución de este programa        
	view.setDefaultCloseOperation(view.EXIT_ON_CLOSE);
        // Poner el frame en el centro de la pantalla
	view.setLocationRelativeTo(null);
	view.setVisible(true); 
    }
}
