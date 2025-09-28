// nth root of num

public class Java052 {
    public static int nthTimes(int mid, int n, int actualValue){
        int prod = 1;

        for(int i=0; i<n; i++){
            prod*=mid;
            if(prod>actualValue) return prod;
        }

        return prod;
    }

    public static int nthRoot(int num, int n){
        int low=0, high=num/2, ans=-1;

        while(low<=high){
            int mid = low + (high-low)/2;

            int value = nthTimes(mid, n, num);

            if(value==num) return mid;
            else if(value>num){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }

        return ans;
    }

    public static void main(String[] args) {
        int num = 1000;

        System.err.println(nthRoot(num, 4));
    }
}
