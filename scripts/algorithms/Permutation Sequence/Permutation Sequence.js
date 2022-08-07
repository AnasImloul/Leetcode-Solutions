const dfs = (path, visited, result, numbers, limit) => {
    // return if we already reached the permutation needed
    if(result.length === limit) {
        return;
    }
    
    // commit the result
    if(path.length === numbers.length) {
        result.push(path.join(''))
        return;
    }
    
    // easier to reason and less prone to miss the -1 offset of normal for loop
    for(const [index, number] of numbers.entries()) {
        if(visited[index]) continue;
        
        path.push(number);
        visited[index] = true;
        dfs(path, visited, result, numbers);
        path.pop();
        visited[index] = false;
    }
}

var getPermutation = function(n, k) {
    const numbers = Array.from({length: n}, (_, i) => i + 1);
    let visitedNumbers = Array.from(numbers, () => false);
    let result = [];
    dfs([], visitedNumbers, result, numbers, k);
    return result[k - 1];
};
