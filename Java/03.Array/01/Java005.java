// remove dups  in place in sorted array

import java.util.*;

public class Java005{

    public static int removeDups(List<Integer>nums){
        int n = nums.size();

        int j=0;
        for(int i=1; i<n; i++){
            if(nums.get(i)!=nums.get(j)){
                j++;
                Collections.swap(nums, j, i);
            }
        }

        return j;
    }

    public static void main(String[] args) {
        List<Integer>l = new ArrayList<Integer>(List.of(1, 2, 2, 4, 5, 6, 6, 7, 7, 7, 8));

        int len = removeDups(l);

        for(int i=0; i<=len; i++) System.err.println(l.get(i));
    }
}