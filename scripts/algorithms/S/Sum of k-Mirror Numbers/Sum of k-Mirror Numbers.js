// Runtime: 1958 ms (Top 50.0%) | Memory: 73.90 MB (Top 50.0%)

/**
 * @param {number} k
 * @param {number} n
 * @return {number}
 */
const convert = (numList, base, degree) => {
  let newNum = 0
  for(let i = numList.length-1; i > 0; i--){
    newNum += numList[i]*(base**(numList.length-i-1)) + numList[i]*(base**(degree - (numList.length-i)))
  }
  if(degree % 2 === 0){
    newNum += numList[0]*(base**(Math.ceil(degree/2)))
  }
  newNum += numList[0]*(base**(Math.ceil(degree/2) - 1))
  return newNum
}
const isMirror = (num) => {
  num = num.toString()
  for(let i = 0; i < Math.floor(num.length/2); i++){
    if(num[i] !== num[num.length-1-i])return false
  }
  return true
}
var kMirror = function(k, n) {
  let degree = 1
  let sum = 0
  const list = [1]
  const generateNewNum = () => {
    list[0]++
    for(let i = 0; i < list.length; i++){
      if(list[i] !== k)break
      else {
        list[i] = 0
        if(i+1 < list.length){
          list[i+1] += 1
        }else{
          if(degree % 2){
            list[i] =  1
          }else{
            list[i+1] = 1
          }
          degree++
        }
      }
    }
  }
  while(n > 0){
    const num = convert(list, k, degree)
    if(isMirror(num)){
      sum += num
      n--
    }
    generateNewNum()
  }
  return sum
};
