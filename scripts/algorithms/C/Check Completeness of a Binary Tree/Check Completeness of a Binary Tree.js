var isCompleteTree = function(root) {
let queue = [root];
let answer = [root];
while(queue.length > 0) {
    let current = queue.shift();
    if(current) {
        queue.push(current.left);
        answer.push(current.left);
        queue.push(current.right);
        answer.push(current.right);
    }
}

console.log("queue", queue);

while(answer.length > 0 ) {
    let current = answer.shift();
    if(current === null) break;
}
console.log("answer after shifting", answer);
 let flag = true;
 for(let current of answer) {
    if(current !== null) {
        flag = false;
        break
    }
}

return flag
};