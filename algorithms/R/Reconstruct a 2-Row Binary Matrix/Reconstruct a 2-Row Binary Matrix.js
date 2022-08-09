/**
 * @param {number} upper
 * @param {number} lower
 * @param {number[]} colsum
 * @return {number[][]}
 */
var reconstructMatrix = function(upper, lower, colsum){
    let dp = new Array(2)
   for(let i  = 0; i< dp.length; i++){
      dp[i] = new Array(colsum.length)
  }
  let first = upper
  let second = lower
    let upsum = 0
    let losum=  0
    
     for(let i = 0; i<  colsum.length; i++){
         if(colsum[i] === 2){
             dp[0][i] = 1
             dp[1][i] = 1
             upsum++
             losum++
         }
         else if(colsum[i] === 1){
             if(lower < upper){
                 dp[0][i] =1
                 dp[1][i] = 0
                 upper--
                 upsum++
             }
             else{
                 dp[0][i] = 0
                 dp[1][i] = 1
                 lower--
                 losum++
             }
         }
         else if(colsum[i] === 0){
             dp[0][i]  = 0
             dp[1][i] = 0
         }
         else{
             return []
         }
     }
     if(losum !== second || upsum !== first) return []
 return dp
}