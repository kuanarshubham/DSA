// min number of days to create bouque

public class Java054 {
    public static int canMakeAllBouque(int[]bloomDay, int waitDay, int noBouque, int noFlower){
        int currBouque = 0;
        int currFlower = 0;
        int n=bloomDay.length;

        for(int i=0; i<n; i++){
            if(waitDay>=bloomDay[i]){
                currFlower++;
                if(currFlower!=0 && currFlower%noFlower==0){
                    currBouque++;
                    currFlower=0;
                }

                if(currBouque > noBouque) break;
            }
            else{
                currFlower=0;
            }
        }

        return currBouque;
    }

    public static int daysToWait(int[]bloomDay, int noBouque, int noFlower){
        int n=bloomDay.length, maxi=Integer.MIN_VALUE, mini=Integer.MAX_VALUE;

        if(n < noBouque * noFlower) return -1;

        for(int day: bloomDay){
            maxi = Integer.max(maxi, day);
            mini = Integer.min(mini, day);
        }

        int low=mini, high=maxi;
        
        while(low<=high){
            int mid = low + (high-low)/2;

            int currBouque = canMakeAllBouque(bloomDay, mid, noBouque, noFlower);

            if(currBouque==noBouque) return mid;
            else if(currBouque>noBouque) high=mid-1;
            else low=mid+1;
        }

        return -1;
    }

    public static void main(String[] args) {
        int[] bloomDay = {7,7,7,7,12,7,7};

        System.err.println(daysToWait(bloomDay, 2, 3));
    }
}
