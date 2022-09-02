// Runtime: 150 ms (Top 50.00%) | Memory: 47.5 MB (Top 33.33%)
const outerTrees = (trees) => {
    trees.sort((x, y) => {
        if (x[0] == y[0]) return x[1] - y[1];
        return x[0] - y[0];
    });
    let lower = [], upper = [];
    for (const tree of trees) {
        while (lower.length >= 2 && cmp(lower[lower.length - 2], lower[lower.length - 1], tree) > 0) lower.pop();
        while (upper.length >= 2 && cmp(upper[upper.length - 2], upper[upper.length - 1], tree) < 0) upper.pop();
        lower.push(tree);
        upper.push(tree);

    }
    return [...new Set(lower.concat(upper))];
};

const cmp = (p1, p2, p3) => {
    let [x1, y1] = p1;
    let [x2, y2] = p2;
    let [x3, y3] = p3;
    return (y3 - y2) * (x2 - x1) - (y2 - y1) * (x3 - x2);
};