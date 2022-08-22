// Runtime: 83 ms (Top 69.32%) | Memory: 42.8 MB (Top 62.50%)
var validSquare = function(p1, p2, p3, p4) {
    const distance = (a, b) => {
        const [aX, aY] = a;
        const [bX, bY] = b;
        return (aX - bX) ** 2 + (aY - bY) ** 2;
    };

    const set = new Set([
        distance(p1, p2),
        distance(p1, p3),
        distance(p1, p4),
        distance(p2, p3),
        distance(p2, p4),
        distance(p3, p4),
    ]);

    return !set.has(0) && set.size === 2;
};