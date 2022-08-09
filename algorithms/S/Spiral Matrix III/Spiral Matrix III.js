var spiralMatrixIII = function(rows, cols, rStart, cStart) {
    let output = [];
    let r = rStart, c = cStart;
    let right = true, down = false, left = false, up = false;
    let steps = 1, maxSteps = 2;

    while (output.length !== (rows * cols)) {
        if (r >= 0 && c >= 0 && r < rows && c < cols) output.push([r, c]);
        if (right) {
            if (steps + 1 > maxSteps) {
                steps = 2, r++;
                right = false, down = true;
            } else c++, steps++;
        }
        else if (down) {
            if (steps + 1 > maxSteps) {
                steps = 2, c--;
                down = false, left = true;
                maxSteps++;
            } else r++, steps++;
        }
        else if (left) {
            if (steps + 1 > maxSteps) {
                steps = 2, r--;
                left = false, up = true;
            } else c--, steps++;
        }
        else if (up) {
            if (steps + 1 > maxSteps) {
                steps = 2, c++;
                up = false, right = true;
                maxSteps++;
            } else r--, steps++;
        }
    }

    return output;
};
