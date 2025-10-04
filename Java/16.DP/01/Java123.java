// climbing stairs

public class Java123 {
    static int helper(int n, int[]dp){
        if(n==0) return 0;
        if(n==1) return 1;

        if(dp[n]!=-1) return dp[n];
        
        return helper(n-1) + helper(n-2);
    }

    static int memo(int n){
        int[] dp = new int[n];

        Arrays.fill(dp, -1);   

        return helper(n, dp);
    }
}