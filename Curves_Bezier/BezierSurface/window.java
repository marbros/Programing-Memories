package beziersurface;

import java.awt.BorderLayout;
import java.awt.Dimension;
import javax.swing.JFrame;

/**
 *
 * @author usuario
 */
public class window extends JFrame{

    private int dimX;
    private int dimY;  
    //private actionPanel PANEL;
    private designPanel DPANEL;
    
    public window() {
	dimX = 500;
	dimY = 400;
	this.setSize(new Dimension(dimX, dimY));        
	this.setResizable(false);   
        this.setTitle("Bezier Surface");
        
        //PANEL = new actionPanel(this);
	DPANEL = new designPanel(this);
        this.setLayout(new BorderLayout());
	//this.add(PANEL, BorderLayout.SOUTH);
	this.add(DPANEL, BorderLayout.CENTER);        
    }   
    
    public int getDimX(){
	return dimX;
    }

    public int getDimY(){
	return dimY;
    }      
}
