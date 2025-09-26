//  get me the leaders of the arary

import java.util.*;

public class Java022 {
    static int[] leader(int[]nums){
        int n=nums.length, maxi=Integer.MIN_VALUE;

        ArrayList<Integer>temp = new ArrayList<>();

        for(int i=n-1; i>=0; i--){
            if(maxi < nums[i]){
                temp.add(nums[i]);
            }

            maxi = Integer.max(maxi, nums[i]);
        }

        int ansSize = temp.size();
        int[] ans = new int[ansSize];
        int i=0;

        Collections.reverse(temp);

        while(i<ansSize){
            ans[i] = temp.get(i);
            i++;
        }

        return ans;
    }
    public static void main(String[] args) {
        int[] nums = new int[]{4, 7, 1, 0};

        int[] ans = leader(nums);

        for(int num: ans) System.err.println(num);
    }
}
