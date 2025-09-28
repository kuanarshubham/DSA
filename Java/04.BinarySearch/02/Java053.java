// koko eating banana

public class Java053 {
    public static int timeTaken(int[]pile, int hrs, int speed){
        int reqSpeed = 0;

        for(int size: pile){
            reqSpeed += Math.ceil((double)size/speed);
            if(reqSpeed > hrs) break;
        }

        return reqSpeed;
    }

    public static int miniSpeed(int[]pile, int hrs){
        int mini=Integer.MAX_VALUE, maxi=Integer.MIN_VALUE;

        for(int num: pile){
            maxi = Integer.max(maxi, num);
            mini = Integer.min(num, mini);
        }

        int low=mini, high=maxi;

        while(low<=high){
            int mid=low + (high-low)/2;

            int reqSpeed = timeTaken(pile, hrs, mid);
            System.err.println(reqSpeed + " " + mid);

            if(reqSpeed==hrs) return mid;
            else if(reqSpeed>hrs) low=mid+1;
            else high=mid-1;
        }

        return -1;
    }

    public static void main(String[] args) {
        int[] pile = {30,11,23,4,20};

        int hrs = 5;

        System.err.println(miniSpeed(pile, hrs));
    }
}
