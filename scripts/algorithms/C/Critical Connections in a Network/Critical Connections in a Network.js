// Runtime: 731 ms (Top 93.55%) | Memory: 113.8 MB (Top 87.10%)
var criticalConnections = function(n, connections) {
    // Graph Formation
    const graph = new Map();
    connections.forEach(([a, b]) => {
        const aconn = graph.get(a) || [];
        const bconn = graph.get(b) || [];

        aconn.push(b), bconn.push(a);
        graph.set(a, aconn);
        graph.set(b, bconn);
    });

    // Find Bridges
    const bridges = [];
    const visited = new Array(n).fill(false);
    const tin = new Array(n).fill(-1);
    const dis = new Array(n).fill(-1);

    let time = 0;

    const dfs = (node, parent = -1) => {
        visited[node] = true;
        ++time;
        tin[node] = time;
        dis[node] = time;

        const connections = graph.get(node);
        for(let conn of connections) {
            if(conn == parent) {
                continue;
            }
            if(visited[conn]) {
                dis[node] = Math.min(dis[node], tin[conn]);
            } else {
                dfs(conn, node);
                dis[node] = Math.min(dis[node], dis[conn]);
                if(dis[conn] > tin[node]) {
                    bridges.push([node, conn]);
                }
            }
        };
    }

    dfs(0);

    return bridges;
};