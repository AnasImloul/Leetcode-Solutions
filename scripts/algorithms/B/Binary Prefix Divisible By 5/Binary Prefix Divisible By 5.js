// Runtime: 59 ms (Top 81.36%) | Memory: 45.80 MB (Top 89.83%)

var prefixesDivBy5 = function(nums) {
   let res = [];
   let binary = 0;
   for(let num of nums){
       binary = (binary % 5) * 2 + num;
       let checkBinary = (binary % 5 === 0);
       res.push(checkBinary);
   }    
   return res;
};
