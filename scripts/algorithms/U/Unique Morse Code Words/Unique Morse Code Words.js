// Runtime: 79 ms (Top 79.05%) | Memory: 43.6 MB (Top 56.48%)
var uniqueMorseRepresentations = function(words) {
    var morse = [".-","-...","-.-.","-..",".","..-.",
                  "--.","....","..",".---",
                  "-.-",".-..","--","-.","---",".--.",
                  "--.-",".-.","...","-","..-","...-",
                  ".--","-..-","-.--","--.."];

    var transformations = new Set();

    for (let word of words) {
        var trans = "";
        for (let letter of word) {
            var index = letter.charCodeAt(0) - 97;
            trans += morse[index];
        }

        transformations.add(trans);
    }

    return transformations.size;
};