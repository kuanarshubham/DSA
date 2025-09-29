// smallest divisor

public class Java055 {
    public static int valueAfterDivide(int[]nums, int divisor, int limit){
        int sum=0;

        for(int num: nums){
            sum += Math.ceil((double)num/divisor);
            if(sum>limit) break;
        }

        return sum;
    }

    public static int smallestDivisor(int[] nums, int limit){
        int n=nums.length, low=Integer.MAX_VALUE, high=Integer.MIN_VALUE;
        
        for(int num: nums){
            low=Integer.min(low, num);
            high=Integer.max(high, num);
        }

        if(n<limit) return -1;

        while(low<=high){
            int mid = low+(high-low)/2;

            int value = valueAfterDivide(nums, mid, limit);

            if(value==limit) return mid;
            else if(value>limit) low=mid+1;
            else high=mid-1;
        }

        return low;
    }
    public static void main(String[] args) {
        
    }
}
