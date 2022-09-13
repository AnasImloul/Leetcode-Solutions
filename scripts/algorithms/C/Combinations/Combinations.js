// Runtime: 164 ms (Top 64.86%) | Memory: 47.8 MB (Top 82.84%)
var combine = function(n, k) {

    function helper (start, end, combo, subset, answer) {
        if (combo==0) {
            answer.push([...subset])
            return;
        }
        if (end - start + 1 < combo) {
            return;
        }
        if (start > end) {
            return;
        }
        subset.push(start)
        helper(start+1, end, combo - 1, subset, answer)

        subset.pop()
        helper(start+1, end, combo, subset, answer)
    }

    const answer = []
    helper(1, n, k, [], answer)
    return answer
};