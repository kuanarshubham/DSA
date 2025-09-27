public class Java042 {
    public static int lowerBound(int[]nums, int toInsert){
        int n=nums.length;

        int low=0, high=n-1, lb=n;

        while(low<=high){
            int mid = low + (high-low)/2;

            if(nums[mid]>=toInsert){
                lb=mid;
                high=mid-1;
            }
            else low=mid+1;
        }

        return lb;
    }
    public static void main(String[] args) {
        int[] nums = new int[]{1,2,4,7};

        System.err.println(lowerBound(nums, 6));
    }
}
