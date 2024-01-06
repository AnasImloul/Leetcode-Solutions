// Runtime: 330 ms (Top 100.0%) | Memory: 69.50 MB (Top 100.0%)

/**
 * @param {number} n
 * @param {number[]} sums
 * @return {number[]}
 */
var recoverArray = function(n, sums) {
    sums.sort((a, b) => a - b);
    let result = [];
    
    while (sums.length > 1) {
        let num = sums[sums.length - 1] - sums[sums.length - 2],
            excluding = [],
            including = [],
            counter = new Map();
        for (let item of sums) {
            let count = counter.get(item);
            if (count) {
                counter.set(item, count + 1);
            } else {
                counter.set(item, 1);
            }
        }
        
        for (let item of sums) {
            if (counter.get(item) > 0) {
                excluding.push(item);
                including.push(item + num);
                counter.set(item, counter.get(item) - 1);
                counter.set(item + num, counter.get(item + num) - 1);
            }
        }
        
        if (excluding.indexOf(0) !== -1) {
            sums = excluding;
            result.push(num);
        } else {
            sums = including;
            result.push(-1 * num);
        }
    }
    
    return result;
};
