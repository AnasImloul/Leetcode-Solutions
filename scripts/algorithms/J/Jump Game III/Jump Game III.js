// Runtime: 57 ms (Top 89.2%) | Memory: 51.60 MB (Top 47.16%)

// Recursion, Backtracking
var canReach = function(arr, start) {
    if (arr === null || arr.length === 0) {
        return false;
    }
    return dfs(arr, start);
    // T.C: O(N)
    // S.C: O(N)
};

const dfs = (arr, idx) => {
    if (arr[idx] === 0) {
        return true;
    }
    if (idx < 0 || idx > arr.length-1 || arr[idx] < 0) {
        return false;
    }
    let jump = arr[idx];
    arr[idx] = -1; // marking this index as visited
    return dfs(arr, idx-jump) || dfs(arr, idx+jump);
}
