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
