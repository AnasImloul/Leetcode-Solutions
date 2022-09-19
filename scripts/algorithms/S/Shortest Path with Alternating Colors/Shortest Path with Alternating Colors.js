// Runtime: 134 ms (Top 50.88%) | Memory: 46.8 MB (Top 94.74%)
const RED = "red";
const BLUE = "blue";

function mapAllEdges(edges) {
    const map = new Map();
    for(let edge of edges) {
        if(!map.has(edge[0])) {
            map.set(edge[0], []);
        }
        map.get(edge[0]).push(edge[1])
    }
    return map;
}

function bfs(color, redNodeMap, blueNodeMap, result) {
    const queue = [0];
    let length = 0;
    let currentColor = color;
    while(queue.length > 0) {
        const size = queue.length;
        for(let i = 0; i < size; i++) {
            const node = queue.shift();
            if(result[node] === -1 || length < result[node] ) {
                result[node] = length;
            }
            const map = RED === currentColor ? redNodeMap : blueNodeMap;
            if(map.has(node)) {
                const edges = map.get(node);
                map.delete(node);
                queue.push(...edges)
            }
        }
        length++;
        currentColor = RED === currentColor ? BLUE : RED;
    }
    return result;
}

function shortestPath(redEdges, blueEdges, color, result) {
    const redNodeMap = mapAllEdges(redEdges);
    const blueNodeMap = mapAllEdges(blueEdges);
    bfs(color, redNodeMap, blueNodeMap, result);
}

/**
 * @param {number} n
 * @param {number[][]} redEdges
 * @param {number[][]} blueEdges
 * @return {number[]}
 */
var shortestAlternatingPaths = function(n, redEdges, blueEdges) {
    const result = new Array(n).fill(-1);
    shortestPath(redEdges, blueEdges, RED, result);
    shortestPath(redEdges, blueEdges, BLUE, result);
    return result
};