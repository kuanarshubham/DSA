// count subarray with sum

import java.util.*;

public class Java026 {
    public static int subarrayWithSumK(int[]nums, int k){
        int n=nums.length;

        HashMap<Integer, Integer>map = new HashMap<>();

        int sum=0, count=0;

        map.put(0, 1);

        for(int i=0; i<n; i++){
            sum+=nums[i];
            int remaining = k-sum;

            if(!map.containsKey(sum)) map.put(sum, 1);
            else map.put(sum, map.get(sum)+1);

            if(map.containsKey(remaining)){
                count+=map.get(remaining);
            }
        }

        return count;
    }

    public static void main(String[] args) {
        int[] nums = new int[]{3, 1, 2, 4};

        System.err.println(subarrayWithSumK(nums, 6));
    }
}
