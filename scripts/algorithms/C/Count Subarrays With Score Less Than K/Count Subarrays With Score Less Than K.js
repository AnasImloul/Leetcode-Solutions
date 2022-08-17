/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var countSubarrays = function(nums, k) 
{
    let count=0;
    let j=0;
    let sum=0;
    for(let i=0;i<nums.length;i++){
        sum+=nums[i];
        while(sum*(i-j+1)>=k){
            sum-=nums[j++];
        }
        count+=(i-j+1);
    }
    return count;
};
