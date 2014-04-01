
public class Matriz {

    
    public static float[][] transpose(float A[][]) {
        int Rows = A.length,
        int Columns = A[0].length;

        float[][] resultant = new float[Columns][Rows];
        
        for(int i = 0; i < Rows; i++)
            for (int j = 0; j < Columns; j++)
                resultant[j][i] = a[i][j];
        return resultant;
    }
    
    public static float[][] normalize(float A[][]){
        int ARows = A.length,
        int AColumns = A[0].length;
        float[][] resultant = new float[ARows-1][AColumns];
        for (int i = 0; i < ARows-1; i++){
            for (int j = 0; j < AColumns; j++)
                resultant[i][j] = a[i][j]/A[ARows-1][j];
        }
        return resultant;
    }

}
