// Runtime: 229 ms (Top 67.86%) | Memory: 51.8 MB (Top 92.86%)
var stoneGameIII = function(stoneValue) {
    let len = stoneValue.length-1
    let bestMoves = [0,0,0]
    bestMoves[len%3] = stoneValue[len]
    for(let i = len-1; i >= 0 ; i--){
        let turn = stoneValue[i]
        let option1 = turn - bestMoves[(i+1)%3]
        turn += stoneValue[i+1] ||0
        let option2 = turn - bestMoves[(i+2)%3]
        turn += stoneValue[i+2] || 0
        let option3 = turn - bestMoves[i %3]
        let best = Math.max(option1,option2,option3)
        bestMoves[i%3] = best
    }
    return bestMoves[0] > 0
        ? "Alice"
        : bestMoves[0] !== 0
            ? "Bob"
            : "Tie"
};
