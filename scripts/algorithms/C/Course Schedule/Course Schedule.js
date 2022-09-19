// Runtime: 135 ms (Top 41.22%) | Memory: 46.8 MB (Top 77.04%)
var canFinish = function(numCourses, prerequisites) {
    const adjList = []
    const visit = []
    construAdj()
    for (let i = 0; i < numCourses; i++) {
        if (!dfs(i)) return false
    }
    return true

    function dfs(i) {
        // base case
        if (visit[i]) return false
        if (visit[i] === false) return true

        visit[i] = true

        for (const nei of adjList[i] ?? []) {
            if (!dfs(nei)) return false
        }

        visit[i] = false
        return true
    }

    function construAdj() {
        for (const pre of prerequisites) {
            if (!adjList[pre[0]]) adjList[pre[0]] = []
            adjList[pre[0]].push(pre[1])
        }
    }
};