// union of 2 sorted array
// intersection of 2 sorted array

import java.util.Arrays;

public class Java09 {
    public static int[] intersection(int[] arr1, int[]arr2){
        int n1=arr1.length, n2=arr2.length;

        int[] ans = new int[n1+n2];

        int i=0, j=0, k=0;

        while(i<n1 && j<n2){
            if(arr1[i]<arr2[j]) i++;
            else if(arr1[i]>arr2[j]) j++;
            else{
                ans[k++] = arr1[i];
                i++;
                j++;
            }
        }

        return Arrays.copyOf(ans, k);
    }

    public static int[] union(int[]arr1, int[]arr2){
        int n1 = arr1.length, n2 = arr2.length;

        int[] ans = new int[n1+n2];

        int i=0, j=0, k=0;

        if(arr1[i]<arr2[j]){
            ans[k]=arr1[i];
            i++;
        }
        else{
            ans[k]=arr2[j];
            j++;
        }

        k++;

        while(i<n1 && j<n2){
            if(arr1[i]<arr2[j]){
                if(ans[k-1]!=arr1[i]){
                    ans[k]=arr1[i];
                    k++;
                }

                i++;
            }
            else if(arr2[j]<=arr1[i]){
                if(ans[k-1]!=arr2[j]){
                    ans[k]=arr2[j];
                    k++;
                }

                j++;
            }
        }

        while(i<n1){
            if(ans[k-1]!=arr1[i]){
                ans[k]=arr1[i];
                k++;
            }

            i++;
        }

        while(j<n2){
            if(ans[k-1]!=arr2[j]){
                ans[k]=arr2[j];
                k++;
            }

            j++;
        }

        return Arrays.copyOf(ans, k);
    }

    public static void main(String[] args) {
        int []nums1 = new int[]{1, 2, 3, 4};
        int []nums2 = new int[]{4, 5, 6};

        int[] un = union(nums1, nums2);
        
        for(int num: un) System.err.println(num);

        int[] in = intersection(nums2, nums1);

        for(int num: in) System.err.println(num);
    }
}
