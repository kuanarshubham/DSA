// total unique path i can move from TL to BR

import java.util.Arrays;

public class Java129 {
    static int helper(int[][]mat, int row, int col, int[][]dp){
        if(col<0) return 0;
        if(row<0) return 0;

        if(col==0 && row==0) return 1;

        if(dp[row][col]!=-1) return dp[row][col];

        int left = helper(mat, row, col-1, dp);
        int top = helper(mat, row-1, col, dp);

        return  dp[row][col] = left+top;
    } 

    static int memo(int[][]mat){
        int totalRows = mat.length;
        int totalCols = mat[0].length;

        int[][] dp = new int[totalRows][totalCols];

        for(int i=0; i<totalRows; i++) Arrays.fill(dp[i], -1);

        return helper(mat, totalRows-1, totalCols-1, dp);
    }

    static int tabs(int[][]mat){
        int totalRows = mat.length;
        int totalCols = mat[0].length;

        int[][] dp = new int[totalRows][totalCols];

        for(int i=0; i<totalRows; i++) Arrays.fill(dp[i], 0);

        dp[0][0]=1;

        for(int row=1; row<totalRows; row++){
            for(int col=1; col<totalCols; col++){
                int right = mat[row][col-1];
                int bottom = mat[row-1][col];
                dp[row][col] = right+bottom;
            }
        }

        return dp[totalRows-1][totalCols-1];
    }

    static int space(int[][]mat){
        int totalRows = mat.length;
        int totalCols = mat[0].length;

        int[]prev = new int[totalCols];
        int[] curr = new int[totalCols];

        Arrays.fill(prev, 0);
        Arrays.fill(curr, 0);

        prev[0] = 1;

        for(int row=1; row<totalRows; row++){
            for(int col=1; col<totalCols; col++){
                int right = curr[col-1];
                int bottom = prev[col];
                curr[row] = right+bottom;
            }

            prev = curr;
        }

        return prev[totalCols-1];
    }
}