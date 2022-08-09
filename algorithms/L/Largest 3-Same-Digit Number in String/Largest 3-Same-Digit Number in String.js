var largestGoodInteger = function(num) {
    let maxGoodInt = '';
    for (let i = 0; i <= num.length - 3; i++) {
        if (num[i] === num[i+1] && num[i+1] === num[i+2]) {
            if (num[i] >= maxGoodInt) {
                maxGoodInt = num[i];
            }
        }
    }
    return maxGoodInt + maxGoodInt + maxGoodInt;
};
