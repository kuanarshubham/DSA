// ninja training

import java.util.Arrays;

public class Java128 {
    static int helper(int[][]points, int day, int last){
        if(day<0) return 0;

        int maxiPoints = 0;

        for(int i=0; i<3; i++){
            if(last!=i){
                maxiPoints = Math.max(maxiPoints, points[day][i]+helper(points, day-1, i));
            }
        }

        return maxiPoints;
    } 

    static int ninjaMaxPoints(int[][]points, int days){
        int[][] dp = new int[days][3];
        for (int i = 0; i < days; i++) {
            Arrays.fill(dp[i], -1);
        }
        return helper(points, days-1, -1);
    }
}