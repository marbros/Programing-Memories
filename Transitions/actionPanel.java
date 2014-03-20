/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package housepaint;

import java.awt.Graphics;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.GridLayout;
import javax.swing.JPanel;
import javax.swing.JButton;   
import javax.swing.JTextField;   
import java.awt.Color;
import javax.swing.JFileChooser;

/**
 *
 * @author usuario
 */
public class actionPanel extends JPanel implements ActionListener{

    private final int VALUES = 1;
    private window window;
    private designPanel design;
    private JButton loadV;
    private JTextField values;  
    private String img = "1";  
    private String status;
    private String path;    
    punto2D[] points;
    int[][] lines;
    Graphics g;
    
    public actionPanel(window window){
	this.window = window; 
        this.setBackground(Color.GRAY);
	this.setLayout(new GridLayout(3, 3)); // 2 rows, 3 columns
        design = new designPanel(window);
	// Create the buttons
        loadV = new JButton("Load values");
        loadV.setActionCommand(img);
	loadV.addActionListener(this);
        this.add(loadV);        
        values = new JTextField("");
 	values.addActionListener(this);
        this.add(values);         
    }       

    public void lines(String[] line, int numPoints) {
        String[] lineAux = line;
        int numLines = Integer.parseInt(line[numPoints + 1]);
        lines = new int [numLines][2];
        int j=0;
        int i = numLines+1;
        for(i = numLines+1; i < line.length - (numLines-1); i++) {
            String[] auxP = lineAux[i].split(",");
            int pOne = Integer.parseInt(auxP[0]);
            int pTwo = Integer.parseInt(auxP[1]);
            lines[j][0] = pOne;
            lines[j][1] = pTwo;
            j++;
        }
        transforms(line, i);
    }
    
    public int[][] getLines() {
        return lines;
    }
    
    public void load () {
        JFileChooser fc = new JFileChooser();
        Text t = new Text();
        int option = fc.showOpenDialog(this);
        if(option == JFileChooser.APPROVE_OPTION) {
            path = fc.getSelectedFile().getPath();
            path = t.read(path);
            points(path);
            values.setText(path.replace(',',' '));//path.replace(',',' ')
        }
    }   
    
    public void points(String p) {
        String[] point;
        point = p.split("/");
        int numPoints = Integer.parseInt(point[0]);
        points = new punto2D[numPoints];
        for(int i = 0; i < numPoints; ++i) {
           points[i] = new punto2D(0,0,1);
           String[] auxP = point[i+1].split(",");
           points[i].setX(Double.parseDouble(auxP[0]));
           points[i].setY(Double.parseDouble(auxP[1]));          
        }
        
        lines(point, numPoints);
    }
    
    public void transforms(String[] transforms, int numTransforms) {
        int numTransfor = Integer.parseInt(transforms[numTransforms+1]);
        String value1;
        String value2 = "";
        
        for (int i = numTransforms+2; i < transforms.length; i++) {
           String[] auxTrans = transforms[i].split(",");
           String actionT = auxTrans[0];        
           value1= auxTrans[1]; 
           if(auxTrans.length > 2) {
               value2= auxTrans[2];
           }
//           transforms[i]= aplicate(action, value1, value2);
        }
    }
    
    public punto2D[] getPoints() {
        return points;
    }
//    
//    public String getText () {
//        return path;
//    }
    
    @Override
    public void actionPerformed(ActionEvent ae) {
	int command = Integer.parseInt(ae.getActionCommand());
	switch (command){
	case VALUES:
		load();
                design.paintComponent(g);
		break;
	default:
		break;
	}  
        
    } 
    
}
