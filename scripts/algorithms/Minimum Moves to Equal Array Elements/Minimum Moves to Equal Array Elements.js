var minMoves = function(nums) {
    let minElm = Math.min(...nums);
    let ans = 0;
    for(let i=0; i<nums.length; i++){
        ans += (nums[i]-minElm)
    }
    return ans
};
