// Runtime: 167 ms (Top 85.71%) | Memory: 73.90 MB (Top 15.71%)

/**
 * @param {number[]} heights
 * @return {number[]}
 */
var canSeePersonsCount = function(heights) {
    const stack = []
    const answer = new Array(heights.length).fill(0)

    for(let i = 0; i < heights.length; i++) {
        while(stack.length && heights[i] > heights[stack[stack.length - 1]]) {
            answer[stack.pop()]++
        }

        if(stack.length) {
            answer[stack[stack.length - 1]]++
        }

        stack.push(i)
    }

    return answer
};
