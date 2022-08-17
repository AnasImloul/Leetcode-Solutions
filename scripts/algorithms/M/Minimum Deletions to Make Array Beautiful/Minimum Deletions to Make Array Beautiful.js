var minDeletion = function(nums) {
    const n = nums.length;
    const res = [];
    
    for (let i = 0; i < n; ++i) {
        const num = nums[i];
        
        if (res.length % 2 === 0 || res.at(-1) != num) {
            res.push(num);
        }
    }
    
    if (res.length % 2 === 1) res.pop();
    
    return n - res.length;
};
