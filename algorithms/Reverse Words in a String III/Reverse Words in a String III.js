var reverseWords = function(s) {
    // make array of the words from s
    let words = s.split(" ");
    for (let i in words) {
	    // replace words[i] with words[i] but reversed
        words.splice(i, 1, words[i].split("").reverse().join(""))
    } return words.join(" ");
};
