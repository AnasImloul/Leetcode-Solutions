// Runtime: 117 ms (Top 31.08%) | Memory: 46.1 MB (Top 80.63%)
var findBottomLeftValue = function(root) {
    let arr=[];
    let q=[root];
    while(q.length!==0){
        let current=q.shift();
        arr.push(current.val)
        if(current.right){
            q.push(current.right)
        }
        if(current.left){
            q.push(current.left);
        }
    }
    return arr[arr.length-1]
};