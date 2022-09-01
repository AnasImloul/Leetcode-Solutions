// Runtime: 79 ms (Top 83.70%) | Memory: 42 MB (Top 97.04%)
// 980. Unique Paths III
var uniquePathsIII = function(grid) {
    const M = grid.length; // grid height
    const N = grid[0].length; // grid width
    let result = 0; // final result
    let startY = 0, startX = 0; // starting point coordinates
    let finalY = 0, finalX = 0; // endpoint coordinates
    let empty = 0; // count of empty squares
    let visit = Array(M); // visited squares (MxN of booleans)

    // Initialization of required variables
    for (let i = 0; i < M; i++) {
        visit[i] = Array(N).fill(false); // now: "visit[i][j] === false"
        for (let j = 0; j < N; j++) {
            switch (grid[i][j]) {
                case 0 : empty++; break;
                case 1 : startY = i; startX = j; break;
                case 2 : finalY = i; finalX = j; break;
            }
        }
    }

    // Recursively run DFS and get the answer in the "result" variable
    dfs(startY, startX, visit, 0);
    return result;

    // DFS implementation
    function dfs (startY, startX, visit, step) {

        // If it's a wrong square, then exit immediately
        if (startY < 0 || startY >= M || // off grid (height)
            startX < 0 || startX >= N || // off grid (width)
            visit[startY][startX] || // already processed
            grid [startY][startX] === -1 // this is an obstacle
        ) return; // ... exit now

        // Base case: we're at the endpoint, need to stop the recursion.
        // If all of squares are visited, increase the "result":
        // (count of paths from start to the end).
        if (startY === finalY && startX === finalX) {
            if (step - 1 === empty) result++;
            return;
        }

        // Run DFS for neighboring squares.
        // Increase the number of steps (count of the visited squares).
        visit[startY][startX] = true; // mark current square as visited
        dfs(startY-1, startX, visit, step + 1); // top
        dfs(startY, startX+1, visit, step + 1); // right
        dfs(startY+1, startX, visit, step + 1); // bottom
        dfs(startY, startX-1, visit, step + 1); // left
        visit[startY][startX] = false; // restore visited square
    }
};