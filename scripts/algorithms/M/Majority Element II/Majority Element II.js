// Runtime: 105 ms (Top 48.44%) | Memory: 43 MB (Top 93.77%)

/**
 * @param {number[]} nums
 * @return {number[]}
 */
var majorityElement = function(nums) {
    const objElement = {};
    const timesVar = Math.floor(nums.length/3);
    const resultSet = new Set();

    for(var indexI=0; indexI<nums.length; indexI++){
       if(objElement[nums[indexI]]) {
               objElement[nums[indexI]] = objElement[nums[indexI]] + 1;
        }
       else objElement[nums[indexI]] = 1;

       if(objElement[nums[indexI]]>timesVar) resultSet.add(nums[indexI]);
    }

    return [...resultSet];
};