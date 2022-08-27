// Runtime: 181 ms (Top 72.22%) | Memory: 63.8 MB (Top 94.44%)
var minSubarray = function(nums, p) {
    let n = nums.length;
    let map = new Map([[0,-1]])
    let total = 0, res = n, sum = 0
    for(let i=0; i<n; i++){
        total += nums[i]
    }
    total = total % p

    for(let i=0; i<n; i++){
        sum = (sum + nums[i]) % p
        map.set(sum, i)
        let prevSum = mod(sum-total,p)
        if(map.has(prevSum)){
            res = Math.min(res, i-map.get(prevSum))
        }
    }

    return res == nums.length ? -1 : res
};

function mod(a,b){
    let c = a%b
    return c<0 ? c+b : c
}