// Runtime: 65 ms (Top 67.95%) | Memory: 48.40 MB (Top 39.74%)

/**
 * @param {number} poured
 * @param {number} query_row
 * @param {number} query_glass
 * @return {number}
 */
var champagneTower = function(poured, query_row, query_glass) {
    let glassLevels = Array(100).fill(0.0);
    glassLevels[0] = poured;

    for (let curRow = 0; curRow < query_row; curRow++) {
        let nextLevels = Array(100).fill(0.0);

        for (let curGlass = 0; curGlass <= curRow; curGlass++) {
            let overflow = Math.max(0, (glassLevels[curGlass] - 1.0) / 2.0);
            nextLevels[curGlass] += overflow;
            nextLevels[curGlass + 1] += overflow;
        }

        glassLevels = nextLevels;
    }

    return Math.min(1.0, glassLevels[query_glass]);    
};
