public class Java11 {

    public static int numberThatAppearOnce(int[]nums){
        int xorSum = 0;

        for(int num: nums) xorSum ^= num;

        return xorSum;
    }
    public static void main(String[] args) {
        int[] nums = new int[]{1, 2, 3, 2, 4, 5, 5, 1, 3};

        System.err.println(numberThatAppearOnce(nums));
    }
}
