// sort 1's 2's 0's

public class Java015 {
    public static void swap(int a, int b, int[] nums){
        int temp = nums[a];
        nums[a] = nums[b];
        nums[b] = temp;
    }

    public static void sort012Better(int[]nums){
        int n=nums.length;

        int zero=0, one=0, two=0;

        for(int num: nums){
            if(num==0) zero++;
            else if(num==1) one++;
            else two++;
        }

        int i=0;

        while(zero-->0){
            nums[i++]=0;
        }

        while(one-->0){
            nums[i++]=1;
        }

        while(two-->0){
            nums[i++]=2;
        }
    } 

    public static void sort012Optimal(int[]nums){
        int n=nums.length;

        int low=0, mid=0, high=n-1;

        while(mid<=high){
            if(nums[mid]==0){
                swap(mid,low, nums);
                low++;
                mid++;
            }
            else if(nums[mid]==1){
                mid++;
            }
            else{
                swap(mid, high, nums);
                high--;
            }
        }
    }

    public static void main(String[] args) {
        int[] nums = new int[]{2, 1, 0, 2, 1, 1, 1, 2, 0, 0, 1, 2};

        sort012Optimal(nums);

        for(int num: nums) System.err.println(num);
    }
}
