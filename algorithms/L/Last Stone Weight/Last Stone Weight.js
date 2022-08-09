var lastStoneWeight = function(stones) {
    let first = 0, second = 0;
    stones.sort((a,b) => a - b);
    while(stones.length > 1) {
        first = stones.pop();
        second = stones.pop();
        stones.push(first - second);
        stones.sort((a,b) => a - b);
    }
    return stones[0];
};
