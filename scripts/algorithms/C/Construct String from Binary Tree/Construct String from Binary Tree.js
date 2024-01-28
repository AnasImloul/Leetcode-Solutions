// Runtime: 61 ms (Top 73.88%) | Memory: 54.70 MB (Top 5.14%)

var tree2str = function(root) {
    // Step 1: Base case - if the root is null, return an empty string
    if (root === null) return "";

    // Step 2: Start with the value of the current node as the result string
    let result = root.val.toString();

    // Step 3: Recursively process the left and right subtrees
    let leftSubtree = tree2str(root.left);
    let rightSubtree = tree2str(root.right);

    // Step 4: Check conditions to determine the final result
    if (leftSubtree === "" && rightSubtree === "") {
        // Both left and right subtrees are empty, return the current result
        return result;
    }
    if (leftSubtree === "") {
        // Left subtree is empty, include empty parentheses for it and the right subtree
        return result + "()" + "(" + rightSubtree + ")";
    }
    if (rightSubtree === "") {
        // Right subtree is empty, include the left subtree
        return result + "(" + leftSubtree + ")";
    }

    // Both left and right subtrees are non-empty, include both in the result
    return result + "(" + leftSubtree + ")" + "(" + rightSubtree + ")";
};

