var getCoprimes = function(nums, edges) {
    
    const node = {}
    const ans = Array(nums.length).fill(null)
    
    function addNode(f, t){
        if(!node[f]){
            node[f]=[]
        }
        node[f].push(t)
    }
    
    edges.forEach(([f, t])=>{
        addNode(f, t)
        addNode(t, f)
    })
    
    function gcd(a, b){
        while(b) [a, b] = [b, a % b];
        return a;
    }
    
    const map = []
    for(let i=0; i<51; i++){
        map[i]=[]
        for(let j=0; j<51; j++){
            map[i][j]= gcd(i,j)
        }
    }

    let pi=-1
    let path=Array(nums.length)
    function check(v){
        if(ans[v]!==null) return
        ans[v] = -1
        let a = nums[v]
        for(let k=pi; k>=0; k--){
            let b = nums[path[k]]
            if(map[a][b]===1){
                ans[v]=path[k]
                break
            }
        }
        if(node[v]) {
            path[++pi]=v
            node[v].forEach(child=>check(child))
            pi--
        }
    }
    
    for(let i=0; i<nums.length; i++){
        check(i)
    }
    
    return ans    
};
