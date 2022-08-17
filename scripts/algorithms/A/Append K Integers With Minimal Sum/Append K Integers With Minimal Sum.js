var minimalKSum = function(nums, k) {
  let total = (k*(k+1))/2;
    
  nums = Array.from(new Set(nums));
  nums.sort((a,b)=>a-b); 
  for (let num of nums) {
    if (num<=k) {
      k++;
      console.log(total-1)
      total=total-num+k;
      console.log(total+1)
    }
    else
      break;
  }
  return total;
}
