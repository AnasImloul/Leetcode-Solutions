class Solution {
    public int[] maximumBeauty(int[][] items, int[] queries) {
        int[] ans = new int[queries.length];
        Arrays.sort(items, (a, b) -> (a[0] - b[0]));
        int maxBeautySoFar = Integer.MIN_VALUE;
        int[] maxBeauty = new int[items.length];
        
        for(int i = 0; i < items.length; i++) {
            if(maxBeautySoFar < items[i][1]) maxBeautySoFar = items[i][1];
            maxBeauty[i] = maxBeautySoFar;
        }
        
        for(int i = 0; i < queries.length; i++) {
            int idx = findLargestIdxWithPriceLessThan(items, queries[i]);
            if(idx != Integer.MIN_VALUE) ans[i] = maxBeauty[idx];
        }
        return ans;
    }
    
    public int findLargestIdxWithPriceLessThan(int[][] items, int price) {
        int l = 0;
        int r = items.length - 1;
        int maxIdxLessThanEqualToPrice = Integer.MIN_VALUE; 
        while(l <= r) {
            int mid = (l + r)/2;
            if(items[mid][0] > price) {
                r = mid - 1;
            } else {
                maxIdxLessThanEqualToPrice = Math.max(maxIdxLessThanEqualToPrice, mid);
                l = mid + 1;
            }
        }
        return maxIdxLessThanEqualToPrice;
    }
}