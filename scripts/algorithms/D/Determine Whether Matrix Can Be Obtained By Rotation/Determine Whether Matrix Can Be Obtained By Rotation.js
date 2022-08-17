var findRotation = function(mat, target) {
    let width = mat[0].length;
    let height = mat.length;
    
    let normal = true;
    let rightOneTime = true;
    let rightTwoTimes = true;
    let rightThreeTimes = true;
    for (let i = 0; i < height; i++)  {
        for (let j = 0; j < width; j++) {
            // don't rotate mat
            if (mat[i][j] !== target[i][j]) {
                normal = false;
            }
            // rotate mat right 1 time
            if (mat[i][j] !== target[j][width - 1 - i]) {
                rightOneTime = false;
            }
            // rotate mat right 2 times
            if (mat[i][j] !== target[height - 1 - i][width - 1 - j]) {
                rightTwoTimes = false;
            }
            // rotate mat right 3 times
            if (mat[i][j] !== target[height - 1 - j][i]) {
                rightThreeTimes = false;
            }
        }
    }
    return normal || rightOneTime || rightTwoTimes || rightThreeTimes;
};
