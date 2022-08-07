var isPowerOfThree = function(n) {
    if(n === 1){return true;}
    if(n === 0){return false;}
    
    n/=3;
    
    if(n%3 != 0 && n != 1){
        return false;
    }else{
        let x = isPowerOfThree(n);
        return x;
    }
};
