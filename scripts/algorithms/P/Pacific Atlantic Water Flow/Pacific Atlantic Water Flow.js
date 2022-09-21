// Runtime: 243 ms (Top 35.79%) | Memory: 50.5 MB (Top 78.35%)
`/**
 * @param {number[][]} heights
 * @return {number[][]}
 */
var pacificAtlantic = function(heights) {
    let atlantic = new Set();
    let pacific = new Set();
    let rows = heights.length;
    let cols = heights[0].length;

    for (let c = 0; c < cols; c++) {
        explore(heights, 0, c, pacific, heights[0][c]); // dfs from top row
        explore(heights, rows - 1, c, atlantic, heights[rows - 1][c]); // dfs from bottom row
    }

    for (let r = 0; r < rows; r++) {
        explore(heights, r, 0, pacific, heights[r][0]); // dfs from left most column
        explore(heights, r, cols - 1, atlantic, heights[r][cols - 1]); // dfs from right most column
    }

    // check if water can flow to both atlantic and pacific ocean.
    let res = [];
    for (let r = 0; r < rows; r++) {
        for (let c = 0; c < cols; c++) {
            let pos = r + ',' + c;
            if (atlantic.has(pos) && pacific.has(pos)) {
                res.push([r, c]);
            }
        }
    }

    return res;
};

function explore(heights, r, c, visited, prevHeight) {
    let rowInbound = 0 <= r && r < heights.length;
    let colInbound = 0 <= c && c < heights[0].length;
    if (!rowInbound || !colInbound) return;

    // height must be higher than prev height. water can only flow downwards not upwards. duh.
    // if it's the first value then it's just the same value so it's not less than so it will not return.
    if (heights[r][c] < prevHeight) return;

    let pos = r + ',' + c;
    if (visited.has(pos)) return;
    visited.add(pos)

    explore(heights, r + 1, c, visited, heights[r][c]) // below
    explore(heights, r - 1, c, visited, heights[r][c]) // above
    explore(heights, r, c + 1, visited, heights[r][c]) // right
    explore(heights, r, c - 1, visited, heights[r][c]) // left
}`