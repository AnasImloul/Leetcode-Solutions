class Solution {
    public boolean canSplit(int[] candies, long k, long mid) {
        long split = 0;
        for(int i = 0; i < candies.length; ++i) {
            split += candies[i]/mid;
        }   
        if(split >= k)
            return true;
        else
            return false;
    }
    
    public int maximumCandies(int[] candies, long k) {
        long sum = 0;
        for(int i = 0; i < candies.length; ++i) {
            sum += candies[i];
        }
        long start = 1, end = sum;
        long ans = 0;
        while(start <= end) {
            long mid = (start + end)/2;
            if(canSplit(candies, k, mid)) {
                ans = mid;
                start = mid + 1;
            } else {
                end = mid-1;
            }
        }
        return (int)ans;
    }
}
