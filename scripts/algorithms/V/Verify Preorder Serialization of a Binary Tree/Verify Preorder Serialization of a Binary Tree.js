// Runtime: 63 ms (Top 38.1%) | Memory: 43.90 MB (Top 52.3%)

/**
 * @param {string} preorder
 * @return {boolean}
 */
var isValidSerialization = function(preorder) {
    let balance = 1
    for(const node of preorder.split(','))
        if (balance > 0)
            if (node === '#') --balance
            else ++balance
        else return false
    return balance < 1
}