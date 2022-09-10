// Runtime: 120 ms (Top 95.62%) | Memory: 45.3 MB (Top 37.23%)
// Time: O(n^2)
var executeInstructions = function(n, startPos, s) {
    let answers = [];
    for (i = 0; i < s.length; i++) {
        let movement = 0;
        let [row, col] = startPos;
        for (j = i; j < s.length; j++) {
            if (s[j] == "R") col++;
            else if (s[j] == "L") col--;
            else if (s[j] == "D") row++;
            else row--;
            if(row>n-1 || col > n-1 || row < 0 || col < 0) {
                break;
            }
            movement++;
        }
        answers[i] = movement;
    }
    return answers;
};