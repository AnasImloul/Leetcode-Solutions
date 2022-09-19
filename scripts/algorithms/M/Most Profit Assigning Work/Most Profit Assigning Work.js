// Runtime: 171 ms (Top 69.15%) | Memory: 49.2 MB (Top 90.43%)
var maxProfitAssignment = function(difficulty, profit, worker) {
    const data = [];

    for (let i = 0; i < difficulty.length; i++) {
        data.push({ difficulty: difficulty[i], profit: profit[i] });
    }

    data.sort((a, b) => a.difficulty - b.difficulty);

    let maxProfit = 0;

    for (let i = 0; i < data.length; i++) {
        data[i].profit = maxProfit = Math.max(maxProfit, data[i].profit);
    }

    // worker.sort((a, b) => a - b);

    let ans = 0;
    let min = 0;

    for (const skill of worker) {
        let left = 0; // min;
        let right = data.length - 1;

        while (left < right) {
            const mid = Math.floor((left + right + 1) / 2);

            if (data[mid].difficulty > skill) {
                right = mid - 1;
            } else {
                left = mid;
            }
        }

        if (data[left].difficulty > skill) {
            continue;
        }

        // min = left;
        ans += data[left].profit;
    }

    return ans;
};