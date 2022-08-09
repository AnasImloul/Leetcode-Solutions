class Solution {
    public int shipWithinDays(int[] weights, int days) {
        int left = 0;
        int right = 0;
        //  left is the biggest element in the array. It's set as the lower boundary.
        //  right is the sum of the array, which is the upper limit. 
        for (int weight : weights) {
            left = Math.max(weight, left);
            right += weight;
        }
        int res = 0;
        while (left <= right) {
            int mid = (left + right) / 2;
            // make sure mid is a possible value 
            if (isPossible(weights, days, mid)) {
                res = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return res;
    }
    
    public boolean isPossible(int [] weights, int days, int mid) {
        int totalDays = 1;
        int totalWeight = 0;
        for (int i = 0; i < weights.length; i++) {
            totalWeight += weights[i];
            // increase totalDays if totalWeight is larger than mid
            if (totalWeight > mid) {
                totalDays++;
                totalWeight = weights[i]; 
            } 
            // the problem states all the packages have to ship within `days` days 
            if (totalDays > days) {
                return false;
            }
        }
        return true;
    }
    
}
