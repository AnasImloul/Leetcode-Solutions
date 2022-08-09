var wordBreak = function(s, wordDict) {
    const n = s.length;
    const result = [];

    const findValidSentences = (currentString = '', remainingString = s, currentIndex = 0) => {
        if(currentIndex === remainingString.length) {
            if(wordDict.includes(remainingString)) {
                result.push(`${currentString} ${remainingString}`.trim())
            }
            return result;
        }

        const newWord = remainingString.slice(0, currentIndex);
        if(wordDict.includes(newWord)) {
            const newCurrentString = `${currentString} ${newWord}`;
            const newRemainingString = remainingString.slice(currentIndex);
            findValidSentences(newCurrentString, newRemainingString, 0);
        }

        return findValidSentences(currentString, remainingString, currentIndex + 1);
    }

    return findValidSentences();
};
