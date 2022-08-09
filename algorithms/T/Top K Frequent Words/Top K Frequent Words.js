var topKFrequent = function(words, k) {
    let map=new Map()
    let res=[]
    for(let i of words){
        if(map.has(i)){
            map.set(i,map.get(i)+1)
        }else{
            map.set(i,1)
        }
    }
    
    res=[...map.keys()].sort((a,b)=>{
        if(map.get(a)===map.get(b)){
            return b < a ? 1:-1
        }
        return map.get(b)-map.get(a)
    }).slice(0,k)
    
    return res
};
