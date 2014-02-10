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

public class Lian_Barsky extends JPanel {

  public static JPanel panel ;    

    @Override
  public void paintComponent(Graphics g) {
      super.paintComponent(g);

      Graphics2D g2d = (Graphics2D) g;

      Dimension size = getSize();
      Insets insets = getInsets();

      int w =  size.width - insets.left - insets.right;
      int h =  size.height - insets.top - insets.bottom;

  }    
    
    public static void main(String[] args) {
        JFrame frame = new JFrame("Algorithm Of Liang Barsky");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        JOptionPane.showInputDialog("");
        Lian_Barsky LiangB = new Lian_Barsky();
        frame.add(LiangB);
        frame.setBackground(Color.BLACK);
        frame.setSize(512, 512);
        frame.setLocationRelativeTo(null);
        frame.setVisible(true);      
    }
}
  


