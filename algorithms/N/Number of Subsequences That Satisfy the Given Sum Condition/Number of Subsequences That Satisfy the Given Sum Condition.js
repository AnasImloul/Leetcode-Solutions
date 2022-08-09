const MOD = 1000000007;

var numSubseq = function(nums, target) {
    nums.sort((a, b) => a - b);
    const len = nums.length;
    const pow = new Array(len).fill(1);
    for(let i = 1; i < len; i++) {
        pow[i] = (pow[i - 1] * 2) % MOD;
    }
    let l = 0, r = len - 1, ans = 0;
    while(l <= r) {
        if(nums[l] + nums[r] > target) {
            r--; continue;
        } else {
            ans = (ans + pow[r - l]) % MOD;
            l++;
        }
    }
    return ans % MOD;
};
