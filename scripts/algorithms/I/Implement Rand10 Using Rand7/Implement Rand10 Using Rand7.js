// Runtime: 86 ms (Top 60.46%) | Memory: 49.50 MB (Top 76.74%)

/**
 * The rand7() API is already defined for you.
 * var rand7 = function() {}
 * @return {number} a random integer in the range 1 to 7
 */
var rand10 = function() {
    while (true) {
        const num1 = rand7() - 1;
        const num2 = rand7();

        const combinedNum = num1 * 7 + num2;

        if (combinedNum <= 40) {
            return (combinedNum % 10) + 1;
        }
    }
};
