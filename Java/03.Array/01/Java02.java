import java.util.*;

class Java02{
    public static int secondMax(List<Integer>nums){
        int maxi = Integer.MIN_VALUE, secMaxi = Integer.MIN_VALUE;

        for(int num: nums){
            if(num>maxi){
                secMaxi = maxi;
                maxi = num;
            }
            else if(num>secMaxi){
                secMaxi = num;
            }
        }

        return secMaxi;
    }

    public static void main(String[] args) {
        List<Integer>l = new ArrayList<Integer>(List.of(1, 2, 3, 4, 5));
        System.err.println(secondMax(l));
    }
}