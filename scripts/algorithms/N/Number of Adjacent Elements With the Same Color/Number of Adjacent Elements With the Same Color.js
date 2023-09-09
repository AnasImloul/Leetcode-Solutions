// Runtime: 258 ms (Top 81.8%) | Memory: 107.46 MB (Top 54.5%)

/**
 * @param {number} n
 * @param {number[][]} queries
 * @return {number[]}
 */
var colorTheArray = function(n, queries) {
    const nums = Array(n).fill(0);
    let count = 0;
    const res = [];
    
    for (const [index, color] of queries) {
        if (nums[index] === color) {
            res.push(count);
            
            continue;
        }    
        
        // change previous color on `index` position
        const old = nums[index];
        
        if (old !== 0) {
            let reduce = 0;

            if (index > 0 && nums[index - 1] === old) {
                reduce += 1;
            }

            if (index < nums.length - 1 && nums[index + 1] === old) {
                reduce += 1;
            }

            count -= reduce;
        }
        
        // update new color on `index` position
        nums[index] = color;
        let add = 0;
        
        if (index > 0 && nums[index - 1] === color) {
            add += 1;
        }
        
        if (index < nums.length - 1 && nums[index + 1] === color) {
            add += 1;
        }
        
        count += add;
        
        res.push(count);
    }
    
    return res;
};