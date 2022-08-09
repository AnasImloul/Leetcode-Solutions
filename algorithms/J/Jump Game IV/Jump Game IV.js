/**
 * @param {number[]} arr
 * @return {number}
 */
var minJumps = function(arr) {
    if(arr.length <= 1) return 0;
    
    const graph = {};
    
    for(let idx = 0; idx < arr.length; idx ++) {
        const num = arr[idx];
        if(graph[num] === undefined) graph[num] = [];
        graph[num].push(idx);
    }
    
    let queue = [];
    const visited = new Set();
    
    queue.push(0);
    visited.add(0);
    
    let steps = 0;
    
    while(queue.length) {
        const nextQueue = [];
        
        for(const idx of queue) {
            if(idx === arr.length - 1) return steps;
            
            const num = arr[idx];
            
            for(const neighbor of graph[num]) {
                if(!visited.has(neighbor)) {
                    visited.add(neighbor);
                    nextQueue.push(neighbor);
                }
            }
            
            if(idx + 1 < arr.length && !visited.has(idx + 1)) {
                visited.add(idx + 1);
                nextQueue.push(idx + 1);
            }
            
            if(idx - 1 >= 0 && !visited.has(idx - 1)) {
                visited.add(idx - 1);
                nextQueue.push(idx - 1);
            }
            
            graph[num].length = 0;
        }
        
        queue = nextQueue;
        steps ++;
    }
    
    return -1;
};
