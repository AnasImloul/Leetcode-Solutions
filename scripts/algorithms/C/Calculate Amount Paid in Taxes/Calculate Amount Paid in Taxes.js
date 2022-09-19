// Runtime: 116 ms (Top 23.96%) | Memory: 44.6 MB (Top 21.88%)
var calculateTax = function(brackets, income) {
    return brackets.reduce(([tax, prev], [upper, percent]) => {
        let curr = Math.min(income, upper - prev);
        tax += curr * (percent / 100);

        income -= curr;
        if (income <= 0) brackets.length = 0;

        return [tax, upper];
    }, [0, 0])[0];
};