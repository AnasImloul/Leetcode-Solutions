class Solution {
    constructor(nums) {
        this.map = new Map();
        this.sum = 0;
        
        nums.forEach((num, i) => {
            this.sum += num;
            this.map.set(this.sum, i);
        })
    }
    pickIndex = function() {
        const random_sum = Math.floor(Math.random() * this.sum);
        return this.fetchIndexUsingBS(random_sum);
    }
    fetchIndexUsingBS = function(target) {
        const sums = Array.from(this.map.keys());
        let lo = 0,
            hi = sums.length - 1,
            mid;
        
        while(lo <= hi) {
            mid = Math.floor((hi - lo)/2) + lo;
            // if((mid === 0 || sums[mid - 1] < target) && sums[mid] >= target) {
            //     return this.map.get(sums[mid]);
            // }
            if(sums[mid] > target) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return lo;
    }
}