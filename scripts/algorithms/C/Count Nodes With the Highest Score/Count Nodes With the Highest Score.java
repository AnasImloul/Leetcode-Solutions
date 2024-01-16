// Runtime: 19 ms (Top 95.33%) | Memory: 67.90 MB (Top 73.63%)

class Solution {
    /** Algorithm/Theory
        1. An efficient first step is to build the tree. This way, we can post-order traverse it and determine the product of non-empty subtrees
        2. Use a simple Node[] array to map node order/value to Node content.
           set node[0] to be the parent.
           loop from 1 to n and if the current node[i] is null, set it as new node. If the parent is null, initialize node[parent[i]].
           set node[parent[i]].left or .right to node[i], depending if left or right is already set.
        3. Continue post-order traversal. 
            - if on a leaf, that leaf will make a score of total -1. Check against the current highest score and set. Return 1 as that leaft has only 1 node
            - if not on a leaf, apply post-oder to left and right.
        4. After 3b) for each parent node, determine its number of nodes from its subtree: 1 + left + right.
        6. Once 5 is done, determine the highest score that node will generate.
           This will be Math.max(1, onLeft) * Math.max(1, onRight) * Math.max(1, (totalNodes - nrOfNodesFromSubtree)).
           Basically we are multiplying the remaining 3 groups of nodes that are formed from the removal of that node (left, right, above).
           Pay attention to multiply with 1 (not with 0). The root will have no "above" nodes so total - nodesOnSubtree will return 0.
    */
   public int countHighestScoreNodes(int[] parents) {
        Node[] nodes = buildTree(parents);
        long[] highestScore = {0,0};
        countHighestScore(nodes[0], highestScore, parents.length);
        return (int)highestScore[1];
    }

    private int countHighestScore(Node node, long[] highestScore, int total) {
        if (node != null) {
            if (node.left == null && node.right == null) {
                // a leaf will have 1 node under(itself) and will produce a total nodes - 1 score.
                if (highestScore[0] == total - 1) {
                    highestScore[1]++;
                } else if (highestScore[0] < total - 1) {
                    highestScore[0] = total - 1;
                    highestScore[1] = 1;
                }
                return 1;
            } else {
                // apply post-order and see how many nodes are left and right
                int onLeft = countHighestScore(node.left, highestScore, total);
                int onRight = countHighestScore(node.right, highestScore, total);
                int totalSubtree = onLeft + onRight + 1;
                // if left or right is null, replace it with 1, multiplication by 1
                long possibleScore = (long) (Math.max(1, onLeft)) * Math.max(onRight, 1)
                        * Math.max(1, total - totalSubtree);
                if (highestScore[0] == possibleScore) {
                    highestScore[1]++;
                } else if (highestScore[0] < possibleScore) {
                    highestScore[0] = possibleScore;
                    highestScore[1] = 1;
                }
                return totalSubtree;
            }
        }
        return 0;
    }

    private Node[] buildTree(int[] parents) {
        Node[] nodes = new Node[parents.length];
        nodes[0] = new Node();
        for (int i = 1; i < parents.length; i++) {
            // create current node
            if (nodes[i] == null) {
                nodes[i] = new Node();
            }
            // create parent node
            if (nodes[parents[i]] == null) {
                nodes[parents[i]] = new Node();
            }
            // link parent node left or right to this child node.
            if (nodes[parents[i]].left == null) {
                nodes[parents[i]].left = nodes[i];
            } else {
                nodes[parents[i]].right = nodes[i];
            }
        }
        return nodes;
    }

    private static class Node {
        Node left;
        Node right;
    }
}
