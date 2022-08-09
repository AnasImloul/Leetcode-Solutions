var allPathsSourceTarget = function(graph) {
    
    const result = [];
    const path = [];
    
    dfs(0);
    return result;

    
    // [1,2], [3], [3], []]
    //          [0]
    // [1]              [2]
    // [3]              [3]
    //         return
    
    function dfs(index) {

        if (index === graph.length - 1) {
            
            return result.push([...path, index]);
            
            // path.push(index);
            // const copyPath = [...path]
            // path.pop();
            // return result.push([...path]);
        }
 
        const elements = graph[index];    // [ 1, 2 ]
        for (let j = 0; j < elements.length; j++) { // [ 1 ]
            path.push(index);  // path: [ 0 ]
            dfs(elements[j]);     // dfs(1);
            path.pop();     
        }
    }
};
