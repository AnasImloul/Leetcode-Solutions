var circularArrayLoop = function(nums) {
    // cannot be a cycle if there are less than 2 elements
    const numsLen = nums.length;
    if (numsLen < 2) return false;

    // init visited array
    const visited = Array(numsLen).fill(false);

    // check each index to see if a cycle can be produced
    for (let i = 0; i < numsLen; i++) {
        if (visited[i]) continue;
        visited[i] = true;
        // determine initial direction
        const isPositive = nums[i] > 0;
        
        // reset which indices were visited after each iteration
        const visitedPerIdx = Array(numsLen).fill(false);
        
        // reset cycle length and current index after each iteration
        let cycleLen = 0,
            currIdx = i;
        
        // loop while cycle is valid
        while (true) {
            // break if current index moves cycle in opposite direction
            if (isPositive !== nums[currIdx] > 0) break;
			
            // calc next valid index
            let nextIdx = (currIdx + nums[currIdx]) % numsLen;
            // map negative index to a positive index
            if (nextIdx < 0) nextIdx += numsLen; 
          
            // break if cycle points to same index
            if (currIdx === nextIdx) break;
            
            cycleLen++; 
			// a cycle is found when the index has already been visited in the current outer iteration, and
			// the cycle length is greater than 1.
            if (visitedPerIdx[nextIdx] && cycleLen > 1) return true;
			
            visitedPerIdx[nextIdx] = true;
            visited[nextIdx] = true;
            // set curr index to new index
            currIdx = nextIdx;
        }
    }

    return false;
};

