/**
 * @param {number[]} nums
 * @return {number}
 */
var wiggleMaxLength = function(nums) {
    //two pass
    //assume we start with positive or start with negative
    //choose the longest of the two
    return Math.max(helper(nums,true),helper(nums,false))
};

const helper =  (nums, start) =>{
    let l = 0
    let r = 1
    let res = nums.length
    let sign = start
    while(r < nums.length){
        //if sign are what we expected, just flip the sign
        if((sign && nums[r] > nums[l]) || (!sign && nums[r] < nums[l])){
            sign = !sign
        }
        //if sign aren't what we expected then we "remove" one
        //if we want positive then we remove the bigger number to give us a better chance of getting positive
        //if we want negative we remove the smaller number go give us a chance of getting a negative
        // want negative but nums[r] - nums[l] = positive   => remove nums[l] 
        // want positive but nums[r] - nums[l] = negative   => remove nums[l]
        //it just so happens that the number we want to remove will always be nums[l], so we don't have to do anything special
        else{
            res--
        }
        l++
        r++
    }
    return res
}
