public class Java010 {
    public static  int missingNumber(int[]nums){
        int n = nums.length+1;

        int lenSum = (n*(n+1))/2;

        int sum=0;

        for(int num: nums) sum+=num;

        return lenSum-sum;
    }

    public static void main(String[] args) {
        int[] nums = new int[]{1, 2, 3, 5};

        System.err.println(missingNumber(nums));
    }
}
