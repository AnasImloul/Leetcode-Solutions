class Solution {
    public int maxTurbulenceSize(int[] arr) {
        if(arr.length == 1) {
            return 1;
        } 
        int l = 0, r = 1;
        int diff = arr[l] - arr[r];
        int max;
        if(diff == 0) {
            l = 1;
            r = 1;
            max = 1;
        } else {
            l = 0;
            r = 1;
            max = 2;
        }
        for(int i = 1; r < arr.length-1; i++) {
            int nextdiff = arr[i] - arr[i+1];
            if(diff < 0) {
                if(nextdiff > 0) {
                    r++;
                } else if(nextdiff == 0) {
                    l = i+1;
                    r = i+1;
                } else {
                    l = i;
                    r = i+1;
                }
            } else {
                if(nextdiff < 0) {
                    r++;
                } else if(nextdiff == 0) {
                    l = i+1;
                    r = i+1;
                } else {
                    l = i;
                    r = i+1;
                }
            }
            diff = nextdiff;
            max = Math.max(max, r-l+1);
        }
        return max;
    }
}
