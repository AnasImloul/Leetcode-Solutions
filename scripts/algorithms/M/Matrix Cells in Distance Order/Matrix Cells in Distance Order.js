// Runtime: 152 ms (Top 83.33%) | Memory: 51.1 MB (Top 50.00%)

var allCellsDistOrder = function(rows, cols, rCenter, cCenter) {
    let distances = []
    let result = []

    //create a new "visited" cells matrix
    let visited = new Array(rows).fill([])
    for(i=0;i<visited.length;i++){
        visited[i] = new Array(cols).fill(0)
    }

    const computeDistances = (row, col, rCenter, cCenter) => {
        if(row >= rows || col >= cols) return
        if(visited[row][col]) return // don't compute distance again if cell already visited
        visited[row][col] = 1

        let distance = Math.abs(rCenter - row) + Math.abs(cCenter - col)
        if(distances[distance]){
            distances[distance].add([row,col])
        }else{
            distances[distance] = new Set()
            distances[distance].add([row,col])
        }

        computeDistances(row + 1, col, rCenter, cCenter)
        computeDistances(row, col + 1, rCenter, cCenter)
    }

    computeDistances(0, 0, rCenter, cCenter)

    distances.forEach(distance => {
        result.push(...distance)
    })

    return result
};