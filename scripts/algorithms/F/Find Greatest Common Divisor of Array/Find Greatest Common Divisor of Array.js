var findGCD = function(nums) {
    let newNum =  [Math.min(...nums) , Math.max(...nums)]
    let firstNum = newNum[0]
    let secondNum = newNum[1]
    while(secondNum) {
    let newNum = secondNum;
    secondNum = firstNum % secondNum;
    firstNum = newNum;
  }
   return firstNum
};
