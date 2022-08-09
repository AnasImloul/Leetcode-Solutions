var minimumNumbers = function(num, k) {
    if (num === 0) return 0;
    for (let i = 1; i <= 10; i++) {
        if (k*i % 10 === num % 10 && k*i <= num) return i;
        if (k*i > num) return -1
    } return -1;
};
