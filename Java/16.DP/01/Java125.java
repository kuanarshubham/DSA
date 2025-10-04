// frog jump 2

import java.util.Arrays;

public class Java125 {
    static int helper(int[]height, int i, int[]dp, int k){
        if(i==1) return Math.abs(height[1]-height[0]);
        if(i==0) return 0;
        if(dp[i]!=-1) return dp[i];
        
        int miniEnergy=Integer.MAX_VALUE;
        for(int it=1; it<=k; it++){
            if(i-it>=0){
                miniEnergy = Math.min(Math.abs(height[i]-height[i-it])+helper(height, i-it, dp, k), miniEnergy);
            }
        }

        return dp[i]=miniEnergy;
    }

    static int frogJump2(int[]height, int k){
        int n=height.length;
        int[] dp = new int[n];
        Arrays.fill(dp, -1);

        return helper(height, n-1, dp, k);
    }
}