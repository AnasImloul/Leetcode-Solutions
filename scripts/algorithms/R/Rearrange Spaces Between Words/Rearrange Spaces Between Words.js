// Runtime: 77 ms (Top 77.31%) | Memory: 42.2 MB (Top 47.52%)
var reorderSpaces = function(text) {
    let arr = text.split(" ");
    let totalSpace = arr.length-1;
    arr = arr.filter(w => w !== '');
    let spaceBetween = arr.length > 1 ?
                    Math.floor(totalSpace / (arr.length-1)) : 0;
    let spaceLeftOver = arr.length > 1 ?
                    totalSpace % (arr.length-1) : totalSpace;
    return (arr.join(" ".repeat(spaceBetween)) + " ".repeat(spaceLeftOver));
    // Time Complexity: O(n)
    // Space Complexity: O(n)
};