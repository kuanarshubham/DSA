import java.util.*;

public class Java01 {

    public static int[] twoSum(int[]nums, int k){
        int n=nums.length;

        Arrays.sort(nums);

        int j=n-1, i=0;
        while(i<n && j>=0){
            int sum = nums[i]+nums[j];
            if(sum==k) return new int[]{nums[i], nums[j]};
            else if(sum>k) j--;
            else i++;
        }

        return new int[]{-1, -1};
    }

    public static void main(String[] args) {
        int[] nums = new int[]{7, 4, 27, 8, 99, 10};

        int[] idx = twoSum(nums, 14);

        System.err.println(idx[0]+" "+idx[1]);
    }
}
