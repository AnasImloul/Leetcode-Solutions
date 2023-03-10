var countHomogenous = function(s) {
    let mod = 1e9 + 7
    let n = s.length
    let j=0, res = 0
    
    for(let i=0; i<n; i++){
        if(i>0 && s[i-1] != s[i]){
            let x = i-j
            res += x*(x+1) / 2
            j = i
        }
    }
    
    let x = n-j
    res += x*(x+1) / 2

    return res%mod
};