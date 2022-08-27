// Runtime: 2 ms (Top 77.02%) | Memory: 54.3 MB (Top 41.77%)
class Solution {
    public boolean validMountainArray(int[] arr) {
        // edge case
        if(arr.length < 3) return false;
        // keep 2 pointers
        int i=0;
        int j=arr.length-1;
        // use i pointer to iterate through steep increase from LHS
        while(i<j && arr[i]<arr[i+1]) {
            i++;
        }
        // use j pointer to iterate steep increase from RHS
        while(j>i && arr[j]<arr[j-1]) {
            j--;
        }
        // both should meet at same place and it be neither start or end.
        return i==j && i<arr.length-1 && j>0;
    }
}