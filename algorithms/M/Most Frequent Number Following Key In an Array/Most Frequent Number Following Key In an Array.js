/**
 * @param {number[]} nums
 * @param {number} key
 * @return {number}
 */
var mostFrequent = function(nums, key) {
    const obj={} // to keep track the occurances after the key
    let count=0;
    let res=nums[0]
    for(let i=1;i<nums.length;i++){
        if(nums[i-1]===key){
            if(obj[nums[i]]){
                obj[nums[i]]+=1
            }else{
                obj[nums[i]]=1
            }
            if(count<obj[nums[i]]){
                count=obj[nums[i]]
                res=nums[i]
            }
        }
    }
    return res
};
