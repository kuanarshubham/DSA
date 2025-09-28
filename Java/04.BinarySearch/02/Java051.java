// sqrt of a number

public class Java051 {
    public static int sqrt(int num){
        int low = 0, high = num/2;

        while (low<=high) {
            int mid = low + (high-low)/2;

            int sqMid = mid*mid;

            if(sqMid == num) return mid;
            else if(sqMid>num) high=mid-1;
            else low=mid+1;
        }

        return high;

    }
    public static void main(String[] args) {
        int num = 16;

        System.err.println(sqrt(num));
    }
}
