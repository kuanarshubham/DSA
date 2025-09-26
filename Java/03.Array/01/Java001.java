import java.util.*;

public class Java001 {
    
    public static int maxNumber(List<Integer>nums){
        int maxi=Integer.MIN_VALUE;

        for(int num: nums){
            maxi = Integer.max(maxi, num);
        }
        
        return maxi;
    }
    public static void main(String[] args) {
        List<Integer>l = new ArrayList<Integer>();

        l.add(1);
        l.add(2);
        l.add(3);
        l.add(4);

        System.err.println(maxNumber(l));
    }
}
