// alternative positive and negative

import java.util.*;

public class Java20 {
    public static void swap(int[]nums, int x, int y){
        int temp = nums[x];
        nums[x] = nums[y];
        nums[y] = temp;
    }

    public static void alternativePosNeg(int[]nums){
        int n=nums.length;

        ArrayList<Integer>pos = new ArrayList<Integer>();
        ArrayList<Integer>neg = new ArrayList<Integer>();

        for(int num: nums){
            if(num>0) pos.add(num);
            else neg.add(num);
        }

        int posIdx=pos.size()-1, negIdx=neg.size()-1;

        for(int i=0; i<n; i++){
            if(i%2==0){
                nums[i] = pos.get(posIdx);
                pos.remove(posIdx);
            }
            else{
                nums[i] = neg.get(negIdx);
                neg.remove(negIdx);
            }
        }
    } 
    
    public static void main(String[] args) {
        int[] nums = new int[]{1,2,-3,-1,-2,-3};

        alternativePosNeg(nums);

        for(int num: nums) System.err.println(num);
    }
}
