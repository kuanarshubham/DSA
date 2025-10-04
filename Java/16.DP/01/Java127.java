// house robber 2

public class Java127 {
    static int helper(int[]houses, int currHouse, int lowest){
        if(currHouse<lowest) return 0;

        int take = houses[currHouse] + helper(houses, currHouse-2, lowest);
        int notTake = helper(houses, currHouse-1, lowest);

        return Math.max(take, notTake);
    }

    static int houseRobber2(int[]houses){
        int n=houses.length;

        int takeFirst = helper(houses, n-2, 0);
        int takeLast = helper(houses, n-1, 1);

        return Math.max(takeFirst, takeLast);
    }
}