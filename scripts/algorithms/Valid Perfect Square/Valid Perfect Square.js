var isPerfectSquare = function(num) {
    let low = 1;
    let high = 100000;
    while(low <= high){
        let mid = (low + high) >> 1;
        let sqrt = mid * mid
        if( sqrt == num) {
            return true;
        
        }else if(num > sqrt ){
            low = mid + 1
        }else {
            high = mid - 1
        }
    }
    return false;
};
