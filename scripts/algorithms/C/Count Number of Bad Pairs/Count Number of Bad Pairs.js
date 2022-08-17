/**
 * @param {number[]} nums
 * @return {number}
 */
var countBadPairs = function(nums) {
    let map={},goodPair=0;
    for(let i=0;i<nums.length;i++){
        let value = nums[i]-i;
        if(map[value]!==undefined){
            goodPair += map[value];
            map[value]++;
        }else{
            map[value]=1;
        }
    }
    let n =  nums.length; 
    let totalPairs = n*(n-1)/2;
    return totalPairs-goodPair;
};
