var dailyTemperatures = function(temperatures) {
    const len = temperatures.length;
    const res = new Array(len).fill(0);
    const stack = [];
    
    for (let i = 0; i < len; i++) {
        const temp = temperatures[i];
        
        while (temp > (stack[stack.length - 1] || [Infinity])[0]) {
            const [_, j]  = stack.pop();
            res[j] = i - j;
        }
        
        stack.push([temp, i]);
    }
    
    return res;
};

