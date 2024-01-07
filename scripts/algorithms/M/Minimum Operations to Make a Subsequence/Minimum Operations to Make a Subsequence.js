// Runtime: 266 ms (Top 33.33%) | Memory: 83.90 MB (Top 33.33%)

var lengthOfLIS = function(A) {
    if(!A.length) return 0;
    let tails = [-Infinity];  //here -Infinity acts as a Sentinel, for cleaner code (or else I would ahve to place A[0] here)

    for(let i=0; i<A.length; i++){
        // If my curr element is bigger than all possible tails, i just need to create a new subarray, which of course will be of length tails.length-1 +1
        if(A[i]>tails[tails.length-1])
            tails.push(A[i]);
        else{
            let lo=0, hi = tails.length-1;
            //binary search to find where to place my current element so i have more chances of creating a bigger subarray
            while(lo<hi){
                let mid = (lo+hi)>>1
                if(tails[mid] < A[i])
                    lo = mid+1;
                else
                    hi = mid;
            }
            tails[lo] = A[i];
        }
    }
    return tails.length-1;// is the length of the longest possible subarray (-1 because of the -Infinity I added)
};
var minOperations = function(T, A) {
    let seen=new Set(T),res=0,originalIndex={},n=T.length
    //filter out all the unnecessary values
    A=A.filter(d=>seen.has(d))
    for(let i=0;i<T.length;i++)
        originalIndex[T[i]]=i //maintain the original indices of the values in T
    A=A.map(d=>originalIndex[d])    
    return  T.length-lengthOfLIS(A)
};
