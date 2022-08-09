var simplifiedFractions = function(n) {
    const res = [];
    const checkValid = (a, b) => {
        if(a === 1) return 1;
        let num = 2;
        while(num <= a) {
            if(b % num === 0 && a % num === 0) return num;
            num++;
        }
        return 1;
    }
    let i = 1;
    while(i / n < 1) {
        let j = i + 1;
        while(j <= n) {
            if(checkValid(i, j) < 2) {
                res.push(`${i}/${j}`); 
            }
            j++;
        }
        i++;
    }
    return res;
};
