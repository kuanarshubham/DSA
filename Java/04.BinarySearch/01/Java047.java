// peak in the rotated sorted array

public class Java047 {
    public static int peak(int[]nums){
        int n=nums.length;
        
        int low=1, high=n-2;

        while(low<=high){
            int mid=low+(high-low)/2;

            if(nums[mid-1]<nums[mid] && nums[mid+1]<nums[mid]) return mid;
            else if(nums[low]==nums[mid] && nums[mid]==nums[high]){
                low++;
                high--;
                continue;
            }
            else if(nums[mid]>=nums[low]){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }

        return 0;
    }

    public static void main(String[] args) {
        int[] nums = new int[]{3, 3, 3, 3, 5, 6, 7, 8, 9, 1, 2, 3, 3, 3, 3, 3, 3, 3};

        System.err.println(peak(nums));
    }
}
