// majority element

public class Java16 {

    public static int majorityElement(int[]nums){
        int n=nums.length;

        int val=-1, count=0;

        for(int i=0; i<n; i++){
            if(count==0){
                val=nums[i];
                count++;
            }
            else if(val == nums[i]) count++;
            else count--;
        }

        return val;
    }
    public static void main(String[] args) {
        int[] nums = new int[]{1, 2, 4, 4, 5, 4, 4, 1, 1, 1, 1};

        System.err.println(majorityElement(nums));
    }
}
