var sumFourDivisors = function(nums) {
    let check = (num) => {
        let divs = [num]; // init the array with the number itself
        let orig = num;
        num = num >> 1; // divide in half to avoid checking too many numbers
        while (num > 0) {
            if (orig % num === 0) divs.push(num);
            num--;
            if (divs.length > 4) return 0;
        }
        if (divs.length === 4) {
            return divs.reduce((a, b) => a + b, 0);
        }
        return 0;
    }
    
    let total = 0;
    
    for (let num of nums) {
        total += check(num);
    }
    
    return total;
};
