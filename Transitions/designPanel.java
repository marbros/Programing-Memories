/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package housepaint;

import java.awt.event.MouseMotionListener;
import java.awt.event.MouseListener;
import java.awt.event.MouseEvent;
import java.awt.Graphics;
import java.awt.Graphics2D;

import javax.swing.JPanel;
import java.awt.BorderLayout;
import javax.swing.JFileChooser;
import javax.swing.JButton;   
import java.awt.GridLayout;
import javax.swing.JTextField;
import java.awt.Color;
/**
 *
 * @author usuario
 */
public class designPanel extends JPanel implements MouseListener, MouseMotionListener {

    private window window;
    private actionPanel action;
    private int dimX;                 
    private int dimY;                    
    private int midX;                  
    private int midY; 
    
    public designPanel(window window){
	this.window = window; 
	addMouseListener(this);
	addMouseMotionListener(this);    
	dimY = window.getDimY();         
	dimX = window.getDimX();         
	midY = dimY / 2;              
	midX = dimX / 2;    
        this.setBackground(Color.BLACK);
	this.window = window;
	        
    }       
    
    public void points() {
        String text = action.getText();
        
    }

    @Override
    public void mouseClicked(MouseEvent me) {
 
    }

    @Override
    public void mousePressed(MouseEvent me) {
    }

    @Override
    public void mouseReleased(MouseEvent me) {
    }

    @Override
    public void mouseEntered(MouseEvent me) {
    }

    @Override
    public void mouseExited(MouseEvent me) {
    }

    @Override
    public void mouseDragged(MouseEvent me) {
    }

    @Override
    public void mouseMoved(MouseEvent me) {
    }
    
    // Method that paints into the panel
    @Override
    public void paintComponent(Graphics g){
	Graphics2D g2d = (Graphics2D) g;
	super.paintComponent(g2d); // Clears the screen
        
        g2d.setColor(Color.BLUE);
        for (int i=0; i<100; i++) {
          int x1 = 200;
          int y1 = 100;
          int x2 = 100;
          int y2 = 200;
          // Así se pinta un punto
          g2d.drawLine(x1, y1, x1, y1);
          g2d.drawLine(100, 100, 200, 100);   
          g2d.drawLine(200, 100, 200, 200);
          g2d.drawLine(200, 200, 100, 200);
          g2d.drawLine(100, 200, 100, 100);
          
          g2d.drawLine(100, 200, 150, 250); 
          g2d.drawLine(200, 200, 150, 250);           
        }
    }       
}
