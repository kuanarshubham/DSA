// floor/ceil in sorted array

// just use the lower-bound and upper-bound

public class Java043 {
    public static int ceil(int[]nums, int target){
        int n=nums.length;

        int low=0, high=n-1, ans=n;

        while(low<=high){
            int mid = low + (high-low)/2;

            if(nums[mid]>=target){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }

        return ans;
    }

    public static int floor(int[]nums, int target){
        int n=nums.length;

        int low=0, high=n-1, ans=-1;

        while(low<=high){
            int mid = low + (high-low)/2;

            if(nums[mid]<=target){
                ans=mid;
                low=mid+1;
            }
            else high=mid-1;
        }

        return ans;
    }


    public static void main(String[] args) {
        int[]nums = {4, 7, 9, 12, 14, 72};

        System.err.println(floor(nums, 13) + " " + ceil(nums, 13));
    }
}
