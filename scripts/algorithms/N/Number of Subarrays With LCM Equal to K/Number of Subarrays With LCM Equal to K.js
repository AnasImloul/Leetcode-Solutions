// Runtime: 66 ms (Top 80.0%) | Memory: 42.10 MB (Top 50.0%)

/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var subarrayLCM = function(nums, k) {
    let ans = 0;
    for(let i = 0; i < nums.length; i++){
        let lcm = nums[i];
        if(lcm == k) ans++;
        for(var j = i + 1; j < nums.length; j++){
            lcm = LCM(lcm, nums[j]);
            if(lcm == k) ans++;
            if(lcm > k) break;
        }
    }
    return ans;
};

const GCD = function(a, b){
    return a % b == 0 ? b : GCD(b, a % b);
}

const LCM = function(a, b){
    return (a * b) / GCD(a, b);
}
