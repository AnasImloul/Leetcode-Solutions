// Runtime: 121 ms (Top 5.08%) | Memory: 41.2 MB (Top 98.87%)
/**
 * @param {number[][]} matrix
 * @return {number[]}
 */
var spiralOrder = function(matrix) {
    let [top, bot, left, right, ans] = [0, matrix.length - 1, 0, matrix[0].length - 1,[]]

    while ((top <= bot) && (left <= right)) {
        for (let j = left; j <= right; j++) {
            ans.push(matrix[top][j])
        }
        top ++;
        for (let i = top; i <= bot; i++) {
            ans.push(matrix[i][right])
        }
        right --;
        if ((bot < top) || (right < left)) {
            break
        }
        for (let j = right; left <= j; j--){
            ans.push(matrix[bot][j])
        }
        bot --;
        for (let i = bot; top <= i; i--){
            ans.push(matrix[i][left])
        }
        left ++;
    }
    return ans
}