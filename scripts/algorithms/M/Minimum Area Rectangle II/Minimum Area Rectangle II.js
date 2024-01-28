// Runtime: 98 ms (Top 66.67%) | Memory: 61.40 MB (Top 66.67%)

var minAreaFreeRect = function(points) {
    const diagonalMap = new Map();
    let result = Infinity;

    for (let a = 0; a < points.length - 1; a++) {
        const [x1, y1] = points[a];
        for (let b = a + 1; b < points.length; b++) {
            const [x2, y2] = points[b];
            const diagonal = calculateeDiagonal(x1, y1, x2, y2);
            const centerX = (x1 + x2) / 2;
            const centerY = (y1 + y2) / 2;
            const key = `${diagonal}_${centerX}_${centerY}`;
            const vectors = diagonalMap.get(key) ?? [];

            vectors.push({ x1, x2, y1, y2 });
            diagonalMap.set(key, vectors);
        }
    }

    for (const [key, vector] of diagonalMap) {
        if (vector.length < 2) continue;
        for (let a = 0; a < vector.length - 1; a++) {
            const vectorA = vector[a];
            for (let b = a + 1; b < vector.length; b++) {
                const vectorB = vector[b];
                const w = Math.sqrt(calculateeDiagonal(vectorA.x1, vectorA.y1, vectorB.x1, vectorB.y1));
                const h = Math.sqrt(calculateeDiagonal(vectorA.x1, vectorA.y1, vectorB.x2, vectorB.y2));

                result = Math.min(result, w * h);
            }
        }
    }
    return result === Infinity ? 0 : result;

    function calculateeDiagonal(x1, y1, x2, y2) {
        return Math.pow(x1 - x2, 2) + Math.pow(y1 - y2, 2);
    }
};
