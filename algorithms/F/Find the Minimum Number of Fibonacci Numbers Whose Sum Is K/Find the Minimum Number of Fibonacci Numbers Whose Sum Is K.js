var findMinFibonacciNumbers = function(k) {
    let sequence = [1, 1], sum = sequence[0] + sequence[1];
    let i = 2;
    while (sum <= k) {
        sequence.push(sum);
        i++;
        sum = sequence[i-1]+sequence[i-2];
    }
    let j = sequence.length-1, res = 0;
    while (k) {
        if (k >= sequence[j]) k -= sequence[j], res++;
        j--;
    }
    return res;
    // Time Complexity: O(n)
    // Space Complexity: O(n)
};
