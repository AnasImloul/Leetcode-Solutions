// Runtime: 78 ms (Top 95.83%) | Memory: 41.9 MB (Top 85.42%)
var waysToBuyPensPencils = function(total, cost1, cost2) {
    let distinctWays = 0;

    for (let cnt = 0; cnt * cost1 <= total; ++cnt) {
        const remMoney = total - (cnt * cost1);
        const waysToBuyPencil = Math.floor(remMoney / cost2) + 1;
        distinctWays += waysToBuyPencil;
    }

    return distinctWays;
};