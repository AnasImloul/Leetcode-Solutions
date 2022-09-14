// Runtime: 172 ms (Top 24.83%) | Memory: 57.7 MB (Top 11.96%)
var removeDuplicates = function(s, k) {
  const stack = []
  for(const c of s){
    const obj = {count: 1, char: c}
    if(!stack.length){
      stack.push(obj)
      continue
    }
    const top = stack[stack.length-1]
    if(top.char === obj.char && obj.count + top.count === k){
      let count = k
      while(count > 1){
        stack.pop()
        count--
      }
    }else if(top.char === obj.char){
      obj.count+=top.count
      stack.push(obj)
    }else{
      stack.push(obj)
    }
  }
  return stack.reduce((a,b)=> a+b.char, '')
};