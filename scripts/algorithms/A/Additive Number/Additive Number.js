// Runtime: 134 ms (Top 8.22%) | Memory: 44.9 MB (Top 12.33%)
const getNum = (str, i, j) => {
    str = str.slice(i, j);
    if(str[0] == '0' && str.length > 1) return -1000
    return Number(str);
}

var isAdditiveNumber = function(num) {
    // i = 3 say and make theory and proof that
    const len = num.length;
    for(let b = 2; b < len; b++) {
        for(let i = 0; i < b - 1; i++) {
            for(let j = i + 1; j < b; j++) {
                let v1 = getNum(num,0, i + 1);
                let v2 = getNum(num,i + 1, j + 1);
                let v3 = getNum(num,j + 1, b + 1);
                if(v1 + v2 == v3) {
                    // test hypothesis;
                    // from b start checking if string persist behaviour
                    let p = num.slice(0, b + 1);
                    while(p.length <= len) {
                        let sum = v2 + v3;
                        p += sum;
                        v2 = v3;
                        v3 = sum;
                    }
                    if(p.slice(0, len) == num) {
                        return true;
                    }
                }
            }
        }
    }
    return false;
};