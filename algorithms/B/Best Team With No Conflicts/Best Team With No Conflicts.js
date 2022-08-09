var bestTeamScore = function(scores, ages) {
    const players = scores.map((score, index) => ({ score, age: ages[index] }))
        .sort((a,b) => a.score === b.score ? a.age - b.age : a.score - b.score);
    let memo = new Array(scores.length).fill(0).map(_ => new Array());
    return dfs(0, 0);
    
    function dfs(maxAge, index) {
        if (index === players.length) {
            return 0;
        }
        
        if (memo[index][maxAge] !== undefined) {
            return memo[index][maxAge];
        }
        
        let max = 0;
        let currentPlayer = players[index];

        // cannot take because I'm too young and better than an old guy in my team
        if (currentPlayer.age < maxAge) {
            memo[index][maxAge] = dfs(maxAge, index + 1)
            return memo[index][maxAge];
        }
        
        // take
        max = Math.max(max, currentPlayer.score + dfs(Math.max(maxAge, currentPlayer.age), index + 1));
        
        // not take
        max = Math.max(max, dfs(maxAge, index + 1));
        
        memo[index][maxAge] = max;
        return max;
    }
};
