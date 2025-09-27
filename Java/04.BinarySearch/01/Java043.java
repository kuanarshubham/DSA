// floor/ceil in sorted array

// just use the lower-bound and upper-bound

public class Java043 {
    public static int ceil(int[]nums, int target){
        int n=nums.length;

        int low=0, high=n-1, ub=n;

        while(low<=high){
            int mid = low + (high-low)/2;

            if(nums[mid]>target){
                ub=mid;
                high=mid-1;
            }
            else low=mid+1;
        }

        return ub;
    }


    public static void main(String[] args) {
        
    }
}
