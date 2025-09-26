// buy sell stock

public class Java019 {
    public static int buySellStock1(int[]days){
        int n=days.length;

        int miniDay=Integer.MAX_VALUE, maxiProf=Integer.MIN_VALUE;

        for(int i=0; i<n; i++){
            miniDay = Integer.min(miniDay, days[i]);
            maxiProf = Integer.max(maxiProf, -miniDay+days[i]);
        }

        return maxiProf;
    }

    public static void main(String[] args) {
        int[] days = new int[]{7,1,5,3,6,4};

        System.err.println(buySellStock1(days));
    }
}
