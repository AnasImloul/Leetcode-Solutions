// Runtime: 148 ms (Top 52.13%) | Memory: 56 MB (Top 21.28%)
var minCost = function(colors, neededTime) {
    let stack = [], time = 0;
    for (let i = 0; i < colors.length; i++) {
        let skipPush = false;
        while (stack.length && colors[i] === colors[stack[stack.length - 1]]) {
            if (neededTime[i] >= neededTime[stack[stack.length - 1]]) {
                time += neededTime[stack.pop()];
            }
            else if (neededTime[i] < neededTime[stack[stack.length - 1]]) {
                time += neededTime[i];
                skipPush = true;
                break;
            }
        }
        if (!skipPush) stack.push(i);
    }
    return time;
};