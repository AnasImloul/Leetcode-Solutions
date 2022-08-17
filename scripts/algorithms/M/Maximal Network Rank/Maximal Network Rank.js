var maximalNetworkRank = function(n, roads) {
    let res = 0
    let map = new Map()
    roads.forEach(([u,v])=>{
        map.set(u, map.get(u) || new Set())
        let set = map.get(u)
        set.add(v)
        
        map.set(v, map.get(v) || new Set())
        set = map.get(v)
        set.add(u)
    })
    
    for(let i=0;i<n;i++){
        if(!map.has(i)) continue
        let uAdj = map.get(i)
        let uCount = uAdj.size;
        for(let j=i+1;j<n;j++){
            if(!map.has(j)) continue
            let vAdj = map.get(j)
            let vCount = vAdj.size
            if(vAdj.has(i)) vCount--
            res = Math.max(uCount+vCount, res)
        }
    }
    return res
};
