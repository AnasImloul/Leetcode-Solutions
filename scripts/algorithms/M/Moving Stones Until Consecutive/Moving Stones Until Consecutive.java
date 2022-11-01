// Runtime: 2 ms (Top 43.75%) | Memory: 41.9 MB (Top 57.50%)
class Solution {
    public int[] numMovesStones(int a, int b, int c) {
        int[] arr ={a,b,c};
        int[] arr2 = {a,b,c};
        int maximum = findMaximum(arr);
        int minimum = findMinimum(maximum,arr2);
        return new int[]{minimum,maximum};
    }
    public int findMaximum(int[] arr){
        Arrays.sort(arr);
        int count = 0;
        if(arr[0] == (arr[1]-1) && arr[1] == (arr[2] -1) ) return count;
        if(arr[0] == arr[1]-1){
            arr[2]--;
            count++;
        }
        else{
            arr[0]++;
            count++;
        }
        return count + findMaximum(arr);

    }

    public int findMinimum(int max,int[] arr){
        Arrays.sort(arr);
        if(max == 0) return 0;
        else if(Math.abs(arr[0]-arr[1]) >2 && Math.abs(arr[1]-arr[2]) >2 ) return 2;
        else return 1;
    }
}