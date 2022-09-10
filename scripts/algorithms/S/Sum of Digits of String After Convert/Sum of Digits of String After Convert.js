// Runtime: 52 ms (Top 100.00%) | Memory: 44.2 MB (Top 53.23%)
/**
 * @param {string} s
 * @param {number} k
 * @return {number}
 */
var getLucky = function(s, k) {
    function alphabetPosition(text) {
      var result = [];
      for (var i = 0; i < text.length; i++) {
        var code = text.toUpperCase().charCodeAt(i)
        if (code > 64 && code < 91) result.push(code - 64);
      }
      return result;
    }

    let str = alphabetPosition(s).join("");
    let sum = 0;
    let newArr;

    while(k>0){
        newArr = str.split("");
        sum = newArr.reduce((acc, e) => parseInt(acc)+parseInt(e));
        str = sum.toString();
        k--;
    }
    return sum

};