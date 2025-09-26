// rotate an arry by D places


public class Java006 {

    public static void rotate(int[]nums, int k){
        int n = nums.length;

        int kNew = k%n;

        if(k==0) return;

        int[] temp = new int[kNew];

        for(int i=0; i<kNew; i++){
            temp[i]=nums[i];
        }

        // shift the array
        for(int i=kNew; i<n; i++){
            nums[i-kNew]=nums[i];
        }

        // append at the end
        for (int i = 0; i < kNew; i++) {
            nums[n - kNew + i] = temp[i];
        }
    }

    public static void main(String[] args) {
        
        int[] nums = new int[]{1, 2, 3, 4, 5, 6};

        rotate(nums, 2);

        for(int num: nums) System.err.println(num);
    }
}
