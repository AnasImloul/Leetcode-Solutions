var minimumSum = function(num) {
   let numbers = []
    for(let i = 0; i<4; i++){
        numbers.push(~~num % 10)
        num /= 10
    }
    const sorted = numbers.sort((a,b) => b - a)
    return sorted[0] + sorted[1] + (10 *( sorted[2] + sorted[3]))
};
