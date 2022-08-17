var canDistribute = function(nums, quantity) {
    quantity.sort((a,b)=>b-a)
    let freq={},flag=false
    for(let num of nums)
        freq[num]=(freq[num]||0) +1
    let set=Object.keys(freq),n=set.length,k=quantity.length
    let rec=(prefix)=>{
        if(prefix.length==k || flag==true)  
            return flag=true
        for(let i=0;i<n;i++){
            freq[set[i]]-=quantity[prefix.length]
			prefix.push(set[i])
            if( freq[set[i]]>=0)
                rec(prefix)
			prefix.pop()
            freq[set[i]]+=quantity[prefix.length]
        }
    }
    rec([])
    return flag
};
