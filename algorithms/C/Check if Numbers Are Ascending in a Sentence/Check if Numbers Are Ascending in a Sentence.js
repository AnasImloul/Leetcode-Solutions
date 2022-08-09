var areNumbersAscending = function(s) {
    const numbers = [];
    const arr = s.split(" ");
    for(let i of arr) {
        if(isFinite(i)) {
            if(numbers.length > 0 && numbers[numbers.length - 1] >= i) {
                return false;
            }
            numbers.push(+i);
        }
    }
    return true
};
