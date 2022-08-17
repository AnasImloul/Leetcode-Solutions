var sumOfUnique = function(nums) {
  let obj = {}
  let sum = 0
  // count frequency of each number
  for(let num of nums){
    if(obj[num] === undefined){
      sum += num
      obj[num] = 1
    }else if(obj[num] === 1){
      sum -= num
      obj[num] = -1
    }
  }
  
  return sum
};
