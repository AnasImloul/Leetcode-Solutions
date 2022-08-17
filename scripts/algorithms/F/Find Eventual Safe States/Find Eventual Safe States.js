/**
 * @param {number[][]} graph
 * @return {number[]}
 */
var eventualSafeNodes = function(graph) {
    const ans = [];
    const map = new Map();
    for(let i=0; i<graph.length; i++) {
        if(dfs(graph, i, map)) {
            ans.push(i);
        }
    }
    return ans;
};

var dfs = function(graph, node, map) {
    if(map.has(node)) return map.get(node);
    map.set(node, false);
    for(let nei of graph[node]) {
        if(!dfs(graph, nei, map)) {
            return false;
        }
    }
    map.set(node, true);
    return true;
}
