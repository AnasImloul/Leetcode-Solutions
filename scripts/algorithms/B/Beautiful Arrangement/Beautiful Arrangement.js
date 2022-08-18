// Runtime: 148 ms (Top 70.67%) | Memory: 42.3 MB (Top 56.00%)

var countArrangement = function(n) {
    let result = 0;
    const visited = Array(n + 1).fill(false);
    const dfs = (next = n) => {
        if (next === 0) {
            result += 1;
            return;
        }

        for (let index = 1; index <= n; index++) {
            if (visited[index] || index % next && next % index) continue;
            visited[index] = true;
            dfs(next - 1);
            visited[index] = false;
        }
    };

    dfs();
    return result;
};