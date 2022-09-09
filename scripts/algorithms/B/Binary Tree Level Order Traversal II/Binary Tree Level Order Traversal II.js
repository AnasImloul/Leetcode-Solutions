// Runtime: 110 ms (Top 30.61%) | Memory: 44.3 MB (Top 44.87%)
var levelOrderBottom = function(root) {
    let solution = []
    function dfs(node, level) {
        if(!node) return null

        if(!solution[level]) solution[level] = []
        solution[level].push(node.val)

        dfs(node.left, level + 1)
        dfs(node.right, level + 1)
    }
    dfs(root, 0)
    return solution.reverse()
};