// Runtime: 102 ms (Top 42.21%) | Memory: 42.3 MB (Top 87.69%)
var findGCD = function(nums) {
    let newNum = [Math.min(...nums) , Math.max(...nums)]
    let firstNum = newNum[0]
    let secondNum = newNum[1]
    while(secondNum) {
    let newNum = secondNum;
    secondNum = firstNum % secondNum;
    firstNum = newNum;
  }
   return firstNum
};