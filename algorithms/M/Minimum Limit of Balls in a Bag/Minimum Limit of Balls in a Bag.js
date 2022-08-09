var minimumSize = function(nums, maxOperations) {
  let i = 1
  let j = Math.max(...nums)
  
  while (i <= j) {
    let mid = Math.floor((j-i)/2 + i)
    let count = 0
    nums.forEach(n => count += Math.floor((n-1)/mid))
    
    if (count <= maxOperations) {
      j = mid - 1
    } else {
      i = mid + 1
    }
  }
  return i
};
