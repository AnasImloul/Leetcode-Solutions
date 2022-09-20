// Runtime: 76 ms (Top 58.82%) | Memory: 42 MB (Top 61.76%)
var decodeAtIndex = function(s, k) {
    let len=0;
    let isDigit=false

    for(let v of s){
        if(v>='0'&&v<='9'){
            len*=+v
            isDigit=true
        }else{
            len++
            if(len===k&&!isDigit){
                return s[k-1]
            }
        }
    }

    for(let i=s.length-1;i>=0;i--){
        const v=s[i]
        if(v>='0'&&v<='9'){
            len=Math.ceil(len/+v) // Math.floor() wont work because we endup leaving few strings
            k%=len
        }else{
            if(k===0||k===len){
                    return v
               }
            len--
        }
    }
};