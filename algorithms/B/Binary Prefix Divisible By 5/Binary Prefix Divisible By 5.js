/**
 * @param {number[]} nums
 * @return {boolean[]}
 */
var prefixesDivBy5 = function(nums) {
    const answer = new Array(nums.length).fill(false)
    let cur = 0
    for (let i = 0; i < nums.length; i++) {
        cur = cur * 2 + nums[i]
        if (cur % 5 === 0) 
            answer[i] = true
        cur %= 5
    }
    
    return answer
};

