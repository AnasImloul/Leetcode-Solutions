var rearrangeArray = function(nums) {
   let result = Array(nums.length).fill(0);
    let posIdx = 0, negIdx = 1;
   for(let i=0;i<nums.length;i++) {
       if(nums[i]>0) {
           result[posIdx] = nums[i]
           posIdx +=2;
       } else {
            result[negIdx] = nums[i]
           negIdx +=2;
       }
   }
    return result;
 };

