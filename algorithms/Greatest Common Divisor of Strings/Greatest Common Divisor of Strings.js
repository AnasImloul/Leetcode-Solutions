/**
 * @param {string} str1
 * @param {string} str2
 * @return {string}
 */
var gcdOfStrings = function(str1, str2) {
  const gcdOfNumber = (num1, num2) => {
    while (num2 !== 0) {
      const res = num2 % num1
      num1 = num2
      num2 = res
    }
    return num1
  }
  const gcd = gcdOfNumber(str1.length, str2.length)
  const common = str1.slice(0, gcd)
  return common.repeat(str1.length / gcd) === str1 &&
    common.repeat(str2.length / gcd) === str2
    ? common
    : ''
}
