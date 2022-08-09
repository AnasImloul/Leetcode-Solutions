var KthLargest = function(k, nums) {
    // sort ascending because I am familiar with it
    // when applying my binary search algorithm
    this.nums = nums.sort((a,b) => a - b);    
    this.k = k;    
};

KthLargest.prototype.add = function(val) {
    // search a place to push val
    // using binary search
    let left = 0; right = this.nums.length - 1;
    while (left < right) {
        let mid = left + Math.floor((right + 1 - left)/2);
        
        if (val < this.nums[mid]) {
            right = mid - 1;
        } else {
            left = mid
        }
    }    
    
    // push val into the nums
    this.nums.splice(left+(this.nums[left] < val ? 1 : 0), 0, val);  

    // because our nums is sorted
    // so kth largest element is easy to be returned
    return this.nums[this.nums.length-this.k]
};
