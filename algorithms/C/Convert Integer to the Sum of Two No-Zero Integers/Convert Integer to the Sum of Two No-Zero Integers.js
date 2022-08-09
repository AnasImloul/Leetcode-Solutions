var getNoZeroIntegers = function(n) {
   for(let i=1;i<=n;i++){
       if(!haveZero(i) && !haveZero(n-i)){
           return [i,n-i]
       }
   }
};

const haveZero = (n) =>{
    let copy = n;
    while(copy>0){
        if(copy%10===0){
            return true
        }
        copy=Math.floor(copy/10)
    }
    return false
}
