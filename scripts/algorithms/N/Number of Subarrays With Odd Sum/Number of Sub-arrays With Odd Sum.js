// Runtime: 90 ms (Top 97.83%) | Memory: 51.2 MB (Top 93.48%)
var numOfSubarrays = function(arr) {
    let mod=1e9+7,sum=0,odds=0,evens=0
    //Notice that I do not need to keep track of the prefixSums, I just need the total count of odd and even PrefixSums
    for(let i=0;i<arr.length;i++){
        sum+=arr[i]
        odds+=Number(sum%2==1)
        evens+=Number(sum%2==0)
    }
    return (odds*evens+odds)%mod
};