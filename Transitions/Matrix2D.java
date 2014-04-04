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

    public static float[][] transpose(float A[][]) {
        int Rows = A.length,
            Columns = A[0].length;

        float[][] resultant = new float[Columns][Rows];
        
        for(int i=0; i < Rows; i++)
            for (int j = 0; j < Columns; j++)
                resultant[j][i] = A[i][j];
        return resultant;
    }

    public static float[][] normalize(float A[][]){
        int Rows = A.length,
            Columns = A[0].length;
        float[][] resultant = new float[Rows-1][Columns];
        for (int i = 0; i < Rows-1; i++){
            for (int j = 0; j < Columns; j++)
                resultant[i][j] = A[i][j] / A[Rows-1][j];
        }
        return resultant;
    }    
      
    public static float dotProduct(Vector x, Vector y){
        float[] a = x.getVector();
        float[] b = y.getVector();
        return (a[0]*b[0]+a[1]*b[1]+a[2]*b[2]);
    }
    
    public static Vector crossProduct(Vector x, Vector y){
        float[] a = x.getVector();
        float[] b = y.getVector();
        
        Vector result = new Vector();
        
        float i = a[1]*b[2] - a[2]*b[1];
        float j = a[2]*b[0] - a[0]*b[2];
        float k = a[0]*b[1] - a[1]*b[0];
        result.setVector(i,j,k);
        
        return result;
    }         
}
