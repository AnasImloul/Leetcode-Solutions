var averageOfLevels = function(root) {
let avg = [root.val];
let level = [];
let queue = [root];
while(queue.length>0){
    let curr = queue.shift();
    if(curr.left){
        level.push(curr.left)
    }
    if(curr.right){
        level.push(curr.right);
    }
    if(queue.length===0){
        queue.push(...level);
        avg.push(level.reduce((a,b) => a+b.val,0)/level.length);
        level = [];
    }
}
avg.pop()
return avg;
};