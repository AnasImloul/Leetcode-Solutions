// Runtime: 2 ms (Top 77.93%) | Memory: 42.7 MB (Top 83.40%)
// BruteForce Approach!
// Author - Nikhil Sharma
// LinkedIn - https://www.linkedin.com/in/nikhil-sharma-41a287226/
// Twitter - https://twitter.com/Sharma_Nikh12

class Solution {
    public List<Integer> pancakeSort(int[] arr) {
        List<Integer> list = new ArrayList<>();
        int n = arr.length;
        while(n!=1) {
            int maxIndex = findIndex(arr,n);
            reverse(arr, maxIndex);
            reverse(arr, n-1);
            list.add(maxIndex+1);
            list.add(n);
            n--;
        }
        return list;
    }

    static int findIndex(int[] arr, int value) {
        for(int i=0; i<arr.length; i++) {
            if(arr[i] == value){
                return i;
            }
        }
        return 0;
    }

    static void reverse(int[] arr, int maxIndex) {
        int l = 0;
        while(l<maxIndex) {
            int temp = arr[l];
            arr[l] = arr[maxIndex];
            arr[maxIndex] = temp;
            l++;
            maxIndex--;
        }
    }
}