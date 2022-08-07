var isPowerOfFour = function(n) {
    if(n==1){
        return true
    }
    let a=1;
    for(let i=2;i<=30;i++){
        a=a*4
        if(a===n){
            return true
        }
    }
    return false
};
