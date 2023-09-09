// Runtime: 165 ms (Top 9.0%) | Memory: 65.69 MB (Top 9.0%)

/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @param {number} distance
 * @return {number}
 */
var countPairs = function(root, distance) {
    var graph = new Map()
    var leaves = new Map()
    function dfs(root, parent) {
        if (!root) return 
        if (!root.left && !root.right) {
            leaves.set(root, true)
        }

        graph.set(root, [])
        if (root.left) {
            graph.get(root).push(root.left)
        }
        if (root.right) {
            graph.get(root).push(root.right)
        }
        if (parent) {
            graph.get(root).push(parent)
        }
        dfs(root.left, root)
        dfs(root.right, root)
    }  

    dfs(root, null)

    var visited = new Map()
    var count = 0

    function bfs(start, dis) {
        visited.set(start, true)
        var queue = [graph.get(start).filter(node => !visited.has(node))]

        var innerVisited = new Map()

        while (queue.length) {
            var curLevelNodes = queue.shift()

            if (!curLevelNodes.length) break
            if (dis === 0) break

            var nextLevelNodes = []
            for (var i = 0; i < curLevelNodes.length; i++) {
                var curLevelNode = curLevelNodes[i]

                innerVisited.set(curLevelNode, true)

                if (leaves.has(curLevelNode)) {
                    count++
                }

                nextLevelNodes.push(
                    ...graph
                        .get(curLevelNode)
                        .filter(node => 
                            !visited.has(node) && 
                            !innerVisited.has(node)
                        )
                )
               
            }
            queue.push(nextLevelNodes)
            dis--
        }
    }

    leaves.forEach((value, leaf) => {
        bfs(leaf, distance)
    })

    return count
};