// move zeros to the end


public class Java007 {

    public static void swap(int i, int j, int[]nums){
        int temp = nums[i];
        nums[i]=nums[j];
        nums[j]=temp;    
    }

    public static void zerosAtTheEnd(int[]nums){
        int n = nums.length;

        int i=-1;

        for(int j=0; j<n; j++){
            if(nums[j]!=0){
                i++;
                swap(i, j, nums);
            } 
        }
    }

    public static void main(String[] args) {
        int[] nums = new int[]{0, 0, 1, 2, 0, 0, 4, 0, 5, 0, 0, 0, 6};

        zerosAtTheEnd(nums);

        for(int num: nums) System.err.println(num);
    }
}
