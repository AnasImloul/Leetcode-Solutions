var longestSubarray = function(nums) {
    let l = 0, r = 0;
    let longest = 0;
    // Keep track of the idx where the last zero was seen
    let zeroIdx = null;
    while (r < nums.length) {
        // If we encounter a zero
        if (nums[r] === 0) {
            // If this is the first zero encountered, then set the zeroIdx to the current r index
            if (zeroIdx === null) zeroIdx = r;
            else {
                // If we've already encountered a zero, then set the l index to the zeroIdx + 1,
				// effectively removing that zero from the subarray
                l = zeroIdx + 1;
                // Then update the zeroIdx to the current r index
                // This way there will be, at most, one zero in the subarray at all times
                zeroIdx = r;
            }
        }
        longest = Math.max(longest, r - l);
        r++;
    }
    return longest;
};
