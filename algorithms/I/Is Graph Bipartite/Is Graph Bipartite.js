var isBipartite = function(graph) {
    const colors = new Map();
    const stack = [];
    
    for (let i = 0; i < graph.length; i++) {
        if (colors.has(i)) continue;
        
        colors.set(i, true);
        stack.push(i);

        while (stack.length > 0) {
            let current = stack.pop();

            for (let neighbour of graph[current]) {
                if (!colors.has(neighbour)) {
                    colors.set(neighbour, !colors.get(current));
                    stack.push(neighbour);
                    continue;
                }
                
                if (colors.get(neighbour) === colors.get(current)) return false;
            }
        }
    }
    
    return true
};
