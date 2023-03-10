var largestRectangleArea = function (heights) {
    let maxArea = 0;
    let stack = []; // [[index, height]]

    for (let i = 0; i < heights.length; i++) {
        let start = i;
        while (stack.length != 0 && stack[stack.length - 1][1] > heights[i]) {
            let [index, height] = stack.pop();
            maxArea = Math.max(maxArea, height * (i - index));
            start = index;
        }
        stack.push([start, heights[i]]);
    }
    for (let i = 0; i < stack.length; i++) {
        maxArea = Math.max(
            maxArea,
            stack[i][1] * (heights.length - stack[i][0])
        );
    }
    return maxArea;
};