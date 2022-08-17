/**
 * @param {number} n
 * @return {number}
 */
var minimumOneBitOperations = function(n) {
  let answer = 0;
  let op = 1;
  let bits = 30;
  while(bits >= 0) {
    if(n & (1 << bits)) {
      let tmp = (1 << (bits + 1)) - 1;
      answer += tmp * op;
      op *= -1;
    }
    bits--;
  }
  return answer;
}
