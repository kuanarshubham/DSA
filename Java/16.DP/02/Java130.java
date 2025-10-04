// Grid Unique Paths 2 (DP 9)

public class Java130 {
    static int memo(int[][]mat, int row, int col, int[][]dp){
        if(row<0) return 0;
        if(col<0) return 0;
        if(row==0 && col==0) return 1;

        

        if(dp[row][col]!=-1) return dp[row][col];

        int left = memo(mat, row, col-1, dp);
        int top = memo(mat, row-1, col, dp);

        return dp[row][col]=left+top;
    }

    static int tabs(int[][]mat){
        int totalRows = mat.length, totalCols = mat[0].length;

        int[][] dp = new int[totalRows][totalCols];

        for(int i=0; i<totalRows; i++) Arrays.fill(dp[i], -1);

        dp[0][0] = 1;

        for(int i=1; i<totalRows; i++){
            for(int j=1; j<totalCols; j++){
                if(mat[row][col]==-1) dp[i][j]=0;
                else dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }

        return dp[totalRows-1][totalCols-1];
    }
}