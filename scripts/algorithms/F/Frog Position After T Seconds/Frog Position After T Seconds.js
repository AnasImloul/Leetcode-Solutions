// Runtime: 91 ms (Top 100.00%) | Memory: 46.8 MB (Top 100.00%)

/**
 * @param {number} n
 * @param {number[][]} edges
 * @param {number} t
 * @param {number} target
 * @return {number}
 */
function dfs(n, map, t, target, visited, prop) {
    // edge case1: if run out of steps, cannot find target
    if(t === 0 && n !== target) return 0;
    // edge case2: if run out of steps, but found target
    if(t === 0 && n === target) return prop;

    visited.add(n);
    // get unvisited children/neighbors
    const validChildren = [];
    (map[n] ?? []).forEach((child) => {
        if(!visited.has(child)) validChildren.push(child);
    })
    // edge case3, if still more steps to use, but no more children to move,
    // if already at the targeted node, should just return
    if(n === target && t > 0 && !validChildren.length) return prop;
    // edge case4, if still more steps to use and no more children to move,
    // but current node is not target node, cannot find target, return 0
    if(n !== target && t > 0 && !validChildren.length) return 0;

    // go to next valid child/neighbor
    for(let i = 0; i < validChildren.length; i ++) {
        if(visited.has(validChildren[i])) continue;
        let result = dfs(validChildren[i], map, t - 1, target, visited, prop * (1 / validChildren.length))
        if(result !== 0) return result;
    }

    return 0;
}

var frogPosition = function(n, edges, t, target) {
    const map = new Array(n + 1);
    // make bidirectional edge map
    edges.forEach(item => {
        if(!map[item[0]]) map[item[0]] = [];
        if(!map[item[1]]) map[item[1]] = [];
        map[item[0]].push(item[1]);
        map[item[1]].push(item[0]);
    });

    return dfs(1, map, t, target, new Set(), 1);
};