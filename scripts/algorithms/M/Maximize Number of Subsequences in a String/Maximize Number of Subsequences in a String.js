// Runtime: 366 ms (Top 17.65%) | Memory: 69.2 MB (Top 29.41%)
/**
 * @param {string} text
 * @param {string} pattern
 * @return {number}
 */
var maximumSubsequenceCount = function(text, pattern) {
    const arrText = text.split("")
    const lengthP0 = arrText.filter(x => x === pattern[0]).length
    const lengthP1 = arrText.filter(x => x === pattern[1]).length
    const [c1, c2, lengthmax] = lengthP0 <= lengthP1 ? [...pattern, lengthP1]: [pattern[1], pattern[0], lengthP0]
    let newText = lengthP0 <= lengthP1 ? [c1,...arrText]: [...arrText, c1]
    newText = lengthP0 <= lengthP1 ? newText : newText.reverse()

    let i = 0;
    let count = 0;
    let countmax = lengthmax
    while(i < newText.length) {
        if(newText[i] === c1) {
            count += countmax
        }
        if(newText[i] === c2) {
            countmax--
        }
        i++;
    }
    return count
};