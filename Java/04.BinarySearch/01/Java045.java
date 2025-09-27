// search in a roatated array

public class Java045 {

    public static int serach1(int[]nums, int target){
        int n=nums.length;

        int low = 0, high=n-1;

        while(low<=high){
            int mid = low + (high-low)/2;

            if(nums[mid]==target) return mid;
            // left one is sorted
            else if(nums[low]<=nums[mid]){
                if(nums[low]<=target && target<nums[mid]) high=mid-1;
                else low = mid+1;
            }
            // right one sorted
            else{
                if(nums[mid]<=target && target<nums[high]) low=mid+1;
                else high=mid-1;
            }
        }

        return -1;
    }
    public static void main(String[] args) {
        int[] nums = {4, 5, 1, 2, 3};

        System.err.println(serach1(nums, 4));
    }
}
