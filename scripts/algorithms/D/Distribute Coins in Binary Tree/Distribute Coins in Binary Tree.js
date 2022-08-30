// Runtime: 138 ms (Top 8.82%) | Memory: 44.3 MB (Top 85.29%)
var distributeCoins = function(root) {
    var moves = 0;
    postorder(root);
    return moves;

    function postorder(node){
        if(!node)
            return 0;

        const subTotal = postorder(node.left) + postorder(node.right);
        const result = node.val - 1 + subTotal;
        moves += Math.abs(result);

        return result;

    }
};