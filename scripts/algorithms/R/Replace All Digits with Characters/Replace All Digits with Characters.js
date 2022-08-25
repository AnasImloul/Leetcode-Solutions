// Runtime: 78 ms (Top 73.93%) | Memory: 42.3 MB (Top 48.93%)
var replaceDigits = function(s) {
    let res = ''
    for(let i = 0; i < s.length; i++){
        if(i % 2 !== 0){
          res += String.fromCharCode(s[i - 1].charCodeAt() + parseInt(s[i]))
        } else{
            res += s[i]
        }

    }
    return res;
};