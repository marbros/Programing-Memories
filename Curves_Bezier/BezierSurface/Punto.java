/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package beziersurface;

/**
 *
 * @author usuario
 */
public class Punto {
    double x, y, z;

    private double point[];
    
    public Punto(double x, double y, double w){
        point = new double[3];
        point[0] = x;
        point[1] = y;
        point[2] = w;
    }
    
    public double[] getPoint() {
        return point;
    }
    
    public void setX(double x) {
        point[0] = x;
    }
    
    public void setY(double y) {
       point[1] = y;
    } 
    
    public double getX() {
        return point[0];
    }
    
    public double getY() {
        return point[1];
    }    
}
