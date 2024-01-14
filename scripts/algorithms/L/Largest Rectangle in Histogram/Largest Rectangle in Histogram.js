// Runtime: 79 ms (Top 90.82%) | Memory: 54.50 MB (Top 69.89%)

var largestRectangleArea = function(heights) {
    const n = heights.length;
    const nsr = new Array(n).fill(0);
    const nsl = new Array(n).fill(0);

    const stack = [];
        
    for (let i = n - 1; i >= 0; i--) {
        while (stack.length !== 0 && heights[i] <= heights[stack[stack.length - 1]]) {
                stack.pop();
        }
        if (stack.length === 0) {
            nsr[i] = n;
        } else {
            nsr[i] = stack[stack.length - 1];
        }
        stack.push(i);
    }

    while (stack.length !== 0) {
        stack.pop();
    }

    for (let i = 0; i < n; i++) {
        while (stack.length !== 0 && heights[i] <= heights[stack[stack.length - 1]]) {
            stack.pop();
        }
        if (stack.length === 0) {
            nsl[i] = -1;
        } else {
             nsl[i] = stack[stack.length - 1];
        }
        stack.push(i);
    }

    let ans = 0;

    for (let i = 0; i < n; i++) {
        ans = Math.max(ans, heights[i] * (nsr[i] - nsl[i] - 1));
    }
   
    return ans;
};
