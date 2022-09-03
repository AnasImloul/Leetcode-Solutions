// Runtime: 11 ms (Top 6.67%) | Memory: 47.2 MB (Top 65.28%)
class Solution {
    int max = 0;
    int len;
    public int findBestValue(int[] arr, int target) {
        this.len = arr.length;

        for (int i = 0; i < len; i++)
            max = Math.max(max, arr[i]);

        int l = 0;
        int r = max;
        while(l < r){
            int mid = l + (r-l) / 2;

            if(check(arr, mid, target) <= check(arr, mid+1, target))
                r = mid;
            else
                l = mid + 1;
        }
        return l;
    }

    private int check(int[] arr, int value, int target){
        int sum = 0;
        for(int e : arr){
            if(e > value)
                sum += value;
            else
                sum += e;
        }

        return Math.abs(sum-target);
    }
}