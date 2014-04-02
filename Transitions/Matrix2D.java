/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package housepaint;

import java.awt.Dimension;

/**
 *
 * @author usuario
 */
public class Matrix2D {

    //operations

    public void rotate(double angle) {
        angle *= Math.PI / 180; // to Radians
        double cosen = (double) Math.cos(angle);
        double sin = (double) Math.sin(angle);
        double matriz[][] = {{ cosen, -sin, 0 }, 
                            { sin,  cos, 0 }, 
                            { 0,    0,   1 }}; 
        //Create new matriz...
    }

    public void translate(double transX, double transY) {
        double matriz[][] = {{ 1, 0, transX }, 
                             { 0, 1, transY }, 
                             { 0, 0,      1 }};

    }

    public void scale(double sclX, double sclY) {
        double matrix[][] = {{ sclX,    0, 0 }, 
                             {    0, sclY, 0 }, 
                             {    0,    0, 1 }};
    }
       
}
