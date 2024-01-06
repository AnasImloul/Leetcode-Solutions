// Runtime: 47 ms (Top 78.6%) | Memory: 41.90 MB (Top 55.1%)

// Runtime: 46 ms, faster than 86.21% of JavaScript online submissions for Summary Ranges.
// Time Complexity : O(N)
// Space Complexity : O(1)
var summaryRanges = function(nums) {
    // Create a list of string to store the output result...
    const output = [];
    // Start traversing the array from idx = 0 till idx < sizeofarray in a while loop.
    let idx = 0;
    while(idx < nums.length) {
        // Initialize beg and last index for identifying the continuous element in the array...
        let beg, last;
        // Mark the number at current index as beginning element of the range...
        beg = nums[idx];
        // Traverse the array beggining from current index & find the last element whose difference from previous element is exactly 1, i.e. nums[idx + 1] == nums[idx] + 1...
        while(idx+1 < nums.length && nums[idx+1] == nums[idx] + 1) 
            idx++;
        // Set this element as last element of the range...
        last = nums[idx];
        // If continuous element isn't present...
        if(beg == last)
            output.push(beg + "");
        // If present...
        else
            output.push( beg + "->" + last );
        idx++;          
    }
    return output;      // Return the output result list...
};
