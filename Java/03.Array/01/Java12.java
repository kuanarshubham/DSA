// longest subarray with given sum k for positive number

public class Java12 {

    public static int[] longestSubarrayWithSumK(int[]nums, int k){
        int n=nums.length;

        int i=0, j=0, sum=0, startIdx=-1, endIdx=-1, size=0;

        while(j<n){
            sum+=nums[j];

            while(sum>k && i<=j){
                sum-=nums[i];
                i++;
            }

            if(sum==k){
                if(size < j-i+1){
                    startIdx=i;
                    endIdx=j;
                    size=j-i+1;
                }
            }

            j++;
        }

        return new int[]{startIdx, endIdx};
    }

    public static void main(String[] args) {
        int[] nums = new int[]{2, 3, 4, 5, 0, 0, 6};

        int[] idx = longestSubarrayWithSumK(nums, 9);

        System.err.println(idx[0]+" " +idx[1]);
    }
}
