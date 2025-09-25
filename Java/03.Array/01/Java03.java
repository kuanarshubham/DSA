import java.util.*;

public class Java03 {
    public static boolean checkSorted(List<Integer>nums){
        int lastMini = Integer.MIN_VALUE;

        for(int num: nums){
            if(lastMini>num) return false;
            lastMini = num;
        }

        return true;
    }
    public static void main(String[] args) {
        List<Integer>l = new ArrayList<Integer>(List.of(1, 9, 3, 4, 5, 6));

        System.err.println(checkSorted(l));
    }
}
