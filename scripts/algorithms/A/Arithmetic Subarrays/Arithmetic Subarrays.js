// Runtime: 84 ms (Top 88.87%) | Memory: 49.20 MB (Top 18.22%)

/**
 * @param {number[]} nums
 * @param {number[]} l
 * @param {number[]} r
 * @return {boolean[]}
 */
var checkArithmeticSubarrays = function(nums, l, r) {
    let result = [];
    for (let i = 0; i < l.length; i++) {
        result.push(isArithmetic(nums.slice(l[i], r[i] + 1)));
    }
    return result;
};

function isArithmetic(arr) {
    let min = Math.min(...arr);
    let max = Math.max(...arr);

    if (min == max) {
        return true;
    }

    let step = (max - min) / (arr.length - 1);

    if (step != Math.floor(step)) {
        return false;
    }

    let set = new Set();
    for (let x of arr) {
        if (set.has(x)) {
            return false;
        }

        set.add(x);
    }

    for (let x = min; x <= max; x += step) {
        if (!set.has(x)) {
            return false;
        }
    }

    return true;
}
