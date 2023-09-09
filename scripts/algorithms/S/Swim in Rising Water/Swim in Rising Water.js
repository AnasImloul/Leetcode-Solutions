// Runtime: 84 ms (Top 89.5%) | Memory: 47.08 MB (Top 93.0%)

const moves = [[1,0],[0,1],[-1,0],[0,-1]]

var swimInWater = function(grid) {
    let pq = new MinPriorityQueue(),
        N = grid.length - 1, ans = grid[0][0], i = 0, j = 0
    while (i < N || j < N) {
        for (let [a,b] of moves) {
            let ia = i + a, jb = j + b
            if (ia < 0 || ia > N || jb < 0 || jb > N || grid[ia][jb] > 2500) continue
            pq.enqueue((grid[ia][jb] << 12) + (ia << 6) + jb)
            grid[ia][jb] = 3000
        }
        let next = pq.dequeue().element
        ans = Math.max(ans, next >> 12)
        i = (next >> 6) & ((1 << 6) - 1)
        j = next & ((1 << 6) - 1)
    }
    return ans
};