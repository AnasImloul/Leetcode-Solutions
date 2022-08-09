var maxSubsequence = function(nums, k) {
    return nums.map((v,i)=>[v,i]).sort((a,b)=>a[0]-b[0]).slice(-k).sort((a,b)=>a[1]-b[1]).map(x=>x[0]);
};
