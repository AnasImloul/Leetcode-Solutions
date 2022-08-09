var getDistances = function(arr) {
    const result = [];
    for (let i = 0; i < arr.length; i++) {
        let sum = 0;
        for (let j = 0; j < arr.length; j++) {
            if (arr[j] === arr[i]) {
                sum += Math.abs(i - j);
            }
        }
        result[i] = sum;
    }
    return result;
};
