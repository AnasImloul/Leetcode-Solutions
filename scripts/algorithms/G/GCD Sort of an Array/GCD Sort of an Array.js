// Runtime: 1815 ms (Top 40.00%) | Memory: 69.6 MB (Top 20.00%)
var gcdSort = function(nums) {
    // group numbers by their prime factors
    const unionFind = {};
    const find = (x) => unionFind[x] = unionFind[x] === x ? x : find(unionFind[x]);
    const union = (x, y) => unionFind[find(y)] = unionFind[find(x)];
    for (const num of nums) {
        if (!unionFind[num]) {
            unionFind[num] = num;
        }
        const primeFactors = getPrimeFactors(num);
        for (const primeFactor of primeFactors) {
            if (!unionFind[primeFactor]) {
                unionFind[primeFactor] = primeFactor;
            }
            union(primeFactor, num);
        }
    }

    // see if it's possible to swap nums to equal sorted by checking the groups
    const sortedNums = [...nums].sort((a, b) => a - b);
    return nums.every((num, i) => find(num) === find(sortedNums[i]));
};

function getPrimeFactors(n) {
    const primeFactors = new Set();
    while (n % 2 === 0) {
        primeFactors.add(2);
        n /= 2;
    }

    for (let i = 3; i * i <= n; i += 2) {
        while (n % i === 0) {
            primeFactors.add(i);
            n /= i;
        }
    }
    if (n > 1) {
        primeFactors.add(n);
    }
    return primeFactors;
}