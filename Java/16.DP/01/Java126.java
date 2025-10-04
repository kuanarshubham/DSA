// house robber

public class Java126 {
    static int helper(int[] houses, int curHouse){
        if(curHouse<0) return 0;
        
        int take = houses[curHouse] + helper(houses, curHouse-2);
        int notTake = helper(houses, curHouse-1);

        return Integer.max(take, notTake);
    }

    static int houseRobber(int[]houses){
        int n=houses.length;

        return helper(houses, n-1);
    }
}