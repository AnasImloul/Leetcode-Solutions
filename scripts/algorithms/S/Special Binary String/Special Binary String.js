// Runtime: 111 ms (Top 16.6%) | Memory: 50.12 MB (Top 33.3%)

/**
 * @param {string} S
 * @return {string}
 */
var makeLargestSpecial = function (S) {
  let t = S
  while (true) {
    let t1 = largest(t)
    if (t1 == t) return t
    t = t1
  }
  function largest(S) {
    let arr = S.split('').map(x => Number.parseInt(x)),
      num = Number.parseInt(S, 2), rtn = S
    for (let firstEndIndex = 1; firstEndIndex < S.length - 2; firstEndIndex++) {
      for (let lLength = 2; lLength < firstEndIndex + 2; lLength += 2) {
        let firstStartIndex = firstEndIndex - lLength + 1
        if (!isSpecial(firstStartIndex, firstEndIndex)) continue
        for (let rLength = 2; rLength < S.length - firstEndIndex; rLength += 2) {
          let secondStartIndex = firstEndIndex + 1, secondEndIndex = firstEndIndex + rLength
          if (!isSpecial(secondStartIndex, secondEndIndex)) continue
          let str = [...arr.slice(0, firstStartIndex),
          ...arr.slice(secondStartIndex, secondEndIndex + 1),
          ...arr.slice(firstStartIndex, firstEndIndex + 1),
          ...arr.slice(secondEndIndex + 1)].join('')
          let newNum = Number.parseInt(str, 2)
          if (newNum > num) {
            num = newNum
            rtn = str
          }
        }
      }
    }
    return rtn

    function isSpecial(start, end) {
      let t = 0
      for (let i = start; i <= end; i++) {
        t += arr[i] == 1 ? 1 : -1
        if (t < 0) return false // this is the second rule, really bad description
      }
      return t == 0 ? true : false
    }
  }

};

// console.log(makeLargestSpecial("101101011000"))