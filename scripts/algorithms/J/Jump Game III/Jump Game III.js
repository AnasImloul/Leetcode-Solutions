var canReach = function(arr, start) {
    const N = arr.length;
    const visited = new Set();
    const queue = [[start]];
    const diff = [1, -1];

    while (queue.length > 0) {
        const nodes = queue.pop();
        const newNodes = [];

        for (const node of nodes) {
            const jump = arr[node];
                
            if (jump === 0) {
                return true;
            }

            for (const d of diff) {
                const newNode = node + (jump * d);

                if (newNode < 0 || newNode >= N) {
                    continue;
                }

                if (visited.has(newNode)) {
                    continue;
                }

                visited.add(newNode);
                newNodes.push(newNode);
            }
        }
        
        if (newNodes.length > 0) {
            queue.push(newNodes);
        }
    }
    
    return false;
};
