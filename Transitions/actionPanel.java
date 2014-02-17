/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package housepaint;

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

    private final int IMG = 1;
    private window window;
    private designPanel design;
    private JButton loadImg;
    private JTextField points; 
    private String img = "1";  
    private String status;
    private String path;    
    
    public actionPanel(window window){
	this.window = window; 
        this.setBackground(Color.GRAY);
	this.window = window;
	this.setLayout(new GridLayout(2, 3)); // 1 rows, 3 columns
	// Create the buttons
        loadImg = new JButton("Load Points");
        loadImg.setActionCommand(img);
	loadImg.addActionListener(this);
        this.add(loadImg);
        
        points = new JTextField("coordinates...");
        points.setEditable(false);
        this.add(points);
    }       

    public void load (String type) {
        JFileChooser fc = new JFileChooser();
        Text t = new Text();
        int option = fc.showOpenDialog(this);
        if(option == JFileChooser.APPROVE_OPTION) {
            path = fc.getSelectedFile().getPath();
            path = t.read(path, type);
            int cantP = Integer.parseInt(path.substring(0, 1));
            
            while(cantP > 0) {
                int index = path.indexOf("\n");
                
                cantP--;
            }
            switch(type){
                case "Text":
                    points.setText(path);
                    break;
//                  txaText.setText(path);    
//                  txaKeys.setText(path.replace('~', '\n'));                
            }            
            
        }
    }   
    
    public String getText () {
        return path;
    }
    
    @Override
    public void actionPerformed(ActionEvent ae) {
	int command = Integer.parseInt(ae.getActionCommand());
	switch (command){
	case IMG:
		load("Text");
		break;
	default:
		break;
	}        
    } 
    
}
