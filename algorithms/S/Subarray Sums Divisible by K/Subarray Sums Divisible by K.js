var subarraysDivByK = function(nums, k) {
    let count = 0;
    let map = new Map();
    map.set(0, 1)
    let sum = 0;
    for(let i=0; i<nums.length; i++){
        sum += nums[i];
        let rem = sum%k;
        if(rem<0) rem += k;
        if(map.has(rem)){
            count += map.get(rem)
            map.set(rem, map.get(rem)+1)
        }else{
            map.set(rem, 1)
        }
    }
    return count
};
