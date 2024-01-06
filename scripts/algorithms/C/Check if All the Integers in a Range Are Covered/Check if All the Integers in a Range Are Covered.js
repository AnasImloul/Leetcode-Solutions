// Runtime: 50 ms (Top 78.79%) | Memory: 42.60 MB (Top 57.58%)

/**
 * @param {number[][]} ranges
 * @param {number} left
 * @param {number} right
 * @return {boolean}
 */
var isCovered = function(ranges, left, right) {
    let z=0,f=0,e=[];
    let a=ranges.flat(Infinity);

    function abc(c,d){
        for(let i=c;i<=d;i++)
        if(e[i]==i)
        e[i]=null;
    }
    for(let i=left;i<=right;i++)
        e[i]=i;
    for(let i=0;i<a.length;i=i+2){
        if(a[i]<=left&&a[i+1]>=right)
        return true;
        else if(a[i]>right)
        continue;
        else abc(a[i],a[i+1])
    }
    for(let i=left;i<=right;i++)
    if(e[i]!=null)
    return false
    
    return true
};
