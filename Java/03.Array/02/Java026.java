// count subarray with sum

import java.util.*;

public class Java026 {
    public static int subarrayWithSumK(int[]nums, int k){
        int n=nums.length;

        HashMap<Integer, Integer>map = new HashMap<>();

        int sum=0, count=0;

        for(int i=0; i<n; i++){
            sum+=nums[i];
            
            int remaining = k-sum;

            if(map.containsValue(remaining)){
                count+=map.get(remaining);
            }
        }

        return count;
    }
    public static void main(String[] args) {
        
    }
}
