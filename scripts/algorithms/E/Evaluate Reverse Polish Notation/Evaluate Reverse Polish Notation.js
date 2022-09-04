// Runtime: 74 ms (Top 94.68%) | Memory: 44 MB (Top 93.79%)
const ops = new Set(['+', '-', '*', '/']);

/**
 * @param {string[]} tokens
 * @return {number}
 */
var evalRPN = function(tokens) {
    const stack = [];

    for (const token of tokens) {
        if (!ops.has(token)) {
            stack.push(Number(token));
            continue;
        }

        const val1 = stack.pop();
        const val2 = stack.pop();
        let toPush;

        if (token === '+') {
            toPush = val1 + val2;
        }

        if (token === '-') {
            toPush = val2 - val1;
        }

        if (token === '*') {
            toPush = val1 * val2;
        }

        if (token === '/') {
            toPush = Math.trunc(val2 / val1);
        }

        stack.push(toPush);
    }

    return stack[0] || 0;
};
