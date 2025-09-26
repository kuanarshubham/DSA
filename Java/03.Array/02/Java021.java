// next permuation

public class Java021 {
    public static void swap(int a, int b, int[]nums){
        int temp = nums[a];
        nums[a] = nums[b];
        nums[b] = temp;
    }

    public static void reverse(int[]nums){
        int n=nums.length;

        for(int i=0; i<Math.ceil(n/2); i++){
            swap(i, n-i-1, nums);
        }
    }

    public static int getMinTillN(int[]nums, int i){
        int n=nums.length, mini=Integer.MIN_VALUE, idx=-1;

        for(int it=i; it<n; it++){
            if(mini>nums[it]){
                idx=it;
                mini = nums[it];
            }
        }

        return idx;
    }

    public static void permute(int[]nums){

        // find the breaking point
        int n=nums.length, breakPoint = 0;

        for(int i=n-1; i>0; i--){
            if(nums[i]>nums[i-1]){
                breakPoint = n-1;
                break;
            }
        }

        // if breakpoint is at start return the reverse -> since the whole array is at end permunation

        if(breakPoint==0){
            reverse(nums);
            return;
        }

        // get the mini's idx to swap with the i-1;

        int idx = getMinTillN(nums, breakPoint);

        swap(idx, breakPoint-1, nums);

    }

    public static void main(String[] args) {
        
    }
}
