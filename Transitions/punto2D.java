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
public class punto2D {

    private Dimension punto;
    
    public punto2D(Dimension punto) {
        this.punto = punto;
    }

    public Dimension getPunto() {
        return punto;
    }
    
    public Dimension mapPoint (Dimension punto,int w,int h) {
        int xp,yp;
        xp = punto.width + (w/2);
        yp = (h/2)-punto.height;
        punto.width=xp;
        punto.height=yp;       
        return punto;
    }    

    public void setPunto(Dimension punto,int w, int h) {
        this.punto = mapPoint(punto,w,h);
    }
       
}
