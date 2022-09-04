// Runtime: 0 ms (Top 100.00%) | Memory: 59.7 MB (Top 83.58%)
class Solution {
public int peakIndexInMountainArray(int[] arr) {

    int start = 0;
    int end = arr.length - 1;

    while( start < end){
        int mid = start + (end - start)/2;
        // if mid < mid next
        if(arr[mid] < arr[mid + 1]){
            start = mid + 1;
        }
        // otherwise it can either peak element or greater element
        else{
            end = mid;
        }
    }
    return start; // or we can return end also, bcz both will be on same value at the time, that's why loop breaks here.
    }
}