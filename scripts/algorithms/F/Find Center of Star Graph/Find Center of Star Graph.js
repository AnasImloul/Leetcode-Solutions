var findCenter = function(edges) {
    // InDegree We need to count
    let indegree = {};
    
    for (let item of edges) {
        for (let i = 0; i < item.length; i++) {
            if (indegree[item[i]]) {
                indegree[item[i]] += 1;
            } else {
                indegree[item[i]] = 1;
            }
            if (indegree[item[i]] === edges.length) {
                return item[i];
            }
        }
    }
};