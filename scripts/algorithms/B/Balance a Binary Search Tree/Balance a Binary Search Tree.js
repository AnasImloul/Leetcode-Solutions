var balanceBST = function(root) {
let arr = [];//store sorted value in array
let InOrder = (node) => {//inorder helper to traverse and store sorted values in array
    if(!node)
        return;
    InOrder(node.left);
    arr.push(node.val);
    InOrder(node.right);
}
InOrder(root);
let BalancedFromSortedArray = (arr, start, end) => {//create Balanced tree from sorted array
    if(start>end)
        return null;
    let mid = Math.floor((start+end)/2);
    let newNode = new TreeNode(arr[mid]);
    newNode.left = BalancedFromSortedArray(arr,start,mid-1);
    newNode.right = BalancedFromSortedArray(arr,mid+1,end);
    return newNode;
}
let Balanced = BalancedFromSortedArray(arr,0,arr.length-1);
return Balanced;
};