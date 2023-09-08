// Runtime: 63 ms (Top 100.0%) | Memory: 45.35 MB (Top 75.0%)

var ambiguousCoordinates = function(S) {
    let ans = [], xPoss
    const process = (str, xy) => {
        if (xy)
            for (let x of xPoss)
                ans.push(`(${x}, ${str})`)
        else xPoss.push(str)
    }
    const parse = (str, xy) => {
        if (str.length === 1 || str[0] !== "0")
            process(str, xy)
        if (str.length > 1 && str[str.length-1] !== "0")
            process(str.slice(0,1) + "." + str.slice(1), xy)
        if (str.length > 2 && str[0] !== "0" && str[str.length-1] !== "0")
            for (let i = 2; i < str.length; i++)
                process(str.slice(0,i) + "." + str.slice(i), xy)
    }
    for (let i = 2; i < S.length - 1; i++) {
        let strs = [S.slice(1,i), S.slice(i, S.length - 1)]
        xPoss = []
        for (let j = 0; j < 2; j++)
            if (xPoss.length || !j) parse(strs[j], j)
    }
    return ans
};