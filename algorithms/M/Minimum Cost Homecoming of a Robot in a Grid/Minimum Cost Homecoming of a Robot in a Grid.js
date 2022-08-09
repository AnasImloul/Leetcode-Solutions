var minCost = function(startPos, homePos, rowCosts, colCosts) {
    let totCosts = 0;

    let rowDir = startPos[0] <= homePos[0] ? 1 : -1;
    let colDir = startPos[1] <= homePos[1] ? 1 : -1;
    
    let row = startPos[0];

    while (row != homePos[0]) {
        row += rowDir;
        totCosts += rowCosts[row];
    }

    let col = startPos[1];

    while (col != homePos[1]) {
        col += colDir;
        totCosts += colCosts[col];
    }

    return totCosts;
};
