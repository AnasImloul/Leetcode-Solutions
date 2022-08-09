/**
 * @param {number[]} nums
 * @param {number} key
 * @param {number} k
 * @return {number[]}
 */
var findKDistantIndices = function(nums, key, k) {
    
    let ind = [];
    let ans = [];
    
    nums.forEach((val, i) => {
       if (val == key) {
           ind.push(i);
       } 
    });
    
    let temp = new Set();
    for (let i = 0; i < ind.length; i++) {
        let mn = Math.max(ind[i]-k, 0);
        let mx = Math.min(Math.abs(ind[i]+k), nums.length-1);
    
        for (let j = mn; j <= mx; j++) {
            temp.add(j);
        } 
    }
    
    return [...temp];
};
