//print matrix in spiral order

public class Java025 {
    public static void spiralMatrix(int[][]mat){
        int cols = mat[0].length;

        int row = 0;

        for(int i=0; i<cols-1; i++){
            System.err.println(mat[row][i]);
        }
    }
    public static void main(String[] args) {
        
    }
}
