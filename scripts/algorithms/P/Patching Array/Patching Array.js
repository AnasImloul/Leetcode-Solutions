// Runtime: 65 ms (Top 100.00%) | Memory: 42.7 MB (Top 47.37%)
// time complexity:
// while loop is - o(n) beacuse we can potentially get to n with nums array full of ones and we will pass on each of them
// in some cases it will hit o(logn) if the nums array is pretty empty
var minPatches = function(nums, n) {
    // nums is sorted so we don't have to sort it
    let index = 0;
    let sumCanCreate = 0;
    let patchCount = 0;
    while(sumCanCreate < n) {
        // if we can't create nums[index] or we at the end of nums and can't create n.
        // we can create nums[index] only if it is lower or equal to sumCanCreate+1.
        if(sumCanCreate+1 < nums[index] || (index >= nums.length && sumCanCreate+1 < n)) {
            patchCount++;
            // because we "patch" the next number in the sequence.
            sumCanCreate += (sumCanCreate+1);
        // if we can create nums[index].
        } else {
            // we can create anything from current sumCanCreate to (sumCanCreate + nums[index]).
            sumCanCreate += nums[index];
            index++;
        }
    }
    return patchCount;
};