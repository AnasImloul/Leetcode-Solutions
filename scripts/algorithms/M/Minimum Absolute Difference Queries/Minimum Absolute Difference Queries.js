var minDifference = function(nums, queries) {
    const qlen   = queries.length, len = nums.length;
    const res    = new Array(qlen).fill(-1);
    const prefix = [];
    
    for(let i = 0; i <= len; i++) {
        if(i == 0) prefix[i] = new Array(101).fill(0);
        else {
            prefix[i] = Array.from(prefix[i-1]);
            prefix[i][nums[i-1]]++;   
        }
    }
    
    for(let k = 0; k < qlen; k++) {
        const [l, r] = queries[k];
        const left = prefix[l], right = prefix[r + 1];
        let prev = -1, ans = Infinity;
        for(let i = 1; i <= 100; i++) {
            const diff = right[i] - left[i];
            if(diff == 0) continue;
            
            if(prev != -1) {
                ans = Math.min(ans, i - prev);
            }
            prev = i;
        }
        if(ans != Infinity) {
            res[k] = ans;
        }
    }
    
    return res;
};
