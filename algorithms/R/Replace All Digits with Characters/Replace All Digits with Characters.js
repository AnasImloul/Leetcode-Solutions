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
