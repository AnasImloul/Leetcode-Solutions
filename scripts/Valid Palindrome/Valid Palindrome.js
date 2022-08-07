var isPalindrome = function(s) {
  const toLower = s.toLowerCase().replace(/[\W_\s]+/g, '').replace(/ /g, '')
  let m = 0
  let n = toLower.length - 1

  while (m < n) {
    if (toLower[m] !== toLower[n]) {
      return false
    }
    m++
    n--
  }
  return true
}
