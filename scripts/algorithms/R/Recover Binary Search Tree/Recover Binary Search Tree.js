// Runtime: 269 ms (Top 19.02%) | Memory: 52.1 MB (Top 64.55%)
var recoverTree = function(root) {
    const arr = [];
    const traverse = (r = root) => {
        if(!r) return;
        traverse(r.left);
        arr.push(r.val);
        traverse(r.right);
    }
    traverse();

    arr.sort((a, b) => a - b);
    let k = 0;
    const recover = (r = root) => {
        if(!r) return null;
        recover(r.left);
        r.val = arr[k++];
        recover(r.right);
    }
    recover();
    return root;
};