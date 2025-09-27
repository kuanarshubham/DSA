// single element in the sorted array

public class Java050 {
    public static int single(int[]nums){
        int n=nums.length;

        if(nums[0]!=nums[1]) return nums[0];
        
        if(nums[n-1]!=nums[n-2]) return nums[n-1];

        int low=1, high=n-2;

        while(low<=high){
            int mid = low + (high-low)/2;

            if(nums[mid]!=nums[mid-1] && nums[mid]!=nums[mid+1]) return mid;
            else if(nums[mid]==nums[mid-1]){
                int lowMidLen = mid-low;
                if(lowMidLen%2==0) low=mid+1;
                else high=mid-1;
            }
            else{
                int midHighLen = high-mid;

                if(midHighLen%2==0) high=mid-1;
                else low=mid+1;
            }
        }

        return -1;
    }
    public static void main(String[] args) {
        int[] nums = new int[]{1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 7, 7, 8, 8, 9, 9};

        System.err.println(single(nums));
    }
}
