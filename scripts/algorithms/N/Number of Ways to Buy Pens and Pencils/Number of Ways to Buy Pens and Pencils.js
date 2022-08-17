var waysToBuyPensPencils = function(total, cost1, cost2) {
    let distinctWays = 0;
    
    for (let cnt = 0; cnt * cost1 <= total; ++cnt) {
        const remMoney = total - (cnt * cost1);
        const waysToBuyPencil = Math.floor(remMoney / cost2) + 1;
        distinctWays += waysToBuyPencil;
    }
    
    return distinctWays;
};
