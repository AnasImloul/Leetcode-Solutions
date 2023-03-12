var maxProfit = function(A, k) {
    //rangeSum Formula
    let rangesum=(i,j)=>{
        i=BigInt(i),j=BigInt(j)
        return ((j*((j+1n))/2n)-(i*(i+1n)/2n))
    }
    A.unshift(0) //prepend the sentinel 0 
    A.sort((a,b)=>a-b)
    let n=A.length,result=0n,mod=BigInt(1e9+7),i=n-1
    // can use all current levels
    while((k>=(n-i)*(A[i]-A[i-1]))&&i>0){
        if(A[i]!=A[i-1])
            result=(result+(rangesum(A[i-1],A[i])*BigInt(n-i)))%mod,
            k-=(n-i)*(A[i]-A[i-1])
        i--
    }
    //can use some of the current levels
    if(k>0&&k>=n-i){
        let levels=Math.floor(k/(n-i)) //the levels i can use 
        result=(result+(BigInt(n-i)*rangesum(A[i]-levels,A[i])))%mod
        k-=levels*(n-i)
        A[i]-=levels
    }
    // can use some of the items OF the first level
    if(k>0&&k<n-i)
        result=(result+BigInt(k)*BigInt(A[i]))%mod
    return Number(result)
};