// Runtime: 233 ms (Top 5.19%) | Memory: 47.2 MB (Top 96.75%)
var getMinimumDifference = function(root) {
    let order = inOrder(root, []);
    let diff = Math.abs(order[1] - order[0]);
    for(let i=0;i<order.length;i++) {
        for(let j=i+1;j<order.length;j++) {
            if(Math.abs(order[i] - order[j]) < diff) diff = Math.abs(order[i] - order[j])
        }
    }
    return diff;
};

const inOrder = (root, order) => {
    if(!root) return null;
    inOrder(root.left, order);
    order.push(root.val);
    inOrder(root.right, order);
    return order;
}