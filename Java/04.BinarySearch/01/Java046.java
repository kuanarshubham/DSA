// get me the elemnet in rotated sorted array with dups element

public class Java046 {
    public static int serach(int[]nums, int target){
        int n=nums.length;

        int low=0, high=n-1;

        while(low<=high){
            int mid = low + (high-low)/2;

            if(nums[mid]==target) return mid;
            if (nums[low] == nums[mid] && nums[mid] == nums[high]) {
                low = low + 1;
                high = high - 1;
                continue;
            }
            else if(nums[low] <= nums[mid]){
                if(nums[low]<=target && target<=nums[mid]) high=mid-1;
                else low=mid+1;
            }
            else{
                if(nums[mid]<=target && target<=nums[high]) low=mid+1;
                else high=mid-1;
            }
        }

        return -1;
    }
    public static void main(String[] args) {
        int[] nums = {3, 1, 2, 3, 3, 3, 3};

        System.err.println(serach(nums, 3));
    }
}
