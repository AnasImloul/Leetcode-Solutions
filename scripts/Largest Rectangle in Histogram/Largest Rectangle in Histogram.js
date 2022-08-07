var largestRectangleArea = function(heights) {
    const n = heights.length;

    const getLeftBoundaries = () => {
        const leftBoundaries = []
        const stack = [];
        for(let i = 0; i < n; i += 1) {
            const height = heights[i];
            while(stack.length > 0 && heights[stack[stack.length - 1]] >= heights[i]) {
                stack.pop();
            }

            leftBoundaries.push(stack.length === 0 ? -1 : stack[stack.length - 1]);
            stack.push(i);
        }
        return leftBoundaries;
    };

    const getRightBoundaries = () => {
        const rightBoundaries = []
        const stack = [];
        for(let i = n - 1; i >= 0; i -= 1) {
            const height = heights[i];
            while(stack.length > 0 && heights[stack[stack.length - 1]] >= heights[i]) {
                stack.pop();
            }

            rightBoundaries.push(stack.length === 0 ? n : stack[stack.length - 1]);
            stack.push(i);
        }
        return rightBoundaries.reverse();
    };

    const leftBoundaries = getLeftBoundaries();
    const rightBoundaries = getRightBoundaries();

    let max = 0;
    for(let i = 0; i < n; i += 1) {
        const height = heights[i];
        const width = rightBoundaries[i] - leftBoundaries[i] - 1;
        max = Math.max(max, width * height);
    }

    return max;
};
