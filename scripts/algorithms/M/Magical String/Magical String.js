// Runtime: 167 ms (Top 9.09%) | Memory: 53.9 MB (Top 27.27%)
var magicalString = function(n) {
    const stack = ['1', '2', '2'];
    let magic = 2;

    while (stack.length < n) {
        const count = stack[magic++];
        const last = stack[stack.length - 1];
        const addStr = last === '1' ? '2' : '1';

        for (let n = 1; n <= count; n++) stack.push(addStr);
    }
    return stack.slice(0, n).filter(str => str === '1').length;
};