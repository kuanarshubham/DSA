// lower bound

public class Java040 {
    public static int lowerBound(int[]nums, int value){
        int n=nums.length;

        int low=0, high=n-1, mid, lb=n;

        while(low<=high){
            mid=low+(high-low)/2;

            if(nums[mid]>=value){
                lb = mid;
                high=mid-1;
            }
            else low = mid+1;
        }

        return lb;
    }
    public static void main(String[] args) {
        int[] nums = new int[]{3,5,8,15,19};

        System.err.println(lowerBound(nums, 9));
    }
}
