public class Surface {

    private Point[] points;
    private int init;
    private Vector normal;

    public Surface(){
        points = new Point[3];
        init = 0;
    }

    public void setNormal(float a, float b, float c){
        normal = new Vector();
        normal.setVector(a,b,c);
    }

    public Vector getNormal(){
        return this.normal;
    }
    
    public Point[] getPoint(){
        return this.points;
    }
}