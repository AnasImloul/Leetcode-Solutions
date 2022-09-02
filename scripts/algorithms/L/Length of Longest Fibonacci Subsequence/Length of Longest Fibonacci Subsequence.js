// Runtime: 623 ms (Top 50.00%) | Memory: 44.1 MB (Top 86.67%)
var lenLongestFibSubseq = function(arr) {
    let ans = 2;
    const set = new Set(arr);
    const len = arr.length
    for(let i = 0; i < len; i++) {
        for(let j = i + 1; j < len; j++) {
            let a = arr[i], b = arr[j], len = 2;
            while(set.has(a + b)) {
                len++;
                let temp = a + b;
                a = b;
                b = temp;
            }
            ans = Math.max(len, ans);
        }
    }
    return ans == 2 ? 0 : ans;
};