// set mat zeros

public class Java023 {
    public static void setMatZero(int[][]mat){
        int rows=mat.length, cols=mat[0].length;

        int mat00 = 1;

        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                if(mat[i][j]==0){
                    if(j==0) mat00 = 0;
                    else mat[0][j] = 0;

                    mat[i][0] = 0;
                }
            }
        }

        for(int i=1; i<rows; i++){
            for(int j=1; j<cols; j++){
                if(j==0 && (mat00==0 || mat[i][0]==0)){
                    mat[i][j]=0;
                }
                else if(mat[0][j]==0 || mat[i][0]==0){
                    mat[i][j]=0;
                }
            }
        }
    }
    public static void main(String[] args) {
        int[][] mat = new int[][]{{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};

        
    }
}
