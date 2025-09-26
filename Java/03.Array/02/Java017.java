// maxi subarray sum;

public class Java017 {
    public static int maxiSum(int[]nums){
        int n=nums.length, maxi=Integer.MIN_VALUE, sum=0;

        for(int i=0; i<n; i++){
            sum+=nums[i];
            
            if(maxi<sum) maxi=sum;

            if(sum<0) sum=0;
        }

        return maxi;
    }
    public static void main(String[] args) {
        int[] nums= new int[]{-2, 1, -3, 4, -1, 2, 1, -5, 4};

        System.err.println(maxiSum(nums));
    }
}
