// Runtime: 144 ms (Top 94.59%) | Memory: 106.20 MB (Top 91.89%)

var decodeCiphertext = function(encodedText, rows) {
    const numColumns = encodedText.length / rows;
    const stringBuilder = [];
    let nextCol = 1;
    let row = 0;
    let col = 0;
    let index = 0
    while (index < encodedText.length) {
        stringBuilder.push(encodedText[index]);
        if (row === rows - 1 || col === numColumns - 1) {
            row = 0;
            col = nextCol;
            nextCol++;
        } else {
            row++;
            col++;
        }
        index = calcIndex(row, col, numColumns);
    }
    while (stringBuilder[stringBuilder.length - 1] === ' ') {
        stringBuilder.pop();
    }
    return stringBuilder.join('');
};

function calcIndex(row, col, numColumns) {
    return row * numColumns + col;
}
