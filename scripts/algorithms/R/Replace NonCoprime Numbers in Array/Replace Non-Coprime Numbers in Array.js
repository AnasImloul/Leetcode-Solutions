// Runtime: 758 ms (Top 12.50%) | Memory: 93.1 MB (Top 12.50%)
function gcd(a, b) {
    while (b > 0) {
        a %= b;
        [a, b] = [b, a];
    }
    return a;
}
function lcm(a, b) {
    return a / gcd(a, b) * b;
}

var replaceNonCoprimes = function(nums) {
    let res = new Array();
    for (let num of nums) {
        while (res.length > 0 && gcd(res.at(-1), num) > 1) {
            num = lcm(res.at(-1), num);
            res.pop();
        }
        res.push(num);
    }
    return res;
};