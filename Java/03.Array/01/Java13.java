import java.util.HashMap;

public class Java13 {
    public static int[] longestSubarrayWithSumK(int[]nums, int k){
        int sum =0, n=nums.length;

        HashMap<Integer, Integer>map = new HashMap<Integer, Integer>();

        map.put(0, -1);

        int startingIdx=-1, endingIdx = -1, size = 0;

        for(int i=0; i<n; i++){
            sum+=nums[i];

            if (!map.containsKey(sum)) {
                map.put(sum, i);
            }
            
            int remaining = sum-k;

            if(map.containsKey(remaining)){
                int currEnd = i, currStart = map.get(remaining)+1;

                if(size < currEnd-currStart+1){
                    endingIdx = i;
                    startingIdx = map.get(remaining)+1;
                    size = currEnd-currStart+1;;
                }
            }
        }

        return new int[]{startingIdx, endingIdx};
    }

    public static void main(String[] args) {
        int[] nums = new int[]{2, 3, -4, 5, 0, 0, 6};

        int[] idx = longestSubarrayWithSumK(nums, 1);

        System.err.println(idx[0]+" " +idx[1]);
    }
}
