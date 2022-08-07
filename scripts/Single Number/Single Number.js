var singleNumber = function(nums) {
    let s = 0; // Location of first possible suspect
    for (let i = s + 1; i < nums.length; i++) {
        if (nums[i] == nums[s]) { // If we found a duplicate
            nums.splice(i, 1); // Remove duplicate so it won't confuse us next time we come across it
            s++; // Next suspect's location
            i = s; // Start of next search (i=s+1 in next loop iteration)
        }
    }
    return nums[s];
};
