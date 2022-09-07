// Runtime: 671 ms (Top 72.22%) | Memory: 86.2 MB (Top 94.44%)
var rearrangeArray = function(nums) {
    let arr=[], res=[]
    for(let q of nums) arr[q]= 1

    let l=0, r=arr.length-1
    while(l<=r){
        while(!arr[l])l++
        while(!arr[r])r--
        if(l<=r)res.push(l++)
        if(l<=r)res.push(r--)
    }
    return res
};