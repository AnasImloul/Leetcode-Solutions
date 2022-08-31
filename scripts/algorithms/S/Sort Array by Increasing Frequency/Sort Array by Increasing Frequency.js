// Runtime: 84 ms (Top 90.67%) | Memory: 44.9 MB (Top 27.33%)
var frequencySort = function(nums) {
  const map = new Map()
  for(let n of nums){
    map.set(n, (map.get(n) || 0)+1)
  }
  return nums.sort((a,b)=>{
    if(map.get(a) === map.get(b)){
      return b-a
    }else{
      return map.get(a) - map.get(b)
    }
  })
};