var containsDuplicate = function(nums) {
    if(nums.length <= 1) return false;
    let cache = {};
    let mid = Math.floor(nums.length /2)
    let left = mid -1;
    let right  = mid;
    while(left >= 0 || right < nums.length) {
        if(nums[left] === nums[right]) {
            return true;
        };
        if(cache[nums[left]]){
            return true
        } else {
            cache[nums[left]] = true; 
        }
        if(cache[nums[right]]){
            return true;
        } else{
            cache[nums[right]] = true;
        }
        left--;
        right++;
    }
    return false;
};
