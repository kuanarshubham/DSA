// number of times array is roated

public class Java049 {
    public static int rotatedTimes(int[]nums){
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
        int[] nums = new int[]{1, 2, 3, 4, 4, 4, 4};

        System.err.println(rotatedTimes(nums));
    }
}
