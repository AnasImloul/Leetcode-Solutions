// Runtime: 260 ms (Top 25.49%) | Memory: 50.2 MB (Top 45.10%)
var addOperators = function(num, target) {
    let res = [];

    let i = 0;

    const helper = (idx, sum, prev, path) => {
        if(idx >= num.length) {
            if(sum === target) {
                res.push(path);
            }
            return null;
        }

        for(let j = idx; j < num.length; j++) {

            if(j !== idx && num[idx] === "0")
                break;

            let n = Number(num.slice(idx, j+1));

            if(idx === 0) {
                helper(j + 1, sum + n, sum + n, path + n);
            } else {
                helper(j + 1, sum + n, n, path + "+" + n);

                helper(j + 1, sum - n, 0 - n, path + "-" + n);

                helper(j + 1, sum - prev + (prev * n), prev * n, path + "*" + n);
            }
        }

    }

    helper(i, 0, 0, "");

    return res;
};