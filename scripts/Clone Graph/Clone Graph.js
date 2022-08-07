
var cloneGraph = function(node) {
    if(!node)
        return node;
    
    let queue = [node];
    
    let map = new Map();
    
	//1. Create new Copy of each node and save in Map
    while(queue.length) {
        let nextQueue = [];
        
        for(let i = 0; i < queue.length; i++) {
            let n = queue[i];
            
            let newN = new Node(n.val);
            
            if(!map.has(n)) {
                map.set(n, newN);
            }
            
            let nei = n.neighbors;
            
            for(let j = 0; j < nei.length; j++) {
                if(map.has(nei[j]))
                    continue;
                nextQueue.push(nei[j]); 
            }
        }
        
        queue = nextQueue;
    }
    
    queue = [node];
    
    let seen = new Set();
    seen.add(node);
    
	//2. Run BFS again and populate neighbors in new node created in step 1.
    while(queue.length) {
        let nextQueue = [];
        
        for(let i = 0; i < queue.length; i++) {
            let n = queue[i];
            
            let nei = n.neighbors;
            let newn = map.get(n);
            
            for(let j = 0; j < nei.length; j++) {
                newn.neighbors.push(map.get(nei[j]));
                
                if(!seen.has(nei[j])) {
                    nextQueue.push(nei[j]); 
                    seen.add(nei[j]);
                }
            }
        }
        
        queue = nextQueue;
    }
    
    return map.get(node);
};
