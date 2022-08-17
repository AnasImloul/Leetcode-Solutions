 var minOperations = function(boxes) {
    
    const ans = new Array(boxes.length).fill(0);

    let ballsLeft = 0, ballsRight = 0;
    let movesLeft = 0, movesRight = 0;

    const len = boxes.length - 1;
    
    for(let i = 0; i <= len; i++) {
       
       movesLeft += ballsLeft;
       movesRight += ballsRight;
       ans[i] += movesLeft;
       ans[len - i] += movesRight;
       ballsLeft += +boxes[i];
       ballsRight += +boxes[len - i];
    }

    return ans;
};
