package bresenham;

/**
 * @author Mario
 */

import java.awt.Color;
import java.awt.Dimension;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.Insets;

import javax.swing.JPanel;
import javax.swing.JFrame;

import java.util.Random; 

public class Bresenham extends JPanel {

  public static JPanel panel ;    

    @Override
  public void paintComponent(Graphics g) {
      super.paintComponent(g);

      Graphics2D g2d = (Graphics2D) g;

      g2d.setColor(Color.BLUE);

      Dimension size = getSize();
      Insets insets = getInsets();

      int w =  size.width - insets.left - insets.right;
      int h =  size.height - insets.top - insets.bottom;

      g2d.setColor(Color.BLUE);
      int x1 = Math.abs(r.nextInt()) % w;
      int y1 = Math.abs(r.nextInt()) % h;
      int x2 = Math.abs(r.nextInt()) % w;
      int y2 = Math.abs(r.nextInt()) % h;     

      int rad = r.nextInt();
      int x = 0;
      int y = rad;

      for (int i = x; i < y; i++) {
          g2d.drawLine(y, x, y, x);
          g2d.drawLine(x, y, x, y);
          g2d.drawLine(x, -y, x,-y);
          g2d.drawLine(y, -x, y, -x);
          g2d.drawLine(-y, -x,-y, -x);
          g2d.drawLine(-x, -y, -x, -y);
          g2d.drawLine(-x, y, -x, y);
          g2d.drawLine(-y, x, -y, x);
      } 

  }   

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
        frame.add(new Bresenham());
        frame.setSize(300, 350);
        frame.setLocationRelativeTo(null);
        frame.setVisible(true);      
    }
}
  


