// Runtime: 584 ms (Top 70.00%) | Memory: 83.2 MB (Top 15.00%)

var findLexSmallestString = function(s, a, b) {
    const n = s.length;
    const visited = new Set();
    const queue = [];

    visited.add(s);
    queue.push(s);

    let minNum = s;

    while (queue.length > 0) {
        const currNum = queue.shift();

        if (currNum < minNum) minNum = currNum;

        const justRotate = rotate(currNum);
        const justAdd = add(currNum);

        if (!visited.has(justRotate)) {
            visited.add(justRotate);
            queue.push(justRotate);
        }

        if (!visited.has(justAdd)) {
            visited.add(justAdd);
            queue.push(justAdd);
        }
    }

    return minNum;

    function rotate(num) {
        let rotatedNum = "";
        const start = n - b;

        for (let i = 0; i < b; i++) {
            rotatedNum += num.charAt(start + i);
        }

        const restDigs = num.substring(0, n - b);
        rotatedNum += restDigs;

        return rotatedNum;
    }

    function add(num) {
        let nextNum = "";

        for (let i = 0; i < n; i++) {
            let currDig = num.charAt(i);

            if (i % 2 == 0) {
                nextNum += currDig;
            }
            else {
                let newDig = (parseInt(currDig) + a) % 10;
                nextNum += newDig;
            }
        }

        return nextNum;
    }
};