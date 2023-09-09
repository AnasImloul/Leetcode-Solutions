// Runtime: 2074 ms (Top 6.4%) | Memory: 223.12 MB (Top 48.3%)

var countSubTrees = function(n, edges, labels) {
    labels = labels.split("")

    let adj = new Array(n)
    for (let i = 0; i < n; i++) {
        adj[i] = new Array()
    }
    for (let edge of edges) {
        adj[edge[0]].push(edge[1])
        adj[edge[1]].push(edge[0])
    }

    let res = new Array(n)
    let dfs = function (node, parent) {
        let map = {}
        for (let neighbor of adj[node]) {
            if (neighbor === parent) continue
            let val = dfs(neighbor, node)
            for (let [label, count] of Object.entries(val)) {
                if (!map[label]) map[label] = 0
                map[label] += count
            }
        }
        if (!map[labels[node]]) map[labels[node]] = 0
        map[labels[node]]++
        res[node] = map[labels[node]]
        return map
    }

    dfs(0)
    return res
};