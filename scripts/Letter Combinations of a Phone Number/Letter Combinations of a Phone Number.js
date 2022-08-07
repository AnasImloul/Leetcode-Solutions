var letterCombinations = function(digits) {
  if(!digits) return []
  let res = []
  const alpha = {
    2: "abc",
    3: "def",
    4: "ghi",
    5: "jkl",
    6: "mno",
    7: "pqrs",
    8: "tuv",
    9: "wxyz"
  }
  
  const dfs = (i, digits, temp)=>{
    if(i === digits.length){
      res.push(temp.join(''))
      return
    }
    
    let chars = alpha[digits[i]]
    for(let ele of chars){
      temp.push(ele)
      dfs(i+1, digits, temp)
      temp.pop()
    }
  }
  dfs(0, digits, [])
  return res
};
