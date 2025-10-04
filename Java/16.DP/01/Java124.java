// frog jump 1

import java.util.Arrays;

public class Java124 {
    static int helper(int[]height, int i, int[]dp){
        if(i==0) return 0;
        if(i==1) return Math.abs(height[1]-height[0]);
        if(dp[i]!=-1) return dp[i];
        
        int oneStep = Math.abs(height[i]-height[i-1]) + helper(height, i-1);
        int twoStep = Math.abs(height[i]-height[i-2]) + helper(height, i-2);

        return dp[i] = Math.min(oneStep, twoStep);
    }

    static int frogJump(int[]height){
        int n=height.length;
        int[] dp = new int[n];
        Arrays.fill(dp, -1);
        return helper(height, n-1);
    }
}