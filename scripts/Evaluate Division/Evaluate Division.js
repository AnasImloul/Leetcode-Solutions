var calcEquation = function(equations, values, queries) {
    const res = []
    
    for(let i = 0; i < queries.length; i++) {
        const currQuery = queries[i]
        
        const [currStart, currDestination] = currQuery
        
        const adj = {}
        
        const additionalEdges = []
        const additionalValues = []
        
        const visited = new Set()
        
        equations.forEach((el,idx) => {
            const [to, from] = el
            const val = values[idx]
            
            additionalEdges.push([from, to])
            additionalValues.push(1/val)
        })
        
        values = [...values, ...additionalValues]
        let idx = 0
        for(const [from, to] of [...equations, ...additionalEdges]) {
            if(!(from in adj)) adj[from] = []
            
            adj[from].push([to, values[idx]])
            
            idx++
        }
        
        if(!(currStart in adj) || !(currDestination in adj)) {
            res.push(-1)
            continue
        }
        
        if(currStart === currDestination) {
            res.push(1)
            continue
        }
        
        
        let currEvaluation = 1
        let found = false
        const subResult = dfs(currStart)
        if(!found) res.push(-1)
        
        
        
        function dfs(node) {
            if(!node) return null
            if(node === currDestination) {
                return true
            }
            
            const children = adj[node] // [ [to, val] ]
            
            if(!children) return false
            
            for(const child of children) {
                if(visited.has(node)) continue
                visited.add(node)
                
                currEvaluation =  currEvaluation*child[1]

                if(dfs(child[0]) === true) {
                    !found && res.push(currEvaluation)
                    found = true
                   return 
                }
                visited.delete(node)
                currEvaluation /= child[1]
            }
        }
        
        }
    return res
};
