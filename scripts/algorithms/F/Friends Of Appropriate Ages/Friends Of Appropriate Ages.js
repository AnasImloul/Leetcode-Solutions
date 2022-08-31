// Runtime: 83 ms (Top 95.24%) | Memory: 46.2 MB (Top 100.00%)
var numFriendRequests = function(ages) {
    const count = new Array(121).fill(0);

    ages.forEach((age) => count[age]++);

    let res = 0; // total friend request sent
    let tot = 0; // cumulative count of people so far

    for (let i = 0; i <= 120; i++) {

        if (i > 14 && count[i] != 0) {
            const limit = Math.floor(0.5 * i) + 7;
            const rest = tot - count[limit];

            res += (count[i] * rest); // current age group send friend request to other people who are within their limit
            res += (count[i] * (count[i] - 1)); // current age group send friend request to each other
        }

        tot += count[i];
        count[i] = tot;
    }

    return res;
};