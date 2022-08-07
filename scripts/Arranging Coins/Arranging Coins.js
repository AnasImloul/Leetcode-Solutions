var arrangeCoins = function(n) {
    if(n===1) return n
    for(let i=1; i<=n; i++){
        if(n<Math.floor((i*(i+1))/2)){
            return i-1
        }
    }
};
