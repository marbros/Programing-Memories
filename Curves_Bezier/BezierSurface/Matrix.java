
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

}
