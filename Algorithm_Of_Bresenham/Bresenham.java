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
      // int x1 = Math.abs(r.nextInt()) % w;
      // int y1 = Math.abs(r.nextInt()) % h;
      // int x2 = Math.abs(r.nextInt()) % w;
      // int y2 = Math.abs(r.nextInt()) % h;   

      int valx, valy, rad; // Ubicación y radio de cada circulo  

      for (int i = 0; i <= 1000 ; i++) {

          rad = (int)(Math.random()*100);
          valx = (int)(Math.random()*w);
          valy = (int)(Math.random()*h);

          int x,y,param;
          x = 0;
          y = rad;
          param = 3-2*rad; 

          while(x < y) {
              if(param < 0) {
                  param = param + 4 * x +6;
              }else {
                  param = param + 4* (x-y) +10;
                  y = y-1;
              }
              x++;
              paintPoints(valx, valy, x, y);
          }                   
      } 

  }   

  public static void paintPoints(x1, y1, x2, y2) {
    

  }    
    
      
    public static void main(String[] args) {
        JFrame frame = new JFrame("Bresenham");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        JOptionPane.showInputDialog("");
        Bresenham circle = new Bresenham();
        frame.add(circle);
        frame.setBackground(Color.BLACK);
        frame.setSize(300, 350);
        frame.setLocationRelativeTo(null);
        frame.setVisible(true);      
    }
}
  


