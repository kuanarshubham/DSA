public class Java08 {
    public static int linearSearch(int[]nums, int k){
        int n=nums.length;
        
        for(int i=0; i<n; i++){
            if(nums[i]==k) return i+1;
        }

        return -1;
    }

    public static void main(String[] args) {
        int []nums = new int[]{1, 2, 3, 4, 5, 6};

        System.err.println(linearSearch(nums, 5));
    }
}
