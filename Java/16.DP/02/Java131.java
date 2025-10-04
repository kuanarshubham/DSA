// Minimum Path Sum In a Grid (DP 10)

// wrong

import java.util.Arrays;

public class Java131 {
    static int memo(int[][]mat, int row, int col, int[][]dp){
        if(row<0) return 0;
        if(col<0) return 0;
        if(row==0 && col==0) return mat[row][col];

        if(dp[row][col]!=-1) return dp[row][col];

        int left = memo(mat, row, col-1, dp);
        int top = memo(mat, row-1, col, dp);
        
        return dp[row][col] = mat[row][col] + Math.max(left, top);
    }

    static int tabs(int[][]mat){
        int totalRows=mat.length, totalCols=mat[0].length;

        int[][]dp = new int[totalRows][totalCols];

        for(int i=0; i<totalRows; i++) Arrays.fill(dp[i], 0);

        dp[0][0] = mat[0][0];

        for(int row=1; row<totalRows; row++){
            for(int col=1; col<totalCols; col++){
                dp[row][col] = mat[row][col] + Math.max(dp[row][col-1], dp[row-1][col]);
            }
        }

        return dp[totalRows-1][totalCols-1];
    }
}