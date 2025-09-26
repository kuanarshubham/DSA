// upper bound

public class Java03 {
    public static int upperBound(int[]nums, int value){
        int n=nums.length;

        int low=0, high=n-1, mid, ub=n;

        while(low<=high){
            mid=low+(high-low)/2;

            if(nums[mid]>value){
                ub = mid;
                high=mid-1;
            }
            else low = mid+1;
        }

        return ub;
    }
    public static void main(String[] args) {
        int[] nums = new int[]{3,5,8,15,19};

        System.err.println(upperBound(nums, 8));
    }
}
