// rotate an matrix by 90 deg

public class Java024 {
    public static void swap(int[][]mat, int x1, int y1, int x2, int y2){
        int temp = mat[x1][y1];
        mat[x1][y1] = mat[x2][y2];
        mat[x2][y2] = temp;
    }

    public static void reverse(int[][]mat, int row){
        int cols = mat[0].length;
        for(int i=0; i<cols/2; i++){
            swap(mat, row, i, row, cols-i-1);
        }
    }

    public static void rotateImage(int[][]mat){
        int rows = mat.length, cols = mat[0].length;

        for(int i=0; i<rows; i++){
            for(int j=0; j<=i; j++){
                swap(mat, i, j, j, i);
            }
        }

        for(int i=0; i<rows; i++){
            reverse(mat, i);
        }
    }
    public static void main(String[] args) {
        int[][] mat = new int[][]{
            {00, 01, 02},
            {10, 11, 12},
            {20, 21, 22}
        };

        rotateImage(mat);

        for(int[] row: mat){
            for(int col: row){
                System.err.print(col + " ");
            }
            System.err.println();
        }
    }
}
