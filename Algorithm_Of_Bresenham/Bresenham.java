package bresenham;

/**
 * @author Mario
 */

import javax.swing.JFrame;
import javax.swing.JOptionPane;
import javax.swing.JPanel;

public class Bresenham extends JPanel {

    public static JPanel panel ;    

  public static void Bresenham(x1, y1, x2, y2) {
    
    int dx =  x1 - x2; 
    int dy =  y1 - y2;
    int p = 2*dy -dx;

    if( dx > dy ) {
      const1 = 2*dy;
      const2 = 2 * (dy -dx);
    }
  }    
    
      
    public static void main(String[] args) {
        JFrame frame = new JFrame("Bresenham");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        JOptionPane.showInputDialog("");
        frame.setVisible(true);        
    }
}
  


