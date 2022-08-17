var maxDistance = function(colors) {
    // using two pointers from start and end
    // Time complexity O(n)
    // Space complexity O(1)
    
    const start = 0;
    const end = colors.length - 1;

    // maximum distance possible is length of arr, so start with two pointer
	// one at the start and one at the end
    const startColor = colors[start];
    const endColor = colors[end];
    
	// base condition, to check if they are not already equal
    if (startColor !== endColor) {
        return end;
    }
    
	// move the forward pointer till we find the differend color
    let forwardPtr = start;
    while (startColor === colors[forwardPtr]) {
        ++forwardPtr;
    }
    
    // move the backward pointer till we find the differend color
    let backwardPtr = end;
    while(endColor === colors[backwardPtr]) {
        --backwardPtr;
    }
    
    // Till here, We already know that startColor === endColor
    // hence we did two things,
 	// 1. we kept startColor fixed and moved backwardPtr till we find different color
    // 2. similarly, we kept endColor fixed and moved the forwardPtr till we find the different color.
   // we will return the max different out of two now.
    return Math.max(Math.abs(start - backwardPtr), Math.abs(end - forwardPtr));
    
};
