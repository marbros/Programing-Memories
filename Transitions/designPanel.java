/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package housepaint;

import java.awt.BasicStroke;
import java.awt.Color;
import java.awt.Graphics;
import java.awt.Graphics2D;
import javax.swing.JPanel;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.awt.event.MouseMotionListener;
import java.awt.image.BufferedImage;

import java.util.ArrayList;
/**
 *
 * @author usuario
 */
public class designPanel extends JPanel implements MouseListener, MouseMotionListener {
    
    private BufferedImage preImage;    // re-drawing all shapes
    private Graphics2D preImageG2D;    
    private ArrayList<punto2D> figure;  // List of Points in screen;    
    private window window;
    private String status;
    private actionPanel action;
    private int dimX;                 
    private int dimY;                    
    private int midX;                  
    private int midY; 
    private int cursorX;                  
    private int cursorY;                      
    
    public designPanel(window window){
	this.window = window; 
//        action = new actionPanel(window);
	addMouseListener(this);
	addMouseMotionListener(this);    
	dimY = window.getDimY();         
	dimX = window.getDimX();         
	midY = dimY / 2;              
	midX = dimX / 2;   
        figure = new ArrayList<punto2D>();
        this.setBackground(Color.BLACK);
    }       
 
    // Reset the currently rendered image
    private void resetCurrentImage(){
	preImage = null;
	preImageG2D = null;
    }       
    
    public void drawFigure(Graphics2D g2d){
        if(action.getLines() != null) {
            int lines [][] = action.getLines();
            punto2D points [] = action.getPoints();
            for(int i=0; i < lines[0].length; i++){
               int p1 = lines[i][0];
               int p2 = lines[i][1];
               double[] Onep = points[p1].getPoint();
               double[] Twop = points[p2].getPoint();
               g2d.drawLine(mapeoX(Onep[0]), mapeoY(Twop[0]), mapeoX(Onep[0]), mapeoY(Twop[1]));
            }
        }
    }    
    
//    public void points() {
//        String text = action.getText();
//    }

    public int mapeoX(double x){
        return (int)x;
    }       
    
    public int mapeoY(double y){
        return (int)y*(-1);
    }
    
    @Override
    public void mouseClicked(MouseEvent me) {
	cursorX = me.getX() - midX;
	cursorY = me.getY() - midY; 
        resetCurrentImage();
        createPoint();
	paintImmediately(0, 0, dimX, dimY);        
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
	cursorX = cursorY = 31313;
	paintImmediately(0, 0, dimX, dimY);        
    }

    @Override
    public void mouseDragged(MouseEvent me) {
    }

    @Override
    public void mouseMoved(MouseEvent me) {
	cursorX = me.getX() - midX;
	cursorY = me.getY() - midY;
	paintImmediately(0, 0, dimX, dimY);        
    }
 
    private void cartesianPlane(Graphics2D g2d){
        g2d.setStroke(new BasicStroke(5));
	g2d.setColor(Color.BLUE); 
        g2d.drawLine(midX, 0, midX, dimY); //vertical line        
        g2d.drawLine(0, midY, dimX, midY); //horizontal line        
    }    
    
    private void createPoint() {
        punto2D p = new punto2D(cursorX, -cursorY, 1);
        figure.add(p);
    }
    
    private void paintCursor(Graphics2D g2d){
	g2d.setColor(Color.GRAY);
	String pos = cursorX + ", " + cursorY*-1;
	int mx = cursorX + midX;
	int my = cursorY + midY;
        // x, y, w, h, arcw, arch
	g2d.fillRoundRect(mx, my - 15, pos.length()*7, 20, 7, 7); //Paint Rect of Coor X, Y
	g2d.setColor(Color.WHITE);
	g2d.drawString(pos, mx + 5, my);
    }   
    
    private void paintLines(Graphics2D g2d) {
        g2d.setColor(Color.GREEN);
        for(int i = 0; i < figure.size() -1; ++i){
            punto2D p1 = figure.get(i);
            punto2D p2 = figure.get(i+1);
            int x1 = (int)p1.getX();
            int y1 = (int)p1.getY();
            int x2 = (int)p2.getX();
            int y2 = (int)p2.getY();
            g2d.drawLine(x1 + midX, -y1 + midY, x2 + midX, -y2 + midY);
            preImageG2D.setColor(g2d.getColor());  
            preImageG2D.drawLine(x1 + midX, -y1 + midY, x2 + midX, -y2 + midY);
        }        
    }
    
    private void paintPoints(Graphics2D g2d) {
        g2d.setColor(Color.CYAN);
        for(int i = 0; i < figure.size(); ++i){
            punto2D point = figure.get(i);
            int x = (int)point.getX();
            int y = (int)point.getY();
            g2d.fillOval(x + midX, -y + midY, 8, 8);
            preImageG2D.setColor(g2d.getColor());
            preImageG2D.fillOval(x + midX, -y + midY, 8, 8);
        }   
    }    
    
    // Method that paints into the panel
    @Override
    public void paintComponent(Graphics g){
	Graphics2D g2d = (Graphics2D) g;
	super.paintComponent(g2d); // Clears the screen 

        cartesianPlane(g2d);         
        if (preImage == null){
            preImage = new BufferedImage(dimX, dimY, BufferedImage.TYPE_INT_ARGB);
            preImageG2D = preImage.createGraphics();           
            paintPoints(g2d);
            if(figure.size() >= 2) {
                paintLines(g2d);
            }
	}else{
            g2d.drawImage(preImage, null, 0, 0);
	}        

        paintCursor(g2d);
//        drawFigure(g2d);
//        for (int i=0; i<100; i++) {
//          int x1 = 200;
//          int y1 = 100;
//          int x2 = 100;
//          int y2 = 200;
//          // Así se pinta un punto
//          g2d.drawLine(x1, y1, x1, y1);
//          g2d.drawLine(100, 100, 200, 100);   
//          g2d.drawLine(200, 100, 200, 200);
//          g2d.drawLine(200, 200, 100, 200);
//          g2d.drawLine(100, 200, 100, 100);
//          
//          g2d.drawLine(100, 200, 150, 250); 
//          g2d.drawLine(200, 200, 150, 250);           
//        }
    }       
}
