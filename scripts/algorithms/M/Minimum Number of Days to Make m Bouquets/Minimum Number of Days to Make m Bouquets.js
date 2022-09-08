// Runtime: 139 ms (Top 86.32%) | Memory: 51.9 MB (Top 82.05%)
var minDays = function(bloomDay, m, k) {
    if (m * k > bloomDay.length) {
        return -1;
    }

    let left = 0;
    let right = 0;

    for (const day of bloomDay) {
        left = Math.min(day, left);
        right = Math.max(day, right);
    }

    let ans = right;

    while (left < right) {
        const day = Math.floor((left + right) / 2);

        let count = 0;
        let current = 0;

        for (let j = 0; j < bloomDay.length; j++) {
            if (bloomDay[j] <= day) {
                current++;
            } else {
                current = 0;
            }

            if (current === k) {
                count++;
                current = 0;
            }
        }

        if (count === m) {
            ans = Math.min(ans, day);
        }

        if (count < m) {
            left = day + 1;
        } else {
            right = day;
        }
    }

    return ans;
};