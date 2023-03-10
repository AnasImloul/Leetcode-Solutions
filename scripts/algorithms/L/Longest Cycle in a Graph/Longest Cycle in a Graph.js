/**
 * @param {number[]} edges
 * @return {number}
 */
var longestCycle = function(edges) {
    // visited array will be -1 if not visited or index of first visited node
    const visited = Array(edges.length).fill(-1)
    let ans = -1
    
    for (let i = 0; i < edges.length; i++) {
        
        // Since one node could be part of only one solution, only compute if it is not already visited.
        if (visited[i] !== -1) continue;
        
        // detect cycle: check if node is already visited
        // if it was visited and the visited[i] === i, 
        // it means we came to this node during this iteration
        // hence find the length
        
        let currNode = i

        while(currNode !== -1) {
            // if not already visited, mark as visited
            if (visited[currNode] === -1) {
                visited[currNode] = i
                currNode = edges[currNode]
                continue;
            }
            
            // if already visited, and value is equal to current index
            // it means we came to node during this iteration, hence we found the cycle 
            if (visited[currNode] === i) {
                // find the cycle length
                let currCycleLen = 1
                let cycleStartNode = currNode
                currNode = edges[currNode]
                
                // revisit all the nodes since first cycle node and note the length
                while(currNode !== cycleStartNode) {
                    currCycleLen++
                    currNode = edges[currNode]
                }
                ans = Math.max(currCycleLen, ans)
            }
            break;
        }
    }
    // console.log(visited)
    return ans
};