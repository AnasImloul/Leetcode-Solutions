// Runtime: 784 ms (Top 5.04%) | Memory: 78.8 MB (Top 6.67%)

/**
 * @param {number[][]} grid
 * @return {number}
 */
var shortestPathBinaryMatrix = function(grid) {
    const n = grid.length
    const directions = [
        [-1, 0], [-1, 1], [0, 1], [1, 1],
        [1, 0], [1, -1], [0, -1], [-1, -1]
    ]
    const visited = []
    const distance = []
    const predecessor = []
    const queue = []

    for (let i = 0; i < n; i++ ) {
        visited.push(Array.from({length: n}, (v, i) => false))
        distance.push(Array.from({length: n}, (v, i) => 9999))
        predecessor.push(Array.from({length: n}, (v, i) => null))
    }

    const startIndex = [0, 0]
    if(grid[startIndex[0]][startIndex[1]] !== 0) {
        return -1
    }

    queue.push(startIndex)
    distance[startIndex[0]][startIndex[1]] = 1

    while(queue.length > 0) {
        const current = queue.shift()
        visited[current[0]][current[1]] = true

        if (current[0] === n-1 && current[1] === n-1) {
            break
        }

        directions.forEach(dir => {
            const x = current[0] + dir[0]
            const y = current[1] + dir[1]

            if (x < 0 || y < 0 || x >= n || y >= n) {
                return
            }

            if (
                grid[x][y] === 0 &&
                visited[x][y] === false &&
                distance[x][y] > distance[current[0]][current[1]] + 1
            ) {
                distance[x][y] = distance[current[0]][current[1]] + 1
                predecessor[x][y] = current
                queue.push([x, y])
            }
        })
    }

    console.log(distance)
    console.log(visited)
    console.log(predecessor)

    return distance[n-1][n-1] >= 999 ?
        -1 : distance[n-1][n-1]
};
