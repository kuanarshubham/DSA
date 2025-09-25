// sort 1's 2's 0's

public class Java02 {
    public static void sort012Better(int[]nums){
        int n=nums.length;

        int zero=0, one=0, two=0;

        for(int num: nums){
            if(num==0) zero++;
            else if(num==1) one++;
            else if(num==2) two++;
        }

        for(int i=0; i<n; i++){
            if(zero>=0){
                nums[i] = 0;
                zero--;
            }   
            else if(one>=0){
                nums[i] = 1;
                one--;
            }
            else{
                nums[i] = 2;
                two--;
            }
        }
    } 
    public static void main(String[] args) {
        int[] nums = new int[]{2, 1, 0, 2, 1, 1, 1, 2, 0, 0, 1, 2};

        sort012Better(nums);

        for(int num: nums) System.err.println(num);
    }
}
