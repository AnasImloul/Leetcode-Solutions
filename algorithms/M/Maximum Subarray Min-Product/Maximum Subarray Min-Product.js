var maxSumMinProduct = function(nums) {
    var mod = BigInt(1000000007);
    var n = nums.length;
    var max = 0n;
    if(n === 1)
    {
        return (nums[0]*nums[0]) % mod;
    }
    var sum = new Array(n+1).fill(0);
    for(var i = 1; i<=n; i++)
    {
        sum[i] = sum[i-1] + nums[i-1];
    }
    for(var i = 0;i<n; i++)
    {
        var l = i-1;
        var r = i+1;
        while(l>=0 && nums[l]>=nums[i])
        {
            l--;
        }
        l++;
        while(r<n && nums[r]>=nums[i])
        {
            r++;
        }
        r--;
        var s = BigInt(sum[r+1] - sum[l]);
        var factor = BigInt(nums[i]);
        var prod = s*factor;
        if(prod > max)
        {
            max = prod;
        }
    }
    return Number(max % mod); 
};
