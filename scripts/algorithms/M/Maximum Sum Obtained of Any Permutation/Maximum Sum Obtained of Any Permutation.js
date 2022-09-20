// Runtime: 10496 ms (Top 8.00%) | Memory: 79.4 MB (Top 56.00%)
/**
 * @param {number[]} nums
 * @param {number[][]} requests
 * @return {number}
 */
var maxSumRangeQuery = function(nums, requests) {
    let frequency = new Array(nums.length).fill(0)
    for(let req of requests){
        for(let i=req[0];i<=req[1];i++){
            frequency[i]++
        }
    }
    nums = nums.sort((a,b)=>a-b)
    let freqArr = frequency.sort((a,b)=>b-a)
    let sum =0
    for(let freq of freqArr){
        sum += (freq * nums.pop())
    }
    const mod = (10 ** 9) + 7;
    return sum%mod
};